/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** triggers.c
*/

#include "system.h"
#include "rpg.h"
#include "entity.h"

void draw_trigger(trigger_t *trigger, sfRenderWindow *window)
{
    if (trigger->activity_img[ACTIVE_TRIGGER] && trigger->activate)
        draw_img(trigger->activity_img[ACTIVE_TRIGGER], window);
    if (trigger->activity_img[NOT_ACTIVE_TRIGGER] && !trigger->activate)
        draw_img(trigger->activity_img[NOT_ACTIVE_TRIGGER], window);
}

void update_triggers(list_t *pnjs, map_t *map, player_t *player)
{
    map->interact = NULL;
    map->to_interact_with = NULL;
    map->selected_trigger = NULL;
    if (check_trigger_pnjs(pnjs, map, player)
    || check_trigger_map(map, player)) {
        change_text(map->action_lbl, ACTION_TXT);
        return;
    }
    change_text(map->action_lbl, "");
}

void destroy_trigger(trigger_t *trigger)
{
    free(trigger);
}