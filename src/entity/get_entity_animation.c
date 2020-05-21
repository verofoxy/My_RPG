/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** player_animation.c
*/

#include "rpg.h"
#include "json_parser.h"
#include "entity.h"
#include "animation.h"

void move(entity_t *ent, sfVector2f off)
{
    switch (ent->type) {
        case PLAYER_ENT:
            ent->entity_value.player->move = off;
            break;
        case PNJ_ENT:
            ent->entity_value.pnj->move = off;
            break;
        case ENEMY_ENT: break;
    }
}

sfIntRect *load_frames_anim(json_array_t *arr_frames)
{
    sfIntRect *frames = malloc(sizeof(sfIntRect) * arr_frames->length);
    json_object_t *tmp = NULL;
    int i = 0;

    CHECK_MALLOC(frames);
    for (i = 0; i < arr_frames->length; i++) {
        tmp = json_array_get_object(arr_frames, i);
        frames[i].left = json_object_get_int(tmp, "x");
        frames[i].top = json_object_get_int(tmp, "y");
        frames[i].width = json_object_get_int(tmp, "w");
        frames[i].height = json_object_get_int(tmp, "h");
    }
    return frames;
}

int add_animation_from_json(list_t **animations, json_array_t arr, int index)
{
    json_object_t *info_anim = json_array_get_object(&arr, index);
    json_array_t arr_frames = json_object_get_array(info_anim, "frames");
    char *name = NULL;
    animation_t *anim = NULL;

    if (!info_anim)
        return EXEC_FAIL;
    name = m_strdup(json_object_get_str(info_anim, "name"));
    anim = create_animation(arr_frames.length,
    load_frames_anim(&arr_frames),
    TO_SEC(json_object_get_int(info_anim, "total_time")),
    json_object_get_bool(info_anim, "loop"));
    set_switch_to(anim,
    m_strdup(json_object_get_str(info_anim, "switch_to")));
    list_push(animations, anim, name);
    return EXEC_SUCCESS;
}

list_t *load_animations(json_object_t *obj, char const *key)
{
    list_t *animations = NULL;
    json_array_t arr_anim = json_object_get_array(obj, key);
    int i = 0;

    for (i = 0; i < arr_anim.length; i++)
        CHECK_CORRUPTED(add_animation_from_json(&animations, arr_anim, i))
    return animations;
}