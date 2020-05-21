/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** test_add_entity_branch.c
*/

#include <criterion/criterion.h>
#include "entity.h"
#include "my.h"

Test(test_add_entity_branch, test_size)
{
    list_t **tab = malloc(sizeof(list_t *) * 3);
    void *element = malloc(sizeof(*element));
    list_t *test = NULL;
    int i = 0;

    tab[2] = (void *)0;
    create_entity(&test, "green home", (map_t *)element, TYPE_MAP);
    add_entity_branch(tab, test, TYPE_MAP);
    test = NULL;
    create_entity(&test, "pnj chien", (pnj_t *)element, TYPE_PNJ);
    add_entity_branch(tab, test, TYPE_PNJ);
    for (; tab[i];)
        if (tab[i] == test)
            i++;
        else
            return ;
    cr_assert_eq(i, 1);
}