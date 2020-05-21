/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** item.h
*/

#ifndef MUL_MY_RPG_2019_ITEM_H
#define MUL_MY_RPG_2019_ITEM_H

typedef enum item_type {
    ATTACK_ITEM,
    HEAL_ITEM
} item_type_e;

typedef struct item {
    char *name;
    item_type_e itm_type;
    int bonus_attack;
    int bonus_vie;
} item_t;

void destroy_item(item_t *item);
list_t *load_items(json_array_t array);
item_t *create_item(json_object_t *obj);

#endif
