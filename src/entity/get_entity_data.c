/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** get_player_data.c
*/

#include "rpg.h"
#include "json_parser.h"
#include "entity.h"
#include "animation.h"

exp_t get_exp_from_object(json_object_t *obj, char const *key)
{
    exp_t exp;
    json_object_t *exp_obj = json_object_get_object(obj, key);

    if (!exp_obj)
        return (exp_t) {0, 15, 1};
    exp.curr_xp = json_object_get_int(exp_obj, "curr_xp");
    exp.max_xp = json_object_get_int(exp_obj, "max_xp");
    exp.lvl = json_object_get_int(exp_obj, "lvl");
    return exp;
}

sfFloatRect get_mask_from_obj(json_object_t *obj, char const *key,
sfVector2f pos)
{
    sfFloatRect mask = {.left = pos.x, .top = pos.y};
    json_object_t *size_obj = json_object_get_object(obj, key);

    if (!size_obj) {
        mask.width = 48;
        mask.height = 72;
    } else {
        mask.width =  (float) json_object_get_int(size_obj, "w");
        mask.height =  (float) json_object_get_int(size_obj, "h");
    }
    return mask;
}

sfVector2f get_position_from_object(json_object_t *obj, char const *key)
{
    sfVector2f pos;
    json_object_t *pos_obj = json_object_get_object(obj, key);

    if (!pos_obj)
        return (sfVector2f) {800, 600};
    pos.x = (float) json_object_get_int(pos_obj, "x");
    pos.y = (float) json_object_get_int(pos_obj, "y");
    return pos;
}

sfIntRect get_int_rect_from_object(json_object_t *obj, char const *key)
{
    json_object_t *rect_info = json_object_get_object(obj, key);
    sfIntRect rect;

    if (!rect_info)
        return (sfIntRect) {0, 0, 0, 0};
    rect.left = json_object_get_int(rect_info, "x");
    rect.top = json_object_get_int(rect_info, "y");
    rect.width = json_object_get_int(rect_info, "w");
    rect.height = json_object_get_int(rect_info, "h");
    return rect;
}

health_t get_health_from_object(json_object_t *obj, char const *key)
{
    health_t health;
    json_object_t *health_obj = json_object_get_object(obj, key);

    if (!health_obj)
        return (health_t) {100, 100};
    health.current_health = json_object_get_int(health_obj, "curr_health");
    health.max_health = json_object_get_int(health_obj, "max_health");
    return health;
}
