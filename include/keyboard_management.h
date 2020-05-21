/*
** EPITECH PROJECT, 2020
** erthtgh
** File description:
** contain all prototypes
*/

#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H

#include "system.h"

typedef struct {
    sfKeyCode code;
    void (*callback) ();
}keyboard_t;

void key_up_z(game_sys_t *sys);
void key_left_q(game_sys_t *sys);
void key_right_d(game_sys_t *sys);
void key_down_s(game_sys_t *sys);
void key_interaction_e(game_sys_t *sys);
void key_skip_echap(game_sys_t *sys);
void get_key_pressed(sfKeyCode code, game_sys_t *sys);

static const keyboard_t KEY_PRESSED[] = {
    {sfKeyZ, &key_up_z},
    {sfKeyQ, &key_left_q},
    {sfKeyS, &key_down_s},
    {sfKeyD, &key_right_d},
    {sfKeyE, &key_interaction_e},
    {sfKeyEscape, &key_skip_echap}
};
static const int nbr_keys = sizeof(KEY_PRESSED) / sizeof(keyboard_t);
#endif
