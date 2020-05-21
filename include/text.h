/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** text.h
*/

#ifndef MUL_MY_DEFENDER_2019_TEXT_H
#define MUL_MY_DEFENDER_2019_TEXT_H

#include <SFML/Graphics.h>

typedef struct {
    char *mall;
    sfText *txt;
    sfFont *font;
} label_t;

label_t *create_label(char const *fontpath, unsigned int size, char const *txt,
sfColor color);
void draw_lbl(label_t *lbl, sfRenderWindow *window);
void label_destroy(label_t *lbl);

void change_text(label_t *lbl, char *new_txt);
void set_pos_label(label_t *lbl, sfVector2f pos);
void change_color(label_t *lbl, sfColor color);
#endif
