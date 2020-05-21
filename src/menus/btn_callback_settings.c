/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_callback_settings.c
*/

#include "rpg.h"
#include "menus.h"
#include "scene.h"
#include "sound.h"

int handle_btn_settings_music(btn_t *this, json_object_t *obj)
{
    (void) obj;
    this->callback = set_music;
    this->arg = 0;
    this->action = SET_MUSIC_BTN;
    return EXEC_SUCCESS;
}

int handle_btn_settings_sfx(btn_t *this, json_object_t *obj)
{
    (void) obj;
    this->callback = set_sfx;
    this->arg = 0;
    this->action = SET_SFX_BTN;
    return EXEC_SUCCESS;
}

int handle_btn_back(btn_t *this, json_object_t *obj)
{
    (void) obj;
    this->callback = change_scene;
    this->arg = 0;
    this->action = BACK_BTN;
    return EXEC_SUCCESS;
}