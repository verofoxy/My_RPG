/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menus
*/

#ifndef MENUS_H_
#define MENUS_H_

#define PAUSE_CONFIG    "./assets/menus/pause.min.json"
#define MAIN_CONFIG     "./assets/menus/main.min.json"
#define SETTINGS_CONFIG "./assets/menus/settings.min.json"
#define CREDITS_CONFIG  "./assets/menus/credits.min.json"
#define HTP_CONFIG      "./assets/menus/htp.min.json"
#define LOSE_CONFIG     "assets/menus/lose.min.json"

#define LOGO            "./assets/img/logo.png"
#define MAIN_BKG        "./assets/menus/wallpaper.png"

#define NEW_SCENE_BTN   0
#define INTERNAL_BTN    1
#define ATTACK_BTN      2
#define RUN_AWAY_BTN    3
#define ITEMS_BTN       4
#define SET_SFX_BTN     5
#define SET_MUSIC_BTN   6
#define BACK_BTN        7

//////////////NECESSARIES INCLUDES/////////
#include <SFML/Graphics.h>
#include "json_parser.h"
#include "image.h"
#include "text.h"
#include "system.h"
#include <stdbool.h>

//////////////STRUCTS//////////////////

typedef int type_action_t;

typedef struct button {
    label_t *name;
    sfVector2f pos;
    bool hover;
    type_action_t action;
    img_t *states[2];
    sfIntRect rect;
    sfIntRect focus_mask;
    void (*callback)();
    int arg;
} btn_t;

typedef struct action_btn {
    char const *key;
    int (*callback)();
} action_btn_t;

//////////////FUNCTIONS BUTTONS///////////////
btn_t *init_btn(json_object_t *obj);
void disp_btn(btn_t *btn, sfRenderWindow *window);
void del_btn(btn_t *btn);

////////////FUNCTIONS MENUS ////////////////////
btn_t **create_menu(char const *filepath);
void disp_menu(btn_t **menu, sfRenderWindow *window);
void draw_menu(game_sys_t *sys, btn_t **menu, img_t *logo, img_t *background);
void check_state_buttons(btn_t **menu, sfVector2i pos);
void del_menu(btn_t **menu);

int handle_btn_new_scene(btn_t *btn, json_object_t *obj);
int handle_btn_attack(btn_t *btn, json_object_t *obj);
int handle_btn_items(btn_t *btn, json_object_t *obj);
int handle_btn_run_away(btn_t *btn, json_object_t *obj);
int handle_btn_internal_scene(btn_t *this, json_object_t *obj);
int handle_btn_settings_sfx(btn_t *this, json_object_t *obj);
int handle_btn_settings_music(btn_t *this, json_object_t *obj);
int handle_btn_back(btn_t *this, json_object_t *obj);

void attack_player_callback(game_sys_t *sys);
void run_away(game_sys_t *sys);

static const action_btn_t BTN_ACTIONS[] = {
    {"NEW_SCENE", handle_btn_new_scene},
    {"ATTACK", handle_btn_attack},
    {"ITEMS", handle_btn_items},
    {"RUN_AWAY", handle_btn_run_away},
    {"INTERNAL", handle_btn_internal_scene},
    {"SET_STATE_MUSIC", handle_btn_settings_music},
    {"SET_STATE_SFX", handle_btn_settings_sfx},
    {"RETURN_SCENE", handle_btn_back}
};
static const int NB_ACTIONS_BTN = sizeof(BTN_ACTIONS) / sizeof(action_btn_t);

void handle_btn_pressed(game_sys_t *sys, btn_t **menu);

#endif /* !MENUS_H_ */
