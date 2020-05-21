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
#include "end.h"
#include "sound.h"

void end_event(game_sys_t *sys, btn_t **menu)
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

void draw_end(game_sys_t *sys, btn_t **menu, img_t *background)
{
    clear_window(sys->window, sfBlack);
    draw_img(background, sys->window);
    disp_menu(menu, sys->window);
    display_window(sys->window);
}

void check_end(game_sys_t *sys, quest_t **quests)
{
    int i = 0;

    for (i = 0; quests[i] != NULL; i++)
        if (quests[i]->state != 2)
            return;
    change_scene(sys, END_SCENE);
}

void end_scene(game_sys_t *sys)
{
    img_t *end_background = create_image(IMG_END_SCENE, NULL);
    btn_t **end_menu = create_menu(END_SCENE_JSON);

    UNEXPECTED_EXIT(end_menu)
    sound_handle(sys, GAMEOVER, 30, PLAY);
    sound_handle(sys, GAMEOVER, 20, VOLUME);
    while (is_open_window(sys->window) && sys->actual_scene == END_SCENE) {
        check_state_buttons(end_menu,
        sfMouse_getPositionRenderWindow(sys->window));
        end_event(sys, end_menu);
        if (sys->actual_scene == EXIT_SCENE)
            break;
        draw_end(sys, end_menu, end_background);
        sfClock_restart(sys->clock);
    }
    image_destroy(end_background);
    del_menu(end_menu);
}