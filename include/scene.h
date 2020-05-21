/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** scene.h
*/

#ifndef MUL_MY_DEFENDER_2019_SCENE_H
#define MUL_MY_DEFENDER_2019_SCENE_H

#include "system.h"
#include "quest.h"

#define EXIT_SCENE              0
#define MENU_SCENE              1
#define WORLD_SCENE             2
#define FIGHT_SCENE             3
#define DIALOG_SCENE            4
#define FADE_SCENE              5
#define ITEM_SCENE              6
#define CREDITS_SCENE           7
#define HELP_SCENE              8
#define SETTINGS_SCENE          9
#define PAUSE_SCENE             10
#define ENEMY_ATTACK_SCENE      11
#define PLAYER_ATTACK_SCENE     12
#define LOSE_SCENE              13
#define END_SCENE               14
#define INTRO_CAVE_SCENE        15
#define INTRO_FOREST_SCENE      16

typedef struct scene {
    int id;
    void (*callback)();
} scene_t;

void world_scene(game_sys_t *sys);
void run_game(game_sys_t *sys);
void dialog_scene(game_sys_t *sys, pnj_t *pnj, trigger_t *trigger);
void fade_in(game_sys_t *sys);
void fade_out(game_sys_t *sys, int new_scene);
void item_scene(game_sys_t *sys, item_t *new_item);
void main_menu_scene(game_sys_t *sys);
void pause_menu(game_sys_t *sys, int actual_scene);
void htp_scene(game_sys_t *sys);
void credits_scene(game_sys_t *sys);
void settings_menu(game_sys_t *sys, int actual_scene);
void attack_enemy_scene(game_sys_t *sys, img_t *background);
void attack_player_scene(game_sys_t *sys, img_t *background);
void run_fight(game_sys_t *sys, bool *run_away);
void lose_scene(game_sys_t * sys);
void end_scene(game_sys_t *sys);
void intro_cave_scene(game_sys_t *sys);
void intro_forest_scene(game_sys_t *sys);

static const scene_t ALL_SCENES[] = {
        {EXIT_SCENE, NULL},
        {MENU_SCENE, main_menu_scene},
        {HELP_SCENE, htp_scene},
        {CREDITS_SCENE, credits_scene},
        {WORLD_SCENE, run_game},
        {FIGHT_SCENE, run_fight},
        {SETTINGS_SCENE, settings_menu},
        {LOSE_SCENE, lose_scene},
        {END_SCENE, end_scene},
        {INTRO_CAVE_SCENE, intro_cave_scene},
        {INTRO_FOREST_SCENE, intro_forest_scene}
};
static const int NB_SCENES = sizeof(ALL_SCENES) / sizeof(scene_t);

#endif