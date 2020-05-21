/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** window_op.c
*/

#include "window.h"

void change_dimension(sfRenderWindow *window, int width, int height)
{
    sfRenderWindow_setSize(window, (sfVector2u) {width, height});
}

void change_framerate(sfRenderWindow *window, int framerate)
{
    sfRenderWindow_setFramerateLimit(window, framerate);
}

void clear_window(sfRenderWindow *window, sfColor color)
{
    sfRenderWindow_clear(window, color);
}