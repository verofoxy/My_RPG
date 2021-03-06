/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_scene
*/

#include "rpg.h"
#include "image.h"
#include "window.h"
#include "entity.h"
#include "scene.h"
#include "menus.h"

void credits_event(game_sys_t *sys, btn_t **menu)
{    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed)
            handle_btn_pressed(sys, menu);
    }
}

void credits_scene(game_sys_t *sys)
{
    img_t *background = create_image(MAIN_BKG, NULL);
    btn_t **credits_menu = create_menu(CREDITS_CONFIG);
    img_t *logo = create_image(LOGO, NULL);

    set_img_position(logo, (sfVector2f) {0, -90});
    while (is_open_window(sys->window) && sys->actual_scene == CREDITS_SCENE) {
        check_state_buttons(credits_menu,
        sfMouse_getPositionRenderWindow(sys->window));
        credits_event(sys, credits_menu);
        if (sys->actual_scene == EXIT_SCENE)
            break;
        draw_menu(sys, credits_menu, logo, background);
        sfClock_restart(sys->clock);
    }
    image_destroy(logo);
    image_destroy(background);
    del_menu(credits_menu);
}