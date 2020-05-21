/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_pnj.c
*/

#include "rpg.h"
#include "json_parser.h"
#include "image.h"
#include "entity.h"
#include "animation.h"

char **load_dialogs(json_array_t arr)
{
    char **dialogs = NULL;
    int i = 0;

    if (!arr.arr || arr.length <= 0)
        return NULL;
    dialogs = malloc(sizeof(char *) * (arr.length + 1));
    CHECK_MALLOC(dialogs)
    dialogs[arr.length] = NULL;
    for (i = 0; i < arr.length; i++)
        dialogs[i] = m_strdup(json_array_get_str(&arr, i));
    return dialogs;
}

static void pnj_get_animations(pnj_t *pnj, json_object_t *obj)
{
    pnj->curr_animation =
    m_strdup(json_object_get_str(obj, "curr_animation"));
    pnj->animations = load_animations(obj, "animations");
    set_img_rect(pnj->sheet,
    ((animation_t *) L_TAG(pnj->animations, pnj->curr_animation))
    ->frames[0]);
}

static pnj_move_t get_ia_parameters(json_object_t *obj, char const *key)
{
    pnj_move_t move;
    json_object_t *move_obj = json_object_get_object(obj, key);

    move.delay = (float) json_object_get_int(move_obj, "delay") / 1000;
    move.curr_time = (float) json_object_get_int(move_obj, "curr");
    if (!m_strcmp(json_object_get_str(move_obj, "direction"), "vertical"))
        move.type = VERTICAL;
    else
        move.type = HORIZONTAL;
    move.reverse = false;
    return move;
}

pnj_t *create_pnj_from_json(json_value_t *pnj_obj)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    json_object_t *obj = NULL;

    CHECK_MALLOC(pnj)
    CHECK_INVALID_PTR(pnj_obj)
    pnj->move = (sfVector2f) {0, 0};
    obj = get_json_object(pnj_obj);
    pnj->name = m_strdup(json_object_get_str(obj, "name"));
    pnj->pos = get_position_from_object(obj, "position");
    pnj->sheet = create_image(json_object_get_str(obj, "sheet"),
    NULL);
    pnj->collision_mask = get_mask_from_obj(obj, "mask", pnj->pos);
    pnj_get_animations(pnj, obj);
    pnj->ia = get_ia_parameters(obj, "ia");
    pnj->trigger = create_trigger(json_object_get_object(obj, "trigger"));
    pnj->dialogs = load_dialogs(json_object_get_array(obj, "dialogs"));
    return pnj;
}