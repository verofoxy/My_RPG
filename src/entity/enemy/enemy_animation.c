/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** enemy_animation.c
*/

#include "rpg.h"
#include "entity.h"
#include "animation.h"

void get_anim_enemy(enemy_t *obj, animation_t **curr)
{
    *curr = list_get_from_tag(obj->animations, obj->curr_animation);
}

void set_anim_enemy(enemy_t *obj, char *tag_anim, char *switch_after)
{
    animation_t *n_curr = NULL;

    if (tag_anim == NULL ||
        list_get_from_tag(obj->animations, tag_anim) == NULL)
        return;
    if (m_strcmp(tag_anim, obj->curr_animation) == 0 &&
        !((animation_t *) list_get_from_tag(obj->animations, tag_anim))
                ->states[ANIM_FINISH])
        return;
    obj->curr_animation = tag_anim;
    n_curr = list_get_from_tag(obj->animations, tag_anim);
    n_curr->switch_to = switch_after;
    n_curr->durations[ANIM_CURR_FRAME] = 0;
    n_curr->durations[ANIM_CURR_TIME] = 0;
    n_curr->states[ANIM_FINISH] = false;
}