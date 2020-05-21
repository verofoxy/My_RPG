/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** check_trigger.c
*/

#include "system.h"
#include "rpg.h"
#include "entity.h"

bool check_trigger_pnjs(list_t *pnjs, map_t *map, player_t *player)
{
    pnj_t *pnj_tmp = NULL;

    while (pnjs) {
        pnj_tmp = get_entity_value(pnjs->element);
        if (sfFloatRect_intersects(
                &pnj_tmp->trigger->area,
                &player->collision_mask,
                NULL
        ) && pnj_tmp->trigger->activate) {
            map->interact = pnj_tmp->trigger->callback;
            map->to_interact_with = pnj_tmp;
            map->selected_trigger = pnj_tmp->trigger;
            return true;
        }
        pnjs = pnjs->next;
    }
    return false;
}

bool check_trigger_map(map_t *map, player_t *player)
{
    int i = 0;

    if (!map->triggers)
        return false;
    for (i = 0; map->triggers[i]; i++)
        if (sfFloatRect_intersects(
                &map->triggers[i]->area,
                &player->collision_mask,
                NULL
        ) && map->triggers[i]->activate) {
            map->interact = map->triggers[i]->callback;
            map->to_interact_with = map;
            map->selected_trigger = map->triggers[i];
            return true;
        }
    return false;
}