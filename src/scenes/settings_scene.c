/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** settings_scene.c
*/

#include "rpg.h"
#include "window.h"
#include "scene.h"
#include "menus.h"
#include "quest.h"

void settings_menu_event(game_sys_t *sys, btn_t **settings_menu, int act_scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            change_scene(sys, act_scene);
        if (event.type == sfEvtMouseButtonPressed)
            handle_btn_pressed(sys, settings_menu);
    }
}

void draw_settings_menu(game_sys_t *sys, btn_t **settings_menu,
sfRectangleShape *shader)
{
    sfRenderWindow_drawRectangleShape(sys->window, shader, NULL);
    disp_menu(settings_menu, sys->window);
    display_window(sys->window);
}

void settings_menu(game_sys_t *sys, int actual_scene)
{
    btn_t **settings_menu = create_menu(SETTINGS_CONFIG);
    sfRectangleShape *shader = init_shader();

    change_scene(sys, SETTINGS_SCENE);
    while (is_open_window(sys->window) && sys->actual_scene == SETTINGS_SCENE) {
        check_state_buttons(settings_menu,
        sfMouse_getPositionRenderWindow(sys->window));
        settings_menu_event(sys, settings_menu, actual_scene);
        draw_settings_menu(sys, settings_menu, shader);
        sfClock_restart(sys->clock);
    }
    sfClock_restart(sys->clock);
    del_menu(settings_menu);
}