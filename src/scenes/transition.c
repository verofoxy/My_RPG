/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** transition.c
*/

#include "rpg.h"
#include "image.h"
#include "scene.h"

void update_fade_in(sfRectangleShape *shader, sfClock *clock, float *time)
{
    int alpha = 0;

    *time += sfTime_asSeconds(sfClock_getElapsedTime(clock));
    alpha = (int) (*time * FADE_MAX / FADE_SPEED);
    if (alpha > FADE_MAX)
        alpha -= (alpha - FADE_MAX) + 1;
    sfRectangleShape_setFillColor(shader, sfColor_fromRGBA(0, 0, 0, alpha));
}

void update_fade_out(sfRectangleShape *shader, sfClock *clock, float *time)
{
    int alpha = 0;

    *time += sfTime_asSeconds(sfClock_getElapsedTime(clock));
    alpha = (int) (*time * FADE_MAX / FADE_SPEED);
    if (alpha > FADE_MAX)
        alpha -= (alpha - FADE_MAX) + 1;
    sfRectangleShape_setFillColor(
        shader,
        sfColor_fromRGBA(0, 0, 0, FADE_MAX - alpha)
    );
}