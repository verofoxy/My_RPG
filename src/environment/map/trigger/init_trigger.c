/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_trigger.c
*/

#include "fight.h"
#include "scene.h"
#include "rpg.h"
#include "entity.h"

void init_trigger_get_item(trigger_t *trigger, json_object_t *obj)
{
    trigger->trigger_type = GET;
    trigger->callback = get_object;
    trigger->activate = true;
    trigger->name_item = m_strdup(json_object_get_str(obj, "name"));
}

void init_trigger_fight(trigger_t *trigger)
{
    trigger->trigger_type = FIGHT;
    trigger->callback = run_boss_fight;
    trigger->activate = true;
}

void init_trigger_discuss(trigger_t *trigger)
{
    trigger->trigger_type = DISCUSS;
    trigger->callback = dialog_scene;
    trigger->activate = true;
}

void init_trigger_spawn(trigger_t *trigger, json_object_t *obj)
{
    trigger->trigger_type = GO;
    trigger->callback = change_world;
    trigger->activate = true;
    trigger->spawn = get_position_from_object(obj, "position");
    if (m_strcmp(json_object_get_str(obj, "new_map"), "FOREST") == 0)
        trigger->new_map = FOREST;
    else if (m_strcmp(json_object_get_str(obj, "new_map"), "CAVE") == 0)
        trigger->new_map = CAVE;
    else
        trigger->new_map = CITY;
}

