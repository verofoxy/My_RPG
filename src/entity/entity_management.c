/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** entity_management.c
*/

#include "rpg.h"
#include "entity.h"

entity_u create_entity_from_type(entity_type_e type_entity, void *value)
{
    entity_u entity_value;

    entity_value.enemy = NULL;
    switch (type_entity) {
        case PLAYER_ENT:
            entity_value.player = value;
            break;
        case ENEMY_ENT:
            entity_value.enemy = value;
            break;
        case PNJ_ENT:
            entity_value.pnj = value;
            break;
        default: break;
    }
    return entity_value;
}

void *get_entity_value(entity_t *entity)
{
    switch (entity->type) {
        case PLAYER_ENT:
            return entity->entity_value.player;
        case PNJ_ENT:
            return entity->entity_value.pnj;
        case ENEMY_ENT:
            return entity->entity_value.enemy;
    }
    return NULL;
}

void destroy_entity(entity_t *entity)
{
    free(entity);
}