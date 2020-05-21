/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_items.c
*/

#include "rpg.h"
#include "entity.h"

list_t *load_items(json_array_t array)
{
    list_t *items = NULL;
    item_t *tmp = NULL;
    int i = 0;

    CHECK_INVALID_PTR(array.arr)
    for (i = 0; i < array.length; i++) {
        tmp = create_item(json_array_get_object(&array, i));
        CHECK_INVALID_PTR(tmp)
        list_push(&items, tmp, tmp->name);
    }
    return items;
}

item_t *create_item(json_object_t *obj)
{
    item_t *item = malloc(sizeof(item_t));

    CHECK_MALLOC(item)
    item->name = m_strdup(json_object_get_str(obj, "name"));
    item->bonus_attack = json_object_get_int(obj, "bonus_attack");
    item->bonus_vie = json_object_get_int(obj, "bonus_vie");
    if (m_strcmp(json_object_get_str(obj, "type"), "ATTACK") == 0)
        item->itm_type = ATTACK_ITEM;
    else
        item->itm_type = HEAL_ITEM;
    return item;
}

void destroy_item(item_t *item)
{
    free(item->name);
    free(item);
}