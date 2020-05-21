/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** sound_handle.c
*/


#include "rpg.h"
#include "list.h"
#include "scene.h"
#include "sound.h"

void *load_sound(json_object_t *obj, list_t **list)
{
    snd_t *sound = create_sound(
        json_object_get_str(obj, "path"),
        100,
        !json_object_get_bool(obj, "is_sfx"),
        json_object_get_bool(obj, "is_sfx")
    );
    list_push(list, sound, m_strdup(json_object_get_str(obj, "type_sound")));
    return (void *)1;
}

list_t *set_sound(void)
{
    list_t *list = NULL;
    json_value_t *obj = get_json_from_file(PATH_SOUND_J, true);
    json_array_t obj_array;

    CHECK_INVALID_PTR(obj)
    obj_array = get_array_value(obj);
    if (!obj_array.arr)
        return NULL;
    for (int i = 0; i < obj_array.length; i++)
        load_sound(json_array_get_object(&obj_array, i), &list);
    destroy_json_value(obj);
    return (list);
}

void sound_handle(game_sys_t *sys, int type_sound, float volume, int mode)
{
    char *flag[] = TAG_SOUND;

    switch (mode) {
        case PLAY:
            play_sound(list_get_from_tag(sys->sounds, flag[type_sound]));
            break;
        case STOP:
            stop_sound(list_get_from_tag(sys->sounds, flag[type_sound]));
            break;
        case PAUSE:
            pause_sound(list_get_from_tag(sys->sounds, flag[type_sound]));
            break;
        case RESET:
            reset_all_sound(sys->sounds);
            break;
        case VOLUME:
            set_volume_sound(sys->sounds, volume);
            break;
    }
}