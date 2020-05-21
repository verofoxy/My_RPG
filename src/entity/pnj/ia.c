/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ia.c
*/

#include "rpg.h"
#include "entity.h"

void apply_move(entity_t *tmp)
{
    pnj_t *pnj = get_entity_value(tmp);

    if (!pnj->ia.reverse) {
        if (pnj->ia.type == HORIZONTAL) {
            move(tmp, MOVES[MOVE_RIGHT]);
            set_anim_pnj(pnj, "right", "idle");
        } else {
            move(tmp, MOVES[MOVE_DOWN]);
            set_anim_pnj(pnj, "down", "idle");
        }
    } else {
        if (pnj->ia.type == HORIZONTAL) {
            move(tmp, MOVES[MOVE_LEFT]);
            set_anim_pnj(pnj, "left", "idle");
        } else {
            move(tmp, MOVES[MOVE_UP]);
            set_anim_pnj(pnj, "up", "idle");
        }
    }
}

void play_ia(entity_t *tmp, float dt)
{
    pnj_t *pnj = get_entity_value(tmp);

    pnj->ia.curr_time += dt;
    if (pnj->ia.curr_time >= pnj->ia.delay) {
        pnj->ia.reverse = !pnj->ia.reverse;
        pnj->ia.curr_time = 0;
    }
    apply_move(tmp);
}

void move_pnjs(list_t *pnjs, sfClock *clock)
{
    while (pnjs) {
        play_ia(pnjs->element, sfTime_asSeconds(sfClock_getElapsedTime(clock)));
        pnjs = pnjs->next;
    }
}