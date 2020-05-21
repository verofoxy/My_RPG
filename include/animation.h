/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** animation.h
*/

#ifndef MUL_MY_DEFENDER_2019_ANIMATION_H
#define MUL_MY_DEFENDER_2019_ANIMATION_H

#include <SFML/Graphics.h>
#include <stdbool.h>

#define TO_SEC(x) (float) (x) / 1000

typedef struct animation
{
    float durations[3];
    bool states[2];
    char *switch_to;
    const sfIntRect *frames;
    int nb_frames;
} animation_t;

animation_t *create_animation(int nb_frames, const sfIntRect *frames, float
total_time, bool loop);
void set_switch_to(animation_t *anim, char *new_switch);
void change_frame(animation_t *anim, sfTime time_past);
void animation_destroy(animation_t *anim);
void play_animation(entity_t *ent, sfClock *clock);
void change_animation(entity_t *obj, char *tag_anim, char
*switch_after);
void apply_on_entity(entity_t *entity, void(*funcs[])());
void get_anim_player(player_t *obj, animation_t **curr);
void get_anim_pnj(pnj_t *pnj, animation_t **curr);
void get_anim_enemy(enemy_t *obj, animation_t **curr);

static const int ANIM_LOOP = 0;
static const int ANIM_FINISH = 1;

static const int ANIM_CURR_FRAME = 0;
static const int ANIM_TIME_ANIM = 1;
static const int ANIM_CURR_TIME = 2;


#endif