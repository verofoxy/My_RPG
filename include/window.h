/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** window.h
*/

#ifndef MUL_MY_DEFENDER_2019_WINDOW_H
#define MUL_MY_DEFENDER_2019_WINDOW_H

#include <SFML/Graphics.h>

sfRenderWindow* create_window(unsigned int width, unsigned int height, char
const *title, unsigned int defaultFramerate);
int is_open_window(sfRenderWindow* window);
void window_destroy(sfRenderWindow *window);
void close_window(sfRenderWindow *window);
void display_window(sfRenderWindow *window);
void change_framerate(sfRenderWindow *window, int framerate);
void change_dimension(sfRenderWindow *window, int width, int height);
void clear_window(sfRenderWindow *window, sfColor color);

#endif
