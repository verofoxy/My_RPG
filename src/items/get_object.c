/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** get_object.c
*/

#include "scene.h"
#include "system.h"
#include "rpg.h"
#include "image.h"
#include "entity.h"

void get_object(game_sys_t *sys, map_t *map, trigger_t *trigger)
{
    item_t *target = NULL;

    (void) map;
    target = L_TAG(sys->map->items, trigger->name_item);
    if (!target)
        return;
    list_push(&((player_t *) GET_PLAYER(sys->entities))->bag, target,
    target->name);
    trigger->activate = false;
    change_text(sys->map->action_lbl, "");
    change_scene(sys, ITEM_SCENE);
    item_scene(sys, target);
}