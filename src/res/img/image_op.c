/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** image_op.c
*/

#include "image.h"

void move_img(img_t *img, sfVector2f off)
{
    sfSprite_move(img->sprite, off);
}

void set_img_rect(img_t *img, sfIntRect new_rect)
{
    sfSprite_setTextureRect(img->sprite, new_rect);
}

sfVector2f get_img_pos(img_t *img)
{
    return sfSprite_getPosition(img->sprite);
}

void set_img_position(img_t *img, sfVector2f new_pos)
{
    if (img)
        sfSprite_setPosition(img->sprite, new_pos);
}