/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** animations.c
*/

#include <stdlib.h>
#include "json_parser.h"
#include "entity.h"
#include "animation.h"
#include "my.h"


animation_t *create_animation(int nb_frames, const sfIntRect *frames, float
total_time, bool loop)
{
    animation_t *anim = malloc(sizeof(*anim));

    anim->frames = frames;
    anim->nb_frames = nb_frames;
    anim->durations[ANIM_CURR_FRAME] = 0;
    anim->durations[ANIM_CURR_TIME] = 0;
    anim->durations[ANIM_TIME_ANIM] = total_time;
    anim->states[ANIM_LOOP] = loop;
    anim->states[ANIM_FINISH] = false;
    return anim;
}

void reset_animation(animation_t *anim)
{
    anim->durations[ANIM_CURR_FRAME] = 0;
    anim->durations[ANIM_CURR_TIME] = 0;
    anim->states[ANIM_FINISH] = false;
}

void change_frame(animation_t *anim, sfTime time_past)
{
    if (anim->states[ANIM_FINISH])
        return;
    anim->durations[ANIM_CURR_TIME] += sfTime_asSeconds(time_past);
    anim->durations[ANIM_CURR_FRAME] = (anim->durations[ANIM_CURR_TIME] /
    anim->durations[ANIM_TIME_ANIM]) * (float) anim->nb_frames;
    if (anim->durations[ANIM_CURR_FRAME] >= (float) anim->nb_frames)
        anim->durations[ANIM_CURR_FRAME] -= (
        anim->durations[ANIM_CURR_FRAME] - (float) anim->nb_frames) + 1;
    if (anim->durations[ANIM_CURR_TIME] >= anim->durations[ANIM_TIME_ANIM]) {
        if (anim->states[ANIM_LOOP])
            reset_animation(anim);
        else {
            anim->durations[ANIM_CURR_TIME] = anim->durations[ANIM_TIME_ANIM];
            anim->states[ANIM_FINISH] = true;
        }
    }
}

void set_switch_to(animation_t *anim, char *new_switch)
{
    anim->switch_to = new_switch;
}

void animation_destroy(animation_t *anim)
{
    free(anim);
}
