/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_pnj.c
*/

#include "rpg.h"
#include "entity.h"
#include "animation.h"

void destroy_pnj(pnj_t *pnj)
{
    int i = 0;

    for (i = 0; pnj->dialogs[i]; i++)
        free(pnj->dialogs[i]);
    free(pnj->dialogs);
    image_destroy(pnj->sheet);
    list_destroy(&pnj->animations, animation_destroy);
    free(pnj->name);
    free(pnj);
}