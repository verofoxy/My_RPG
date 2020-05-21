/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** window.c
*/

#include <stdlib.h>
#include "window.h"

sfRenderWindow* create_window(unsigned int width, unsigned int height, char
const *title, unsigned int defaultFramerate)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow* window = sfRenderWindow_create(
        mode,
        title,
        sfClose,
        NULL);
    sfRenderWindow_setFramerateLimit(window, defaultFramerate);
    return (window);
}

int is_open_window(sfRenderWindow* window)
{
    return sfRenderWindow_isOpen(window);
}

void window_destroy(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}

void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
