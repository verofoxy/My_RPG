/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** scene.c
*/

#include "rpg.h"
#include "scene.h"

void change_scene(game_sys_t *sys, int new_scene)
{
    sys->actual_scene = new_scene;
}

void (*get_scene(int id))(game_sys_t *)
{
    int i = 0;

    for (i = 0; i < NB_SCENES; i++)
        if (ALL_SCENES[i].id == id)
            return ALL_SCENES[i].callback;
    return NULL;
}