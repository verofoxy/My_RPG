/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** collisions.c
*/

#include "rpg.h"
#include "camera.h"
#include "entity.h"

bool collide_with_walls_pnj(pnj_t *pnj, map_t *map, float dt)
{
    int i = 0;
    float nx = pnj->pos.x + (pnj->move.x * (float) MOVE_SPEED * dt);
    float ny = pnj->pos.y + (pnj->move.y * (float) MOVE_SPEED * dt);
    sfFloatRect test_rect = {
        nx + 10,
        ny + 20,
        pnj->collision_mask.width,
        pnj->collision_mask.height
    };

    for (i = 0; i < map->nb_masks; i++) {
        if (sfFloatRect_intersects(&map->collision_masks[i], &test_rect, NULL))
            return true;
    }
    return false;
}

bool collide_with_walls(player_t *player, map_t *map, float dt)
{
    int i = 0;
    float nx = player->pos.x + (player->move.x * (float) MOVE_SPEED * dt);
    float ny = player->pos.y + (player->move.y * (float) MOVE_SPEED * dt);
    sfFloatRect test_rect = {nx + 10, ny + 20,
            player->collision_mask.width,
            player->collision_mask.height
    };

    for (i = 0; i < map->nb_masks; i++) {
        if (sfFloatRect_intersects(&map->collision_masks[i], &test_rect, NULL))
            return true;
    }
    return false;
}

bool collide_with_pnjs(
    player_t *player,
    map_t *map,
    list_t **entities,
    float dt
)
{
    int i = 0;
    pnj_t *tmp = NULL;
    float nx = player->pos.x + (player->move.x * (float) MOVE_SPEED * dt);
    float ny = player->pos.y + (player->move.y * (float) MOVE_SPEED * dt);
    sfFloatRect test_rect = {
    nx + 10,
    ny + 20,
        player->collision_mask.width,
        player->collision_mask.height
    };

    for (i = 0; i < map->nb_ids; i++) {
        tmp = get_entity_value(get_entity_from_id(entities, map->pnj_ids[i]));
        if (sfFloatRect_intersects(&tmp->collision_mask, &test_rect, NULL))
            return true;
    }
    return false;
}

bool collide_with_player(
    pnj_t *pnj,
    list_t **entities,
    float dt
)
{
    player_t *tmp = get_entity_value(get_entity_from_id(entities, 0.0));
    float nx = pnj->pos.x + (pnj->move.x * (float) MOVE_SPEED * dt);
    float ny = pnj->pos.y + (pnj->move.y * (float) MOVE_SPEED * dt);
    sfFloatRect test_rect = {
        nx, ny,
        pnj->collision_mask.width,
        pnj->collision_mask.height
    };

    if (sfFloatRect_intersects(&tmp->collision_mask, &test_rect, NULL))
        return true;
    return false;
}

sfFloatRect *get_masks(json_array_t *j_array)
{
    sfFloatRect *masks = malloc(sizeof(sfFloatRect) * j_array->length);
    json_object_t *tmp = NULL;
    int i = 0;

    CHECK_MALLOC(masks)
    for (i = 0; i < j_array->length; i++) {
        tmp = json_array_get_object(j_array, i);
        masks[i].left = (float) json_object_get_int(tmp, "x");
        masks[i].top = (float) json_object_get_int(tmp, "y");
        masks[i].width = (float) json_object_get_int(tmp, "w");
        masks[i].height = (float) json_object_get_int(tmp, "h");
    }
    return masks;
}