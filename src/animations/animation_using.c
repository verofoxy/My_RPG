/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** animation_part1.c
*/

#include <stdlib.h>
#include "my.h"
#include "json_parser.h"
#include "entity.h"
#include "animation.h"

void update_frame(entity_t *ent, animation_t *curr)
{
    switch (ent->type) {
        case PLAYER_ENT:
            set_img_rect(ent->entity_value.player->sheet, curr->frames[
                (int) curr->durations[ANIM_CURR_FRAME]
            ]);
            break;
        case PNJ_ENT:
            set_img_rect(ent->entity_value.pnj->sheet, curr->frames[
                (int) curr->durations[ANIM_CURR_FRAME]
            ]);
            break;
        case ENEMY_ENT:
            set_img_rect(ent->entity_value.enemy->sheet, curr->frames[
                (int) curr->durations[ANIM_CURR_FRAME]
            ]);
            break;
    }
}

void change_animation(entity_t *ent, char *tag_anim, char
*switch_after)
{
    switch (ent->type) {
        case PLAYER_ENT:
            set_anim_player(ent->entity_value.player, tag_anim, switch_after);
            break;
        case PNJ_ENT:
            set_anim_pnj(ent->entity_value.pnj, tag_anim, switch_after);
            break;
        case ENEMY_ENT:
            set_anim_enemy(ent->entity_value.enemy, tag_anim, switch_after);
            break;
    }
}

void play_animation(entity_t *ent, sfClock *clock)
{
    animation_t *curr = NULL;
    sfTime time_past = sfClock_getElapsedTime(clock);

    switch (ent->type) {
        case PLAYER_ENT:
            get_anim_player(ent->entity_value.player, &curr);
            break;
        case PNJ_ENT:
            get_anim_pnj(ent->entity_value.pnj, &curr);
            break;
        case ENEMY_ENT:
            get_anim_enemy(ent->entity_value.enemy, &curr);
            break;
    }
    if (curr->states[ANIM_FINISH] && curr->switch_to != NULL) {
        change_animation(ent, curr->switch_to, NULL);
        return;
    }
    change_frame(curr, time_past);
    update_frame(ent, curr);
}

void animate_entities(list_t **entities, sfClock *clock)
{
    int i = 0;
    list_t *tmp = NULL;

    for (i = 0; i < NB_BRANCH; i++) {
        tmp = entities[i];
        while (tmp) {
            play_animation(tmp->element, clock);
            tmp = tmp->next;
        }
    }
}