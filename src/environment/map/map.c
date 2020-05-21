/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** map.c
*/

#include "rpg.h"
#include "entity.h"
#include "system.h"
#include "text.h"

map_t *create_map(char const *filepath, char const *datapath, list_t **entities)
{
    map_t *map = malloc(sizeof(map_t));
    sfIntRect tmp;

    CHECK_MALLOC(map)
    map->img = create_image(filepath, NULL);
    CHECK_MALLOC(map->img)
    map->pos.x = 0;
    map->pos.y = 0;
    tmp = sfSprite_getTextureRect(map->img->sprite);
    map->size = (sfVector2u) {tmp.width, tmp.height};
    map->collision_masks = NULL;
    map->nb_masks = 0;
    map->interact = NULL;
    map->action_lbl = create_label(MAIN_FONT, 40, "", sfBlack);
    if (datapath)
        load_map_data(map, datapath, entities);
    return map;
}

map_t *create_map_from_type(location_e type, list_t **entities)
{
    map_t *map = NULL;

    switch (type) {
        case FOREST:
            map = create_map(FOREST_MAP, FOREST_DATA, entities);
            break;
        case CAVE:
            map = create_map(CAVE_MAP, CAVE_DATA, entities);
            break;
        case CITY:
            map = create_map(CITY_MAP, CITY_DATA, entities);
            break;
    }
    CHECK_MALLOC(map)
    map->loc = type;
    return map;
}

void draw_map(map_t *map, sfRenderWindow *window)
{
    draw_img(map->img, window);
    draw_lbl(map->action_lbl, window);
}

void map_destroy(map_t *map)
{
    int i = 0;

    if (map->pnj_ids)
        free(map->pnj_ids);
    image_destroy(map->img);
    if (map->triggers) {
        for (i = 0; map->triggers[i]; i++)
            destroy_trigger(map->triggers[i]);
        free(map->triggers);
    }
    free(map);
}