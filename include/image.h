/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** image.h
*/

#ifndef MUL_MY_DEFENDER_2019_IMAGE_H
#define MUL_MY_DEFENDER_2019_IMAGE_H

#include <SFML/Graphics.h>

typedef struct image {
    sfTexture *txt;
    sfSprite *sprite;
} img_t;

img_t *create_image(char const *filepath, sfIntRect *area);
void image_destroy(img_t *img);

void draw_img(img_t *img, sfRenderWindow *window);
void move_img(img_t *img, sfVector2f off);
void set_img_rect(img_t *img, sfIntRect new_rect);
void set_img_position(img_t *img, sfVector2f new_pos);
sfVector2f get_img_pos(img_t *img);

#endif