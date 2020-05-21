/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** dialog_scene.c
*/

#include "rpg.h"
#include "window.h"
#include "entity.h"
#include "scene.h"

void check_dialog_interaction(game_sys_t *sys, sfKeyCode code)
{
    if (code == sfKeyEscape)
        change_scene(sys, WORLD_SCENE);
    if (code == sfKeyE) {
        if (sys->dialog_box->curr_time < DIALOG_SPEED) {
            sys->dialog_box->curr_time = DIALOG_SPEED;
            return;
        }
        change_scene(sys, WORLD_SCENE);
    }
}

void dialog_event(game_sys_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
        if (event.type == sfEvtKeyPressed)
            check_dialog_interaction(sys, event.key.code);
    }
}

sfRectangleShape *init_shader(void)
{
    sfRectangleShape *shader = sfRectangleShape_create();

    sfRectangleShape_setSize(shader, (sfVector2f) {800, 600});
    sfRectangleShape_setFillColor(
            shader,
            sfColor_fromRGBA(50, 50, 50, 100)
    );
    sfRectangleShape_setOutlineThickness(shader, 0);
    return shader;
}

void draw_dialog_scene(game_sys_t *sys, sfRectangleShape *shader)
{
    int i = 0;

    clear_window(sys->window, sfColor_fromRGBA(200, 25, 255, 0));
    draw_map(sys->map, sys->window);
    for (i = 0; sys->map->triggers[i]; i++)
        draw_trigger(sys->map->triggers[i], sys->window);
    draw_entities(sys->entities, sys->window);
    sfRenderWindow_drawRectangleShape(sys->window, shader, NULL);
    draw_dialog(sys->dialog_box, sys->window);
    display_window(sys->window);
}

void dialog_scene(game_sys_t *sys, pnj_t *pnj, trigger_t *trigger)
{
    sfRectangleShape *shader = init_shader();

    (void) trigger;
    change_scene(sys, DIALOG_SCENE);
    if (get_random_dialog(sys->dialog_box, pnj) == EXEC_FAIL)
        change_scene(sys, WORLD_SCENE);
    sys->dialog_box->curr_time = 0;
    sys->dialog_box->curr_index = 0;
    while (is_open_window(sys->window) && sys->actual_scene == DIALOG_SCENE) {
        dialog_event(sys);
        draw_dialog_scene(sys, shader);
        update_dialog(sys->dialog_box, sys->clock);
        sfClock_restart(sys->clock);
    }
    sfRectangleShape_destroy(shader);
    change_scene(sys, WORLD_SCENE);
    sfClock_restart(sys->clock);
}