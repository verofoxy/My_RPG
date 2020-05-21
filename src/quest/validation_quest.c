/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** validation_quest.c
*/

#include "rpg.h"
#include "entity.h"
#include "quest.h"
#include "json_parser.h"

int valid_quest(quest_t *quest, player_t *player, location_e e)
{
    if (quest->activate && sfFloatRect_contains\
    (&player->collision_mask, quest->pos.x, quest->pos.y) && quest->loc == e) {
        end_quest(quest);
        return (EXEC_SUCCESS);
    }
    return (EXEC_FAIL);
}

void check_validation_quests(player_t *player, location_e e)
{
    int i = 0;

    for (i = 0; player->quests[i]; i++)
        valid_quest(player->quests[i], player, e);
}