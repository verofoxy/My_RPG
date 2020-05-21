/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_btns_callback.c
*/

#include "rpg.h"
#include "scene.h"
#include "entity.h"
#include "fight.h"
#include "particle.h"

void attack_player_event(game_sys_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
    }
}

void attack_player_callback(game_sys_t *sys)
{
    float time = 0;

    while (is_open_window(sys->window)) {
        attack_player_event(sys);
        if (time <= 0.15)
            particle_effect(800, FREQUENCY(200), PATH_PART_FIRE, sys->window);
        else
            break;
        display_window(sys->window);
        time += sfTime_asSeconds(sfClock_getElapsedTime(sys->clock));
        sfClock_restart(sys->clock);
    }
    attack_entity(
            GET_PLAYER_ENT(sys->entities),
            GET_ENEMY_ENT(sys->entities)
    );
    if (sys->actual_scene != EXIT_SCENE)
        change_scene(sys, FIGHT_SCENE);
}

void run_away(game_sys_t *sys)
{
    change_scene(sys, WORLD_SCENE);
}