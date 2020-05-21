/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj.c
*/

#include "rpg.h"
#include "image.h"
#include "entity.h"
#include "animation.h"

void draw_pnj(pnj_t *pnj, sfRenderWindow *window)
{
    draw_img(pnj->sheet, window);
}

void get_anim_pnj(pnj_t *pnj, animation_t **curr)
{
    *curr = list_get_from_tag(pnj->animations, pnj->curr_animation);
}

void set_anim_pnj(pnj_t *obj, char *tag_anim, char *switch_after)
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

pnj_t *update_pnj(pnj_t *pnj, list_t **entities, map_t *map, float dt)
{
    float offset_x = pnj->trigger->area.left - pnj->pos.x;
    float offset_y = pnj->trigger->area.top - pnj->pos.y;

    if (collide_with_player(pnj, entities, dt) == false
    && collide_with_walls_pnj(pnj, map, dt) == false) {
        pnj->pos.x += (pnj->move.x * MOVE_PNJ_SPEED * dt);
        pnj->pos.y += (pnj->move.y * MOVE_PNJ_SPEED * dt);
        pnj->collision_mask.left = pnj->pos.x + 10;
        pnj->collision_mask.top = pnj->pos.y + 20;
        pnj->trigger->area.left = pnj->pos.x + offset_x;
        pnj->trigger->area.top = pnj->pos.y + offset_y;
        set_img_position(pnj->sheet, pnj->pos);
    }
    pnj->move = (sfVector2f) {0, 0};
    return pnj;
}