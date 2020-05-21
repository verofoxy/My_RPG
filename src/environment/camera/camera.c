/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** environment.c
*/

#include "rpg.h"
#include "entity.h"
#include "camera.h"

camera_t *init_camera(unsigned int width, unsigned int height)
{
    camera_t *camera = malloc(sizeof(camera_t));

    CHECK_MALLOC(camera);
    camera->map_width = width;
    camera->map_height = height;
    return camera;
}

void apply_cam_on_entities(camera_t *camera, list_t **entities)
{
    int i = 0;
    list_t *tmp = NULL;

    for (i = 0; i < NB_BRANCH; i++) {
        tmp = entities[i];
        while (tmp) {
            apply_camera(camera, tmp->element);
            tmp = tmp->next;
        }
    }
}

void camera_destroy(camera_t *camera)
{
    free(camera);
}