/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intro_forest.c
*/

/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intro_forest_scene.c
*/

#include "rpg.h"
#include "image.h"
#include "window.h"
#include "scene.h"
#include "menus.h"
#include "intro_scenes.h"

void intro_forest_event(game_sys_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
        if (event.type == sfEvtKeyPressed)
            change_scene(sys, INTRO_CAVE_SCENE);
    }
}

void intro_forest_scene(game_sys_t *sys)
{
    label_t *key_precision =
    create_label(MAIN_FONT, 24, ANY_KEY, sfBlack);
    CHECK_CANCEL(key_precision)
    set_pos_label(key_precision, (sfVector2f) {
        W_SCREEN - m_strlen(ANY_KEY) * 12.25,
        H_SCREEN - 30
    });
    img_t *background = create_image(INTRO_FOREST, NULL);
    change_scene(sys, INTRO_FOREST_SCENE);
    while (is_open_window(sys->window) &&
    sys->actual_scene == INTRO_FOREST_SCENE) {
        intro_forest_event(sys);
        clear_window(sys->window, sfBlack);
        draw_img(background, sys->window);
        draw_lbl(key_precision, sys->window);
        display_window(sys->window);
        sfClock_restart(sys->clock);
    }
    image_destroy(background);
    label_destroy(key_precision);
}