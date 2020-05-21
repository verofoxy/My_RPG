/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** label.c
*/

#include <stdlib.h>
#include "text.h"
#include "rpg.h"

label_t *create_label(char const *fontpath, unsigned int size, char const *txt,
sfColor color)
{
    label_t *lbl = malloc(sizeof(label_t));

    CHECK_MALLOC(lbl);
    lbl->txt = sfText_create();
    lbl->mall = m_strdup(txt);
    lbl->font = sfFont_createFromFile(fontpath);
    if (!lbl->font)
        return NULL;
    sfText_setString(lbl->txt, lbl->mall);
    sfText_setFont(lbl->txt, lbl->font);
    sfText_setColor(lbl->txt, color);
    sfText_setCharacterSize(lbl->txt, size);
    return lbl;
}

void draw_lbl(label_t *lbl, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, lbl->txt, NULL);
}

void label_destroy(label_t *lbl)
{
    free(lbl->mall);
    sfText_destroy(lbl->txt);
    sfFont_destroy(lbl->font);
    free(lbl);
}