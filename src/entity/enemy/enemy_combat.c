/*
** EPITECH PROJECT, 2020
** fghjk
** File description:
** fghjklm
*/

#include "rpg.h"
#include "entity.h"

player_t *attack_enemy(enemy_t *src, player_t *dest)
{
    dest->health.current_health -= src->attck;
    if (dest->health.current_health <= 0)
        dest->health.current_health = 0;
    return dest;
}

bool check_death_enemy(enemy_t *enemy)
{
    return enemy->health.current_health <= 0;
}