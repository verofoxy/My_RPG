/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest.h
*/

#ifndef QUEST_H
#define QUEST_H

#include <SFML/Graphics.h>
#include "rpg.h"
#include "entity.h"

#define PATH_QUEST_j "./assets/quest/quest_minified.json"
#define FINISHED_QUEST  2
#define IN_PROGRESS     1

typedef struct quest_t
{
    char *name_of_quest;
    bool activate;
    sfVector2f pos;
    location_e loc;
    int state;
    char *description;
} quest_t;

quest_t **create_quest(void);
void destroy_quest(struct quest_t **h_quest);

void end_quest(struct quest_t *quest);
struct quest_t *load_quest(json_object_t *obj);
void draw_quests(struct quest_t **quests, sfRenderWindow *window);

#endif