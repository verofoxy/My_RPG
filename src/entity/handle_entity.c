/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handelEntity.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "entity.h"

void add_entity_branch(list_t *tab_entity[], list_t *new_branch,
unsigned int type_branch)
{
    tab_entity[type_branch] = new_branch;
}

float add_entity(list_t *entity_tab[], entity_t *entity, unsigned int branch_id)
{
    entity->entity_id = create_id((float) branch_id,
    (float) list_get_length(entity_tab[branch_id]));
    list_push(&entity_tab[branch_id], entity, NULL);

    return entity->entity_id;
}

entity_t *get_entity_from_id(list_t *tab_entity[], float target_id)
{
    entity_t *entity = list_get_from_index(
    tab_entity[take_id(BRANCH_ID_TYPE, target_id)],
    take_id(ENTITY_ID_TYPE, target_id));

    return entity;
}

int take_id(id_type_e type_id, long double id)
{
    int i;

    if (type_id == BRANCH_ID_TYPE) {
        i = (int) ((id - (long int)id) * 10000);
        if (i == 0)
            return (0);
        while (i % 10 == 0)
            i /= 10;
    }
    else if (type_id == ENTITY_ID_TYPE)
        i = (int) id;
    else
        return (-1);
    return (i);
}

float create_id(float id_branch, float id_entity)
{
    return (id_entity + (id_branch / 10));
}
