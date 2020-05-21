/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_scene.c
*/

#include "my.h"
#include "menus.h"
#include "image.h"
#include "window.h"
#include "scene.h"
#include "fight.h"
#include "window.h"
#include "entity.h"
#include "animation.h"
#include "text.h"
#include "sound.h"

void fight_event(game_sys_t *sys, btn_t **btns)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
        if (event.type == sfEvtKeyPressed)
            if (event.key.code == sfKeyEscape)
                change_scene(sys, WORLD_SCENE);
        if (event.type == sfEvtMouseButtonPressed)
            handle_btn_pressed(sys, btns);
    }
}

void fight_update(game_sys_t *sys)
{
    animate_entities(sys->entities, sys->clock);
}

void draw_combat(game_sys_t *sys, img_t **imgs, btn_t **btn, label_t **labels)
{
    int i = 0;

    clear_window(sys->window, sfRed);
    set_img_position(imgs[HEART], (sfVector2f) {190, 100});
    for ( i = 0; imgs[i] != NULL; i++) {
        draw_img(imgs[i], sys->window);
    }
    set_img_position(imgs[HEART], (sfVector2f) {600, 100});
    draw_img(imgs[HEART] , sys->window);
    disp_menu(btn, sys->window);
    draw_entities(sys->entities, sys->window);
    for (i = 0; labels[i] != NULL; i++) {
        draw_lbl( labels[i], sys->window);
    }
    display_window(sys->window);
}

void attack_player_scene(game_sys_t *sys, img_t *background)
{
    btn_t **btn = create_menu(FIGHT_JSON);
    label_t *labels[5] = {0};
    img_t *imgs[4] = {0};

    create_images_fight(imgs, background);
    create_labels_fight(sys, labels);
    change_animation(GET_PLAYER_ENT(sys->entities), "idle_left",
    NULL);
    change_scene(sys, PLAYER_ATTACK_SCENE);
    while (is_open_window(sys->window)
    && sys->actual_scene == PLAYER_ATTACK_SCENE) {
        check_state_buttons(btn, sfMouse_getPositionRenderWindow(sys->window));
        fight_event(sys, btn);
        draw_combat(sys, imgs, btn, labels);
        fight_update(sys);
        sfClock_restart(sys->clock);
    }
    destroy_fight_scene(imgs, labels);
}