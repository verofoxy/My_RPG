/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** test_create_entity.c
*/

#include <criterion/criterion.h>
#include "entity.h"
#include "my.h"

Test(test_create_entity, test_element)
{
    list_t *test = malloc(sizeof(*test));
    pnj_t *element = malloc(sizeof(*element));

    create_entity(&test, "test pnj", element, TYPE_PNJ);
    cr_assert_eq(test->element, element);
}

Test(test_create_entity, test_type_element)
{
    list_t *test = malloc(sizeof(*test));
    void *element;
    int rd = rand() % 3;
    char *tab_flag[3] = {"map", "pnj", "player"};

    switch (rd) {
        case TYPE_PLAYER:
            element = malloc(sizeof(player_t));
            create_entity(&test, "player", element, TYPE_PLAYER);
            break;
        case TYPE_PNJ:
            element = malloc(sizeof(pnj_t));
            create_entity(&test, "pnj", element, TYPE_PNJ);
            break;
        case TYPE_MAP:
            element = malloc(sizeof(map_t));
            create_entity(&test, "map", element, TYPE_MAP);
            break;
    }
    cr_assert_eq(m_strcmp(test->tag, tab_flag[rd]), 0);
}