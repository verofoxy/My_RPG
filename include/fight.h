/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.h
*/

#ifndef MUL_MY_RPG_2019_FIGHT_H
#define MUL_MY_RPG_2019_FIGHT_H

#define IMG_FIGHT_CAVE "./assets/scenes/fight/fight_cave.png"
#define IMG_FIGHT_FOREST "./assets/scenes/fight/fight_forest.png"

#define IMG_VS "./assets/scenes/fight/vs.png"
#define IMG_HEART "./assets/scenes/fight/heart.png"

#define FIGHT_JSON "./assets/menus/fight.min.json"
#include "window.h"
#include "image.h"
#include "system.h"
#include "menus.h"

static const int BOUNTY_XP = 10;

static const int LABEL_ENEMY_NAME = 0;
static const int LABEL_PLAYER_NAME = 1;
static const int LABEL_ENEMY_LIFE  = 3;
static const int LABEL_PLAYER_LIFE = 2;

static const int BACKGROUND = 0;
static const int VS = 1;
static const int HEART = 2;

/*player*/
player_t *lvl_up(player_t *player);
player_t *up_xp(player_t *player, int bounty_xp);
enemy_t *attack_player(player_t *src, enemy_t *dest);
player_t * get_heart(player_t *player, int add_heart);
bool check_death_player(player_t *player);

/*enemy*/
player_t *attack_enemy(enemy_t *src, player_t *dest);
bool check_death_enemy(enemy_t *enemy);

/*both*/
void attack_entity(entity_t *src_attack, entity_t *dest_attack);
bool check_death_entity(entity_t *entity);

/*fight_scene*/
void fight_event(game_sys_t *sys, btn_t **btns);
void fight_update(game_sys_t *sys);
void draw_combat(game_sys_t *sys, img_t **imgs, btn_t **btn, label_t **labels);
void create_labels_fight(game_sys_t *sys, label_t **labels);
void create_images_fight(img_t **imgs, img_t *background);
void destroy_fight_scene(img_t **imgs, label_t **labels);
void run_boss_fight(game_sys_t *sys, map_t *map, trigger_t *trigger);

#endif