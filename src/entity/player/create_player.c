/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_player.c
*/

#include "rpg.h"
#include "camera.h"
#include "image.h"
#include "entity.h"
#include "animation.h"
#include "quest.h"

void load_entity_specifications(json_object_t *obj, player_t *player)
{
    player->move = (sfVector2f) {0, 0};
    player->name = m_strdup(json_object_get_str(obj, "name"));
    player->attck = json_object_get_int(obj, "attack_point");
    player->pos = get_position_from_object(obj, "position");
    player->health = get_health_from_object(obj, "health");
    player->animations = load_animations(obj, "animations");
    player->bag = NULL;
    player->quests = create_quest();
}

player_t *create_player_from_json(char const *filepath)
{
    player_t *player = malloc(sizeof(player_t));
    json_value_t *player_obj_value = get_json_from_file(filepath, true);
    json_object_t *obj = NULL;

    CHECK_MALLOC(player)
    CHECK_INVALID_PTR(player_obj_value)
    obj = get_json_object(player_obj_value);
    load_entity_specifications(obj, player);
    player->exp = get_exp_from_object(obj, "exp");
    player->sheet = create_image(json_object_get_str(obj, "sheet"),
    NULL);
    player->collision_mask = get_mask_from_obj(obj, "mask", player->pos);
    player->curr_animation =
    m_strdup(json_object_get_str(obj, "curr_animation"));
    set_img_rect(player->sheet,
    ((animation_t *) L_TAG(player->animations, player->curr_animation))
    ->frames[0]);
    destroy_json_value(player_obj_value);
    return player;
}