/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pause_scene.c
*/

#include "rpg.h"
#include "window.h"
#include "scene.h"
#include "entity.h"
#include "menus.h"
#include "quest.h"

void pause_event(game_sys_t *sys, btn_t **pause_menu, int actual_scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            change_scene(sys, actual_scene);
        if (event.type == sfEvtMouseButtonPressed)
            handle_btn_pressed(sys, pause_menu);
    }
}

void draw_pause_menu(game_sys_t *sys, btn_t **pause_menu,
sfRectangleShape *shader, label_t **labels)
{
    sfRenderWindow_drawRectangleShape(sys->window, shader, NULL);
    for (int i = 0; labels[i]; i++)
        draw_lbl(labels[i], sys->window);
    disp_menu(pause_menu, sys->window);
    draw_quests(((player_t *) GET_PLAYER(sys->entities))->quests,
    sys->window);
    display_window(sys->window);
}

static void draw_map_pause(game_sys_t *sys, int actual_scene)
{
    clear_window(sys->window, sfBlack);
    if (actual_scene == WORLD_SCENE) {
        draw_map(sys->map, sys->window);
        draw_entities(sys->entities, sys->window);
    }
}

void create_labels_stat(game_sys_t *sys, label_t **labels)
{
    labels[0] = create_label(
        MAIN_FONT,
        30,
        m_strcat_dup("Health Point:  ",
        m_itos(((player_t *)
        GET_PLAYER(sys->entities))->health.current_health)),
        sfBlack
    );
    labels[1] = create_label(
        MAIN_FONT,
        30,
        m_strcat_dup("Lvl:  ",
        m_itos(((player_t *)
        GET_PLAYER(sys->entities))->exp.lvl)),
        sfBlack
    );
    labels[2] = create_label(MAIN_FONT, 30, "Quests: ", sfBlack);
    labels[3] = create_label(MAIN_FONT, 30, "", sfBlack);
}

void pause_menu(game_sys_t *sys, int actual_scene)
{
    btn_t **pause_menu = create_menu(PAUSE_CONFIG);
    sfRectangleShape *shader = init_shader();
    label_t *labels[5] = {0};

    create_labels_stat(sys, labels);
    set_pos_label(labels[0], (sfVector2f) {15, 0});
    set_pos_label(labels[1], (sfVector2f) {15, 50});
    set_pos_label(labels[2], (sfVector2f) {15, 200});
    change_scene(sys, PAUSE_SCENE);
    while (is_open_window(sys->window) && sys->actual_scene == PAUSE_SCENE) {
        check_state_buttons(pause_menu,
        sfMouse_getPositionRenderWindow(sys->window));
        pause_event(sys, pause_menu, actual_scene);
        draw_map_pause(sys, actual_scene);
        draw_pause_menu(sys, pause_menu, shader, labels);
        sfClock_restart(sys->clock);
    }
    sfClock_restart(sys->clock);
    del_menu(pause_menu);
}