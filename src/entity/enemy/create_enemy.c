/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_enemy.c
*/

#include "rpg.h"
#include "entity.h"
#include "animation.h"

sfVector2f get_size_canvas(json_object_t *obj, char const *key)
{
    sfVector2f size;
    json_object_t *size_obj = json_object_get_object(obj, key);

    size.x = (float) json_object_get_int(size_obj, "w");
    size.y = (float) json_object_get_int(size_obj, "h");
    return size;
}

enemy_t *create_enemy_from_json(json_value_t *j_value)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    json_object_t *obj = NULL;

    CHECK_MALLOC(enemy)
    CHECK_INVALID_PTR(j_value)
    obj = get_json_object(j_value);
    enemy->name = m_strdup(json_object_get_str(obj, "name"));
    enemy->rect = get_size_canvas(obj, "size");
    enemy->attck = json_object_get_int(obj, "attack_point");
    enemy->sheet = create_image(json_object_get_str(obj, "sheet"),
    NULL);
    enemy->curr_animation =
    m_strdup(json_object_get_str(obj, "curr_animation"));
    enemy->animations = load_animations(obj, "animations");
    set_img_rect(enemy->sheet,
    ((animation_t *) L_TAG(enemy->animations, enemy->curr_animation))
    ->frames[0]);
    set_img_position(enemy->sheet, get_position_from_object(obj, "position"));
    enemy->health = get_health_from_object(obj, "health");
    return enemy;
}