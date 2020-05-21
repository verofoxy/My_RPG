/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_game.c
*/

#include "rpg.h"
#include "system.h"
#include "window.h"
#include "scene.h"
#include "sound.h"

void destroy_game(game_sys_t *sys)
{
    list_destroy(&sys->sounds, destroy_sound);
    sfClock_destroy(sys->clock);
    window_destroy(sys->window);
    destroy_dialog(sys->dialog_box);
    free(sys);
}