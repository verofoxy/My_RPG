/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** entity_combat.c
*/

#include "rpg.h"
#include "entity.h"
#include "fight.h"

void attack_entity(entity_t *src_attack, entity_t *dest_attack)
{
    switch (src_attack->type) {
        case PLAYER_ENT:
            attack_player(
                src_attack->entity_value.player,
                dest_attack->entity_value.enemy
            );
            break;
        case ENEMY_ENT:
            attack_enemy(
                src_attack->entity_value.enemy,
                dest_attack->entity_value.player
            );
            break;
        case PNJ_ENT:
            break;
    }
}

bool check_death_entity(entity_t *entity)
{
    switch (entity->type) {
        case PLAYER_ENT:
            return check_death_player(entity->entity_value.player);
        case ENEMY_ENT:
            return check_death_enemy(entity->entity_value.enemy);
        case PNJ_ENT:
            break;
    }
    return false;
}