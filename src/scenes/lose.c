/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** lose.c
*/

#include "rpg.h"
#include "window.h"
#include "scene.h"
#include "entity.h"
#include "menus.h"
#include "lose.h"
#include "sound.h"

void lose_event(game_sys_t *sys, btn_t **menu)
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

void draw_lose(
    game_sys_t *sys,
    btn_t **menu,
    img_t *gameover_text,
    img_t *background
)
{
    clear_window(sys->window, sfBlack);
    draw_img(background, sys->window);
    draw_img(gameover_text, sys->window);
    disp_menu(menu, sys->window);
    display_window(sys->window);
}

void lose_scene(game_sys_t *sys)
{
    img_t *gameover = create_image(GAMEOVER_IMG, NULL);
    img_t *background = create_image(MAIN_BKG, NULL);
    btn_t **lose_menu = create_menu(LOSE_CONFIG);

    sound_handle(sys, GAMEOVER, 30, PLAY);
    sound_handle(sys, GAMEOVER, 30, VOLUME);
    set_img_position(gameover, (sfVector2f) { 100, 100});
    while (is_open_window(sys->window) && sys->actual_scene == LOSE_SCENE) {
        check_state_buttons(lose_menu,
        sfMouse_getPositionRenderWindow(sys->window));
        lose_event(sys, lose_menu);
        if (sys->actual_scene == EXIT_SCENE)
            break;
        draw_lose(sys, lose_menu, gameover, background);
        sfClock_restart(sys->clock);
    }
    image_destroy(gameover);
    image_destroy((background));
    del_menu(lose_menu);
}