/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_fight_scene.c
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

void create_labels_fight(game_sys_t *sys, label_t **labels)
{
    labels[LABEL_ENEMY_NAME] = create_label(MAIN_FONT, 60,
    ((enemy_t *)GET_ENEMY(sys->entities))->name, sfBlack);
    labels[LABEL_PLAYER_NAME] = create_label(MAIN_FONT, 60,
    ((player_t *) GET_PLAYER(sys->entities))->name, sfBlack);
    labels[LABEL_PLAYER_LIFE] = create_label(MAIN_FONT, 60,
    m_itos(((player_t *)
    GET_PLAYER(sys->entities))->health.current_health), sfBlack);
    labels[LABEL_ENEMY_LIFE] = create_label(MAIN_FONT, 60,
    m_itos(((enemy_t *)
    GET_ENEMY(sys->entities))->health.current_health), sfBlack);
    set_pos_label( labels[LABEL_ENEMY_NAME], (sfVector2f) {50, 0});
    set_pos_label(labels[LABEL_ENEMY_LIFE], (sfVector2f) {100, 80});
    set_pos_label(labels[LABEL_PLAYER_NAME], (sfVector2f) {480 , 0});
    set_pos_label(labels[LABEL_PLAYER_LIFE], (sfVector2f) {500, 80});
    set_img_position(((player_t *) GET_PLAYER(sys->entities))->sheet,
    (sfVector2f) {400, 250});
}

void create_images_fight(img_t **imgs, img_t *background)
{
    imgs[BACKGROUND] = background;
    imgs[VS] = create_image(IMG_VS, NULL);
    imgs[HEART] = create_image(IMG_HEART, NULL);
    set_img_position(imgs[VS], (sfVector2f) {350, 0});
}

void destroy_fight_scene(img_t **imgs, label_t **labels)
{
    image_destroy(imgs[VS]);
    image_destroy(imgs[HEART]);
    label_destroy(labels[LABEL_ENEMY_NAME]);
    label_destroy(labels[LABEL_ENEMY_LIFE]);
    label_destroy(labels[LABEL_PLAYER_NAME]);
    label_destroy(labels[LABEL_PLAYER_LIFE]);
}