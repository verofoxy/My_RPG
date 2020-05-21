/*
** EPITECH PROJECT, 2020
** ghjk
** File description:
** ghjik
*/

#include "rpg.h"
#include "entity.h"
#include "fight.h"

player_t *lvl_up(player_t *player)
{
    player->exp.lvl += 1;
    player->attck += 5;
    player->health.max_health += 5;
    player->exp.max_xp += 5;
    return player;
}

player_t *up_xp(player_t *player, int bounty_xp)
{
    player->exp.curr_xp += bounty_xp;
    if (player->exp.curr_xp >= player->exp.max_xp) {
        player->exp.curr_xp = player->exp.curr_xp - player->exp.max_xp;
        lvl_up(player);
    }
    return player;
}

enemy_t *attack_player(player_t *src, enemy_t *dest)
{
    list_t *items = src->bag;
    item_t *tmp = NULL;

    dest->health.current_health -= src->attck;
    while (items) {
        tmp = items->element;
        if (tmp->itm_type == ATTACK_ITEM)
            dest->health.current_health -= tmp->bonus_attack;
        items = items->next;
    }
    if (dest->health.current_health <= 0)
        dest->health.current_health = 0;
    return dest;
}

player_t *get_heart(player_t *player, int add_heart)
{
    player->health.current_health += add_heart ;
    if (player->health.current_health >= player->health.max_health)
        player->health.current_health = player->health.max_health;
    return player;
}

bool check_death_player(player_t *player)
{
    return player->health.current_health <= 0;
}