/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** run_boss_fight.c
*/

#include "scene.h"
#include "rpg.h"
#include "entity.h"
#include "fight.h"

void run_boss_fight(game_sys_t *sys, map_t *map, trigger_t *trigger)
{
    bool run_away = false;
    player_t *player = ((player_t *) GET_PLAYER(sys->entities));

    add_entity(sys->entities, get_boss(map->loc), ENEMY_BRANCH);
    change_scene(sys, FIGHT_SCENE);
    run_fight(sys, &run_away);
    if (sys->actual_scene == WORLD_SCENE && run_away == false) {
        change_position(
            GET_PLAYER(sys->entities),
            (sfVector2f) {
                trigger->area.left + trigger->area.width / 2 -
                player->collision_mask.width / 2,
                trigger->area.top + trigger->area.height / 2 -
                player->collision_mask.height / 2
            }
        );
        trigger->activate = false;
    }
}