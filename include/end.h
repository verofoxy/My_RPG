/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** end.h
*/

#ifndef MUL_MY_RPG_2019_END_H
#define MUL_MY_RPG_2019_END_H

#define IMG_END_SCENE "assets/scenes/end_game/game_finish.png"
#define END_SCENE_JSON "assets/menus/end.min.json"

void check_end(game_sys_t *sys, quest_t **quest);
void end_event(game_sys_t *sys, btn_t **menu);
void draw_end(game_sys_t *sys, btn_t **menu, img_t *background);
#endif
