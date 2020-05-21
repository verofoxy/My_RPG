/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_keyboard.c
*/

#include "system.h"
#include "rpg.h"
#include "entity.h"
#include "animation.h"

void key_up_z(game_sys_t *sys)
{
    move(GET_PLAYER_ENT(sys->entities), (sfVector2f) {0, -1});
    change_animation(GET_PLAYER_ENT(sys->entities), "up", "idle_up");
}

void key_left_q(game_sys_t *sys)
{
    move(GET_PLAYER_ENT(sys->entities), (sfVector2f) {-1, 0});
    change_animation(GET_PLAYER_ENT(sys->entities), "left", "idle_left");
}

void key_right_d(game_sys_t *sys)
{
    move(GET_PLAYER_ENT(sys->entities), (sfVector2f) {1, 0});
    change_animation(GET_PLAYER_ENT(sys->entities), "right", "idle_right");
}

void key_down_s(game_sys_t *sys)
{
    move(GET_PLAYER_ENT(sys->entities), (sfVector2f) {0, 1});
    change_animation(GET_PLAYER_ENT(sys->entities), "down", "idle_down");
}
