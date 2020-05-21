/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fade_scene.c
*/

#include "rpg.h"
#include "image.h"
#include "window.h"
#include "camera.h"
#include "entity.h"
#include "scene.h"
#include "camera.h"

void fade_event(game_sys_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed)
            change_scene(sys, WORLD_SCENE);
    }
}

void draw_fade(game_sys_t *sys, sfRectangleShape *shader)
{
    clear_window(sys->window, sfBlack);
    draw_map(sys->map, sys->window);
    draw_entities(sys->entities, sys->window);
    sfRenderWindow_drawRectangleShape(sys->window, shader, NULL);
    display_window(sys->window);
}

void update_fade(game_sys_t *sys)
{
    update_camera(sys->camera, GET_PLAYER(sys->entities));
    apply_camera_map(sys->camera, sys->map);
    apply_cam_on_entities(sys->camera, sys->entities);
}

void fade_in(game_sys_t *sys)
{
    float time = 0;
    sfRectangleShape *shader = init_shader();
    change_scene(sys, FADE_SCENE);

    while (is_open_window(sys->window) && sys->actual_scene == FADE_SCENE) {
        fade_event(sys);
        draw_fade(sys, shader);
        update_fade_in(shader, sys->clock, &time);
        update_fade(sys);
        sfClock_restart(sys->clock);
        if (time >= FADE_SPEED)
            change_scene(sys, WORLD_SCENE);
    }
    sfRectangleShape_destroy(shader);
}

void fade_out(game_sys_t *sys, int new_scene)
{
    float time = 0;
    sfRectangleShape *shader = init_shader();
    change_scene(sys, FADE_SCENE);

    while (is_open_window(sys->window) && sys->actual_scene == FADE_SCENE) {
        fade_event(sys);
        draw_fade(sys, shader);
        update_fade_out(shader, sys->clock, &time);
        update_fade(sys);
        sfClock_restart(sys->clock);
        if (time >= FADE_SPEED)
            change_scene(sys, new_scene);
    }
    sfRectangleShape_destroy(shader);
}