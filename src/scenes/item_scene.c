/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** item_scene.c
*/

#include "rpg.h"
#include "scene.h"
#include "window.h"
#include "particle.h"
#include "sound.h"

void item_key_management(game_sys_t *sys, sfKeyCode key)
{
    if (key == sfKeyEscape || key == sfKeyE)
        change_scene(sys, WORLD_SCENE);
}

void item_scene_event(game_sys_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
        if (event.type == sfEvtKeyPressed)
            item_key_management(sys, event.key.code);
    }
}

static void init_labels(label_t **labels, item_t *new_item)
{
    label_t *congrats = create_label(
            MAIN_FONT,
            45,
            "CONGRATULATIONS !!!",
            sfWhite
    );
    label_t *name_item = create_label(MAIN_FONT, 35,
    m_strcat_dup("New item : ", new_item->name), sfWhite);
    labels[0] = congrats;
    labels[1] = name_item;
    labels[2] = NULL;
}

void draw_item_scene(game_sys_t *sys, label_t **labels,
sfRectangleShape *shader, float *time_)
{
    int i = 0;

    clear_window(sys->window, sfBlack);
    draw_map(sys->map, sys->window);
    draw_entities(sys->entities, sys->window);
    sfRenderWindow_drawRectangleShape(sys->window, shader, NULL);
    for (i = 0; labels[i]; i++)
        draw_lbl(labels[i], sys->window);
    *time_ += sfTime_asSeconds(sfClock_getElapsedTime(sys->clock));
    if (*time_ <= 0.02) {
        particle_effect(800, FREQUENCY(200), PATH_PART_BUBBLE, sys->window);
        particle_effect(800, FREQUENCY(250), PATH_PART_FIRE, sys->window);
    }
    display_window(sys->window);

}

void item_scene(game_sys_t *sys, item_t *new_item)
{
    float time_ = 0.0f;
    sfRectangleShape *shader = init_shader();
    label_t *labels[3];

    sound_handle(sys, NEWITEM, 10, PLAY);
    sound_handle(sys, NEWITEM, 10, VOLUME);
    init_labels(labels, new_item);
    set_pos_label(labels[0], (sfVector2f) {200, 100});
    set_pos_label(labels[1], (sfVector2f) {250, 300});
    while (is_open_window(sys->window) && sys->actual_scene == ITEM_SCENE) {
        item_scene_event(sys);
        draw_item_scene(sys, labels, shader, &time_);
        sfClock_restart(sys->clock);
    }
    sound_handle(sys, NEWITEM, 30, STOP);
    change_scene(sys, WORLD_SCENE);
    sfClock_restart(sys->clock);
}