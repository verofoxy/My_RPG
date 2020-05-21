/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** sound_op.c
*/

#include "sound.h"

void play_sound(snd_t *snd)
{
    sfSound_play(snd->sound);
}

void stop_sound(snd_t *snd)
{
    sfSound_stop(snd->sound);
}

void pause_sound(snd_t *snd)
{
    sfSound_pause(snd->sound);
}

void volume_sound(snd_t *snd, float volume)
{
    sfSound_setVolume(snd->sound, volume);
}