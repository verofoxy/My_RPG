/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_map.c
*/

#include "rpg.h"
#include "entity.h"
#include "system.h"
#include "text.h"
#include "item.h"

float *load_map_pnjs(json_array_t *array, list_t **entities)
{
    float *ids = NULL;
    entity_t *ent = NULL;
    pnj_t *tmp_pnj = NULL;

    if (!array->arr)
        return NULL;
    ids = malloc(sizeof(float) * array->length);
    CHECK_MALLOC(ids);
    for (int i = 0; i < array->length; i++) {
        tmp_pnj = create_pnj_from_json(array->arr[i]);
        ent = create_entity(PNJ_ENT, tmp_pnj);
        ids[i] = add_entity(entities, ent, PNJ_BRANCH);
    }
    entities[PNJ_BRANCH] = list_reverse(entities[PNJ_BRANCH]);
    return ids;
}

trigger_t **load_triggers(json_array_t data)
{
    int i = 0;
    trigger_t **triggers = NULL;

    if (!data.arr)
        return NULL;
    triggers = malloc(sizeof(trigger_t *) * (data.length + 1));
    CHECK_MALLOC(triggers)
    triggers[data.length] = NULL;
    for (i = 0; i < data.length; i++)
        triggers[i] = create_trigger(json_array_get_object(&data, i));
    return triggers;
}

int load_map_data(map_t *map, char const *json_path, list_t **entities)
{
    json_value_t *json_value = get_json_from_file(json_path, true);
    json_object_t *obj = NULL;
    json_array_t col_arr;
    json_array_t pnjs;

    CHECK_NULL(json_value)
    obj = get_json_object(json_value);
    col_arr = json_object_get_array(obj, "collisions");
    pnjs = json_object_get_array(obj, "pnjs");
    map->nb_masks = col_arr.length;
    map->collision_masks = get_masks(&col_arr);
    map->pnj_ids = load_map_pnjs(&pnjs, entities);
    map->nb_ids = pnjs.length;
    map->triggers = load_triggers(json_object_get_array(obj, "triggers"));
    map->items = load_items(json_object_get_array(obj, "items"));
    destroy_json_value(json_value);
    return EXEC_SUCCESS;
}

