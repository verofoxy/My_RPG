/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest.c
*/

#include "rpg.h"
#include "entity.h"
#include "quest.h"
#include "json_parser.h"

void destroy_quest(quest_t **h_quest)
{
    for (int i = 0; h_quest[i]; i++) {
        free(h_quest[i]->name_of_quest);
        free(h_quest[i]->description);
        free(h_quest[i]);
    }
    free(h_quest);
}

void end_quest(quest_t *quest)
{
    quest->activate = false;
    quest->state = 2;
}

quest_t *load_quest(json_object_t *obj)
{
    quest_t *quest = malloc(sizeof(*quest));

    CHECK_MALLOC(quest)
    quest->activate = json_object_get_bool(obj, "activate");
    quest->pos = get_position_from_object(obj, "position");
    quest->name_of_quest =  m_strdup(json_object_get_str(obj, "quest"));
    quest->state = json_object_get_int(obj, "state");
    quest->description =  m_strdup(json_object_get_str(obj, "description"));
    if (m_strcmp(json_object_get_str(obj, "map"), "FOREST") == 0)
        quest->loc = FOREST;
    else
        quest->loc = CAVE;
    return (quest);
}

quest_t **create_quest(void)
{
    quest_t **h_quest = NULL;
    json_value_t *quest_json = get_json_from_file(PATH_QUEST_j, true);
    json_array_t quest_array;
    json_object_t *obj = NULL;

    CHECK_INVALID_PTR(quest_json)
    quest_array = get_array_value(quest_json);
    h_quest = malloc(sizeof(quest_t *) * (quest_array.length + 1));
    CHECK_MALLOC(h_quest)
    h_quest[quest_array.length] = NULL;
    for (int i = 0; i < quest_array.length; i++) {
        obj = json_array_get_object(&quest_array, i);
        h_quest[i] = load_quest(obj);
    }
    destroy_json_value(quest_json);
    return (h_quest);
}