/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** apply_camera.c
*/

#include "rpg.h"
#include "entity.h"
#include "camera.h"

void apply_camera_map(camera_t *camera, map_t *map)
{
    int i = 0;

    sfVector2f new_pos = {
            map->pos.x + camera->camera.left,
            map->pos.y + camera->camera.top
    };
    set_img_position(map->img, new_pos);
    for (i = 0; map->triggers[i]; i++) {
        if (map->triggers[i]->trigger_type != FIGHT &&
        map->triggers[i]->trigger_type != GET)
            continue;
        new_pos.x = map->triggers[i]->area.left + (float) camera->camera.left;
        new_pos.y = map->triggers[i]->area.top + (float) camera->camera.top;
        set_img_position(
        map->triggers[i]->activity_img[ACTIVE_TRIGGER], new_pos);
        set_img_position(
        map->triggers[i]->activity_img[NOT_ACTIVE_TRIGGER], new_pos);
    }
}

void apply_camera(camera_t *camera, entity_t *ent)
{
    sfVector2f draw_pos;
    sfVector2f new_pos;

    switch (ent->type) {
        case PLAYER_ENT:
            draw_pos = ent->entity_value.player->pos;
            new_pos.x = draw_pos.x + (float) camera->camera.left;
            new_pos.y = draw_pos.y + (float) camera->camera.top;
            set_img_position(ent->entity_value.player->sheet, new_pos);
            break;
        case PNJ_ENT:
            draw_pos = ent->entity_value.pnj->pos;
            new_pos.x = draw_pos.x + (float) camera->camera.left;
            new_pos.y = draw_pos.y + (float) camera->camera.top;
            set_img_position(ent->entity_value.pnj->sheet, new_pos);
        case ENEMY_ENT : break;
    }
}