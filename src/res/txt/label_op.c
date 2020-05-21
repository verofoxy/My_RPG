/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** label_op.c
*/

#include <stdlib.h>
#include "text.h"
#include "my.h"

void change_text(label_t *label, char *new_text)
{
    if (!new_text)
        return;
    free(label->mall);
    label->mall = m_strdup(new_text);
    sfText_setString(label->txt, label->mall);
}

void set_pos_label(label_t *lbl, sfVector2f pos)
{
    sfText_setPosition(lbl->txt, pos);
}

void change_color(label_t *lbl, sfColor color)
{
    sfText_setColor(lbl->txt, color);
}