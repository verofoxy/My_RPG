/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menus
*/

#include "rpg.h"
#include "menus.h"
#include "entity.h"

btn_t **create_menu(char const *filepath)
{
    json_value_t *value_t = get_json_from_file(filepath, true);
    btn_t **menu = NULL;
    json_array_t array_t;

    CHECK_INVALID_PTR(value_t);
    array_t = get_array_value(value_t);
    CHECK_INVALID_PTR(array_t.arr);
    menu = malloc(sizeof(btn_t *) * (array_t.length + 1));
    CHECK_MALLOC(menu);
    menu[array_t.length] = NULL;
    for (int i = 0; i < array_t.length; i++)
        menu[i] = init_btn(json_array_get_object(&array_t, i));
    destroy_json_value(value_t);
    return (menu);
}

void check_state_buttons(btn_t **menu, sfVector2i pos)
{
    int i = 0;

    for (i = 0; menu[i]; i++) {
        if (sfIntRect_contains(&menu[i]->focus_mask, pos.x, pos.y)) {
            menu[i]->hover = true;
            break;
        }
        menu[i]->hover = false;
    }
}

void disp_menu(btn_t **menu, sfRenderWindow *window)
{
    for (int i = 0; menu[i] != NULL; i++)
        disp_btn(menu[i], window);
}

void del_menu(btn_t **menu)
{
    for (int i = 0; menu[i] != NULL; i++)
        del_btn(menu[i]);
    free(menu);
}