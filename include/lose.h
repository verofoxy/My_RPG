/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** lose.h
*/

#ifndef MUL_MY_RPG_2019_LOSE_H
#define MUL_MY_RPG_2019_LOSE_H

#define GAMEOVER_IMG    "assets/scenes/gameover/gameover.png"

void lose_event(game_sys_t *sys, btn_t **menu);
void draw_lose(
    game_sys_t *sys,
    btn_t **menu,
    img_t *gameover_text,
    img_t *background
);

#endif