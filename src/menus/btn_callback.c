/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_callback.c
*/

#include "rpg.h"
#include "menus.h"
#include "scene.h"

int handle_btn_new_scene(btn_t *this, json_object_t *obj)
{
    this->callback = change_scene;
    this->arg = json_object_get_int(obj, "new_scene");
    this->action = NEW_SCENE_BTN;
    return EXEC_SUCCESS;
}

int handle_btn_internal_scene(btn_t *this, json_object_t *obj)
{
    this->callback = get_scene(json_object_get_int(obj, "new_scene"));
    this->arg = 0;
    this->action = INTERNAL_BTN;
    return EXEC_SUCCESS;
}

int handle_btn_attack(btn_t *this, json_object_t *obj)
{
    (void) obj;
    this->callback = attack_player_callback;
    this->arg = 0;
    this->action = ATTACK_BTN;
    return EXEC_SUCCESS;
}

int handle_btn_items(btn_t *this, json_object_t *obj)
{
    (void) obj;
    this->callback = NULL;
    this->arg = 0;
    this->action = ITEMS_BTN;
    return EXEC_SUCCESS;
}

int handle_btn_run_away(btn_t *this, json_object_t *obj)
{
    (void) obj;
    this->callback = run_away;
    this->arg = 0;
    this->action = RUN_AWAY_BTN;
    return EXEC_SUCCESS;
}