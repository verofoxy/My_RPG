/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** monster_spawn.c
*/

#include "system.h"
#include "rpg.h"
#include "entity.h"

bool spawn_monster(game_sys_t *sys)
{
    static float walk = 0;
    static float time = 0.1f;

    if (sys->map->loc == CITY
    || (((player_t *) GET_PLAYER(sys->entities))->move.x == 0
    && ((player_t *) GET_PLAYER(sys->entities))->move.y == 0))
        return false;
    walk += (float) (rand() % 30) * time;
    time += sfTime_asSeconds(sfClock_getElapsedTime(sys->clock));
    if (walk < 4500)
        return false;
    walk = 0;
    time = 0.1f;
    add_entity(sys->entities, get_random_enemy(sys->map->loc), ENEMY_BRANCH);
    return true;
}