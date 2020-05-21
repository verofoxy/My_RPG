/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** interact_keyboard.c
*/

#include "scene.h"
#include "rpg.h"
#include "my.h"

void key_interaction_e(game_sys_t *sys)
{
    if (sys->paused)
        return;
    if (!sys->map->interact)
        return;
    sys->map->interact(
            sys, sys->map->to_interact_with,
            sys->map->selected_trigger
    );
}

void key_skip_echap(game_sys_t *sys)
{
    if (sys->paused)
        return;
    pause_menu(sys, WORLD_SCENE);
}