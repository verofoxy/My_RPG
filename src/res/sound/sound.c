/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** sound.c
*/

#include <stdlib.h>
#include "sound.h"
#include "rpg.h"

snd_t *create_sound(char const *filepath, float volume, bool loop, bool sfx)
{
    snd_t *snd = malloc(sizeof(snd_t));

    CHECK_MALLOC(snd)
    snd->buffer = sfSoundBuffer_createFromFile(filepath);
    snd->sound = sfSound_create();
    snd->is_sfx = sfx;
    sfSound_setBuffer(snd->sound, snd->buffer);
    sfSound_setLoop(snd->sound, loop);
    sfSound_setVolume(snd->sound, volume);
    return snd;
}

void destroy_sound(snd_t *snd)
{
    sfSound_destroy(snd->sound);
    sfSoundBuffer_destroy(snd->buffer);
    free(snd);
}

void reset_all_sound(list_t *sound)
{
    while (sound) {
        stop_sound((snd_t *)sound->element);
        sound = sound->next;
    }
}

void set_volume_sound(list_t *sound, float volume)
{
    while (sound) {
        volume_sound((snd_t *)sound->element, volume);
        sound = sound->next;
    }
}