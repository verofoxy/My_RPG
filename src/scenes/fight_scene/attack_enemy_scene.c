/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** attack_player_scene.c
*/

#include "rpg.h"
#include "scene.h"
#include "window.h"
#include "entity.h"
#include "fight.h"
#include "animation.h"
#include "sound.h"

void animation_attack_event(game_sys_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
    }
}

void draw_enemy_scene_fight(game_sys_t *sys, img_t *back)
{
    clear_window(sys->window, sfBlack);
    draw_img(back, sys->window);
    draw_entities(sys->entities, sys->window);
    display_window(sys->window);
}

void attack_enemy_scene(game_sys_t *sys, img_t *background)
{
    animation_t *anim = NULL;
    entity_t *enemy = GET_ENEMY_ENT(sys->entities);
    entity_t *player = GET_PLAYER_ENT(sys->entities);

    SFX_ACTIVED(sound_handle(sys, ATT, 30, PLAY));
    SFX_ACTIVED(sound_handle(sys, ATT, 30, VOLUME));
    change_scene(sys, ENEMY_ATTACK_SCENE);
    change_animation(enemy, "attack", NULL);
    get_anim_enemy(get_entity_value(enemy), &anim);
    while (is_open_window(sys->window) &&
    sys->actual_scene == ENEMY_ATTACK_SCENE) {
        animation_attack_event(sys);
        draw_enemy_scene_fight(sys, background);
        animate_entities(sys->entities, sys->clock);
        sfClock_restart(sys->clock);
        if (anim->states[ANIM_FINISH])
            change_scene(sys, FIGHT_SCENE);
    }
    attack_entity(enemy, player);
}