/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_enemy.c
*/

#include "rpg.h"
#include "entity.h"
#include "animation.h"

void destroy_enemy(enemy_t *enemy)
{
    list_destroy(&enemy->animations, animation_destroy);
    image_destroy(enemy->sheet);
    free(enemy->name);
    free(enemy);
}