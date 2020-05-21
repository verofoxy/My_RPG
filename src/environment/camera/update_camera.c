/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** update_camera.c
*/

#include "rpg.h"
#include "entity.h"
#include "camera.h"

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void update_camera(camera_t *camera, player_t *player)
{
    int x = -player->pos.x + ((int) (W_SCREEN / 2));
    int y = -player->pos.y + ((int) (H_SCREEN / 2));

    x = min(0, x);
    y = min(0, y);
    x = max(-(camera->map_width - W_SCREEN), x);
    y = max(-(camera->map_height - H_SCREEN), y);
    camera->camera.left = x;
    camera->camera.top = y;
}