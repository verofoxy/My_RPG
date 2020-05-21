/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_quests.c
*/

#include "rpg.h"
#include "system.h"
#include "entity.h"
#include "quest.h"

static void draw_labels(label_t *title, label_t *desc, sfRenderWindow *window)
{
    draw_lbl(title, window);
    draw_lbl(desc, window);
}

static void free_tmp(char *desc1, char *desc2)
{
    free(desc1);
    free(desc2);
}

static void update_pos(label_t *title, label_t *desc, float beg_x, float beg_y)
{
    set_pos_label(title, (sfVector2f) {beg_x, beg_y});
    set_pos_label(desc, (sfVector2f) {beg_x, beg_y + 40});
}

sfRectangleShape *get_box(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, sfColor_fromRGBA(245, 179, 28, 90));
    sfRectangleShape_setOutlineThickness(shape, 3);
    sfRectangleShape_setOutlineColor(shape, sfColor_fromRGB(245, 179, 28));
    sfRectangleShape_setSize(shape, (sfVector2f) {500, 80});
    return shape;
}

void draw_quests(quest_t **quests, sfRenderWindow *window)
{
    float begin_x = 15, begin_y = 270;
    label_t *title = create_label(MAIN_FONT, 30, "", sfWhite);
    label_t *desc_lbl = create_label(MAIN_FONT, 25, "", sfWhite);
    char *desc_first_part = NULL, *full_desc = NULL;
    sfRectangleShape *box = get_box();

    for (int i = 0; quests[i]; i++) {
        sfRectangleShape_setPosition(box, (sfVector2f) {begin_x, begin_y});
        update_pos(title, desc_lbl,  begin_x, begin_y);
        change_text(title, quests[i]->name_of_quest);
        desc_first_part = m_strcat_dup(quests[i]->description,  " - ");
        full_desc = m_strcat_dup(desc_first_part,
        (quests[i]->state == FINISHED_QUEST) ? "Finished" : "In Progress");
        change_text(desc_lbl, full_desc);
        sfRenderWindow_drawRectangleShape(window, box, NULL);
        draw_labels(title, desc_lbl, window);
        free_tmp(full_desc, desc_first_part);
        begin_y += 90;
    }
}