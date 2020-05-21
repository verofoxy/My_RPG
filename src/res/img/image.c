/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** image.c
*/

#include <stdlib.h>
#include "image.h"
#include "rpg.h"

img_t *create_image(char const *filepath, sfIntRect *area)
{
    img_t *n_img = malloc(sizeof(img_t));
    sfTexture *txt = sfTexture_createFromFile(filepath, area);
    sfSprite *sprite = sfSprite_create();

    CHECK_MALLOC(txt)
    CHECK_MALLOC(sprite)
    CHECK_MALLOC(n_img)
    sfSprite_setTexture(sprite, txt, sfTrue);
    n_img->sprite = sprite;
    n_img->txt = txt;
    return n_img;
}

void draw_img(img_t *img, sfRenderWindow *window)
{
    if (img)
        sfRenderWindow_drawSprite(window, img->sprite, NULL);
}

void image_destroy(img_t *img)
{
    sfSprite_destroy(img->sprite);
    sfTexture_destroy(img->txt);
    free(img);
}