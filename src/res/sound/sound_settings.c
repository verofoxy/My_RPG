/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** sound_settings.c
*/

#include "rpg.h"
#include "sound.h"
#include "system.h"

void set_sfx(game_sys_t *sys)
{
    sys->settings.sfx_allowed = !sys->settings.sfx_allowed;
    if (!sys->settings.sfx_allowed) {
        reset_all_sound(sys->sounds);
        return;
    }
}

void set_music(game_sys_t *sys)
{
    sys->settings.music_allowed = !sys->settings.music_allowed;
    if (!sys->settings.music_allowed) {
        reset_all_sound(sys->sounds);
        return;
    }
    sound_handle(sys, ENV, 50, PLAY);
    sound_handle(sys, ENV, 50, VOLUME);
}