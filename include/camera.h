/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** environment.h
*/

#ifndef MUL_MY_RPG_2019_CAMERA_H
#define MUL_MY_RPG_2019_CAMERA_H

#include <SFML/Graphics.h>
#include "image.h"
#include "entity.h"

static const int W_SCREEN = 800;
static const int H_SCREEN = 600;

typedef struct camera
{
    unsigned int map_width;
    unsigned int map_height;
    sfIntRect camera;
} camera_t;

camera_t *init_camera(unsigned int width, unsigned int height);
void camera_destroy(camera_t *camera);
void apply_camera(camera_t *camera, entity_t *ent);
void apply_camera_map(camera_t *camera, map_t *map);
void update_camera(camera_t *camera, player_t *target);
void apply_cam_on_entities(camera_t *camera, list_t **entities);

#endif