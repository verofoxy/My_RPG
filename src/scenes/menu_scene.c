/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_scene
*/

#include "sound.h"
#include "rpg.h"
#include "image.h"
#include "window.h"
#include "entity.h"
#include "scene.h"
#include "menus.h"

void handle_btn_pressed(game_sys_t *sys, btn_t **menu)
{
    int i = 0;
    sfVector2i pos_click = sfMouse_getPositionRenderWindow(sys->window);

    for (i = 0; menu[i]; i++) {
        if (sfIntRect_contains(
                &menu[i]->focus_mask,
                pos_click.x,
                pos_click.y
            )) {
            if (!menu[i]->callback)
                break;
            SFX_ACTIVED(sound_handle(sys, CLICK, 30, PLAY));
            (menu[i]->action == NEW_SCENE_BTN)
            ? menu[i]->callback(sys, menu[i]->arg)
            : menu[i]->callback(sys, sys->actual_scene);
        }
    }
}

void menu_event(game_sys_t *sys, btn_t **menu)
{
    sfEvent event;

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

void draw_menu(game_sys_t *sys, btn_t **menu, img_t *logo, img_t *background)
{
    clear_window(sys->window, sfBlack);
    draw_img(background, sys->window);
    draw_img(logo, sys->window);
    disp_menu(menu, sys->window);
    display_window(sys->window);
}

void main_menu_scene(game_sys_t *sys)
{
    img_t *background = create_image(MAIN_BKG, NULL);
    btn_t **main_menu = create_menu(MAIN_CONFIG);
    img_t *logo = create_image(LOGO, NULL);

    UNEXPECTED_EXIT(main_menu)
    set_img_position(logo, (sfVector2f) {0, 60});
    while (is_open_window(sys->window) && sys->actual_scene == MENU_SCENE) {
        check_state_buttons(main_menu,
        sfMouse_getPositionRenderWindow(sys->window));
        menu_event(sys, main_menu);
        if (sys->actual_scene == EXIT_SCENE)
            break;
        draw_menu(sys, main_menu, logo, background);
        sfClock_restart(sys->clock);
    }
    image_destroy(logo);
    image_destroy(background);
    del_menu(main_menu);
}