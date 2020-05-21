/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_trigger.c
*/

#include "system.h"
#include "rpg.h"
#include "entity.h"

void add_activity_imgs_trigger(trigger_t *trigger, json_object_t *obj)
{
    trigger->activity_img[NOT_ACTIVE_TRIGGER] =
    !json_object_get_str(obj, "not_activated_img") ? NULL :
    create_image(json_object_get_str(obj, "not_activated_img"), NULL);
    trigger->activity_img[ACTIVE_TRIGGER] =
    !json_object_get_str(obj, "activated_img") ? NULL :
    create_image(json_object_get_str(obj, "activated_img"), NULL);
    set_img_position(
    trigger->activity_img[ACTIVE_TRIGGER],
    (sfVector2f) {trigger->area.left, trigger->area.top}
    );
    set_img_position(
    trigger->activity_img[NOT_ACTIVE_TRIGGER],
    (sfVector2f) {trigger->area.left, trigger->area.top}
    );
}

trigger_t *create_trigger(json_object_t *data)
{
    trigger_t *trigger = malloc(sizeof(trigger_t));
    char const *target_key = json_object_get_str(data, "action");
    int i = 0;
    json_object_t *area_obj = json_object_get_object(data, "area");

    CHECK_MALLOC(trigger)
    trigger->area.left = (float) json_object_get_int(area_obj, "x");
    trigger->area.top = (float) json_object_get_int(area_obj, "y");
    trigger->area.width = (float) json_object_get_int(area_obj, "w");
    trigger->area.height = (float) json_object_get_int(area_obj, "h");
    add_activity_imgs_trigger(trigger, data);
    for (i = 0; i < NB_TRIGGER_ACTIONS; i++)
        if (m_strcmp(target_key, TRIGGER_ACTIONS[i].key) == 0) {
            TRIGGER_ACTIONS[i].callback(trigger, data);
            break;
        }
    if (i == NB_TRIGGER_ACTIONS)
        return NULL;
    return trigger;
}