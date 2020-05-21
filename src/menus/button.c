/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button
*/

#include "rpg.h"
#include "menus.h"
#include "entity.h"
#include "scene.h"

btn_t *set_img_states(btn_t *this, json_object_t *info)
{
    if (!info) {
        this->states[0] = NULL;
        this->states[1] = NULL;
        return this;
    }
    this->states[0] =
    create_image(json_object_get_str(info, "idle"), &this->rect);
    this->states[1] =
    create_image(json_object_get_str(info, "hover"), &this->rect);
    if (this->states[0])
        set_img_position(this->states[0], this->pos);
    if (this->states[1])
        set_img_position(this->states[1], this->pos);
    return this;
}

btn_t *load_action_btn(btn_t *this, json_object_t *obj)
{
    int i = 0;
    char const *action_txt = json_object_get_str(obj, "action");

    for (i = 0; i < NB_ACTIONS_BTN; i++) {
        if (m_strcmp(BTN_ACTIONS[i].key, action_txt) == 0) {
            BTN_ACTIONS[i].callback(this, obj);
            return this;
        }
    }
    this->callback = NULL;
    this->arg = 0;
    return this;
}

btn_t *init_btn(json_object_t *obj)
{
    btn_t *btn = NULL;
    char const *name = json_object_get_str(obj, "name");

    CHECK_MALLOC(obj)
    btn = malloc(sizeof(btn_t));
    CHECK_MALLOC(btn);
    btn->hover = false;
    btn->name = create_label(MAIN_FONT, 30, name, sfWhite);
    btn->pos = get_position_from_object(obj, "pos");
    btn->rect = get_int_rect_from_object(obj, "rect");
    btn->focus_mask = (sfIntRect) {
    (int) btn->pos.x, (int) btn->pos.y, btn->rect.width, btn->rect.height};
    set_pos_label(btn->name, (sfVector2f) {
        btn->pos.x + btn->rect.width / 2 - m_strlen(name) * 15 / 2,
        btn->pos.y + btn->rect.height / 2 - 25});
    set_img_states(btn, json_object_get_object(obj, "states"));
    load_action_btn(btn, obj);
    return (btn);
}

void disp_btn(btn_t *btn, sfRenderWindow *window)
{
    if (btn->hover)
        draw_img(btn->states[1], window);
    else
        draw_img(btn->states[0], window);
    draw_lbl(btn->name, window);
}

void del_btn(btn_t *btn)
{
    label_destroy(btn->name);
    if (btn->states[0])
        image_destroy(btn->states[0]);
    if (btn->states[1])
        image_destroy(btn->states[1]);
    free(btn);
}