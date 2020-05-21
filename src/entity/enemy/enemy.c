/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
**  enemy.c
*/

#include <time.h>
#include "rpg.h"
#include "entity.h"
#include "animation.h"

entity_t *get_random_enemy(location_e loc)
{
    entity_t *ent = NULL;
    enemy_t *enemy = NULL;
    json_value_t *value = NULL;
    json_array_t arr_enemy;
    int selected_monster = 0;

    value = (loc == FOREST)
    ? get_json_from_file(FOREST_ENEMIES, true)
    : get_json_from_file(CAVE_ENEMIES, true);
    CHECK_INVALID_PTR(value);
    arr_enemy = get_array_value(value);
    selected_monster = rand()  % (arr_enemy.length - 1);
    enemy = create_enemy_from_json(arr_enemy.arr[selected_monster]);
    ent = create_entity(ENEMY_ENT, enemy);
    return ent;
}

entity_t *get_boss(location_e loc)
{
    entity_t *ent = NULL;
    enemy_t *boss = NULL;
    json_value_t *value = NULL;
    json_array_t arr_enemy;

    value = (loc == FOREST)
    ? get_json_from_file(FOREST_ENEMIES, true)
    : get_json_from_file(CAVE_ENEMIES, true);
    CHECK_INVALID_PTR(value);
    arr_enemy = get_array_value(value);
    boss = create_enemy_from_json(arr_enemy.arr[BOSS_IDX]);
    ent = create_entity(ENEMY_ENT, boss);
    return ent;
}

void draw_enemy(enemy_t *enemy, sfRenderWindow *window)
{
    draw_img(enemy->sheet, window);
}