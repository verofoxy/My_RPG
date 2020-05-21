/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019_yann
** File description:
** entity_test.c
*/

#include "system.h"
#include "rpg.h"
#include "entity.h"

entity_t *create_entity(entity_type_e type, void *entity_value)
{
    entity_t *entity = malloc(sizeof(entity_t));

    CHECK_MALLOC(entity)
    entity->type = type;
    entity->entity_value = create_entity_from_type(entity->type, entity_value);
    return entity;
}

void draw_entity(entity_t *ent, sfRenderWindow *window)
{
    switch (ent->type) {
        case PLAYER_ENT:
            return draw_player(ent->entity_value.player, window);
        case ENEMY_ENT:
            return draw_enemy(ent->entity_value.enemy, window);
        case PNJ_ENT:
            return draw_pnj(ent->entity_value.pnj, window);
    }
}

void draw_entities(list_t **entities, sfRenderWindow *window)
{
    int i = 0;
    list_t *tmp = NULL;

    for (i = 0; i < NB_BRANCH; i++) {
        tmp = entities[i];
        while (tmp) {
            draw_entity(tmp->element, window);
            tmp = tmp->next;
        }
    }
}

void update_entity(entity_t *ent, map_t *map, list_t **entities, game_sys_t *s)
{
    float dt = sfTime_asSeconds(sfClock_getElapsedTime(s->clock));

    switch (ent->type) {
        case PLAYER_ENT:
            update_player(ent->entity_value.player, map, entities, s);
            break;
        case PNJ_ENT:
            update_pnj(ent->entity_value.pnj, entities, map, dt);
            break;
        case ENEMY_ENT: break;
    }
}

void update_entities(
    map_t *map,
    list_t **entities,
    game_sys_t *sys
)
{
    int i = 0;
    list_t *tmp = NULL;

    for (i = 0; i < NB_BRANCH; i++) {
        tmp = entities[i];
        while (tmp) {
            update_entity(tmp->element, map, entities, sys);
            tmp = tmp->next;
        }
    }
}