/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particle.c
*/

#include "json_parser.h"
#include "entity.h"
#include "particle.h"

player_t *f_player(entity_t *ent)
{
    if (ent->type == PLAYER_ENT)
        return (ent->entity_value.player);
    return (NULL);
}

player_t *find_player_for_set_particle(list_t **entities)
{
    int i = 0;
    list_t *tmp = NULL;
    player_t *player = NULL;

    for (i = 0; i < NB_BRANCH; i++) {
        tmp = entities[i];
        while (tmp) {
            player = f_player(tmp->element);
            if (player)
                return (player);
            tmp = tmp->next;
        }
    }
    return NULL;
}

void set_random_pos(sfVector2f rect_center, img_t *img, const int size)
{
    if (rand() % 10 < 5)
        rect_center.x -= (rand() % size / 2);
    else
        rect_center.x += (rand() % size / 2);
    if (rand() % 10 < 5)
        rect_center.y -= (rand() % size / 2);
    else
        rect_center.y += (rand() % size / 2);
    set_img_position(img, rect_center);
}

void set_random_pos_particle(img_t *img, const int range)
{
    sfVector2f new_pos;

    if (img && range) {
        new_pos.x = get_img_pos(img).x + RAND_PART_POS_X;
        new_pos.y = get_img_pos(img).y - RAND_PART_POS_Y;
        set_img_position(img, new_pos);
    }
}

void destroy_particle(particle_t *part)
{
    if (part) {
        image_destroy(part->img);
        part = NULL;
    }
}