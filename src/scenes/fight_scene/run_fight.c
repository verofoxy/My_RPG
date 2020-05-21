/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** run_fight.c
*/

#include "rpg.h"
#include "entity.h"
#include "animation.h"
#include "fight.h"
#include "scene.h"
#include "lose.h"
#include "sound.h"

void end_fight_checker(game_sys_t *sys, bool death_player, bool death_enemy)
{
    if (death_player == true) {
        change_scene(sys, LOSE_SCENE);
        return;
    }
    if (death_enemy == true)
        up_xp(GET_PLAYER(sys->entities), BOUNTY_XP);
    if (sys->actual_scene == EXIT_SCENE)
        return;
    list_destroy(&sys->entities[ENEMY_BRANCH], destroy_entity);
    fade_out(sys, WORLD_SCENE);
}

void fight_loop(
    game_sys_t *sys,
    bool *death_player,
    bool *death_enemy,
    bool *run_away
)
{
    img_t *background =  (sys->map->loc == FOREST)
    ? create_image(IMG_FIGHT_FOREST, NULL)
    : create_image(IMG_FIGHT_CAVE, NULL);

    while (*death_player == false && *death_enemy == false &&
    sys->actual_scene == FIGHT_SCENE)
    {
        attack_player_scene(sys, background);
        if (sys->actual_scene != FIGHT_SCENE) {
            *run_away = true;
            break;
        }
        *death_enemy = check_death_entity(GET_ENEMY_ENT(sys->entities));
        attack_enemy_scene(sys, background);
        change_animation(GET_ENEMY_ENT(sys->entities), "idle", NULL);
        *death_player = check_death_entity(GET_PLAYER_ENT(sys->entities));
    }
    image_destroy(background);
}

void run_fight(game_sys_t *sys, bool *run_away)
{
    bool death_player = false;
    bool death_enemy = false;

    fight_loop(sys, &death_player, &death_enemy, run_away);
    end_fight_checker(sys, death_player, death_enemy);
}