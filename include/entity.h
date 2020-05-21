/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** entity.h
*/

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.h>
#include "list.h"
#include "image.h"
#include "text.h"
#include "item.h"

//TYPE of THE BRANCH
#define PLAYER_BRANCH   0
#define ENEMY_BRANCH    1
#define PNJ_BRANCH      2
#define NB_BRANCH       3

#define FOREST_MAP      "./assets/img/forest.png"
#define FOREST_DATA     "./assets/map/forest_minified.json"
#define FOREST_ENEMIES  "./assets/perso/forest_enemies_data.min.json"

#define CITY_MAP        "./assets/img/city.png"
#define CITY_DATA       "./assets/map/city_minified.json"

#define CAVE_MAP        "./assets/img/cave.png"
#define CAVE_DATA       "./assets/map/cave_minified.json"
#define CAVE_ENEMIES    "./assets/perso/cave_enemies_data.min.json"

#define PLAYER_DATA     "./assets/perso/player.min.json"

#define GET_PLAYER(ent) get_entity_value(get_entity_from_id(ent, 0.0))
#define GET_PLAYER_ENT(ent) get_entity_from_id(ent, 0.0)

#define GET_ENEMY(ent) get_entity_value(get_entity_from_id(ent, 0.1))
#define GET_ENEMY_ENT(ent) get_entity_from_id(ent, 0.1)

#define MOVE_LEFT           0
#define MOVE_UP             1
#define MOVE_RIGHT          2
#define MOVE_DOWN           3

#define NOT_ACTIVE_TRIGGER  0
#define ACTIVE_TRIGGER      1

#define BOSS_IDX            2

static const int MOVE_SPEED = 600;
static const int MOVE_PNJ_SPEED = 150;

typedef enum location {
    FOREST,
    CAVE,
    CITY
} location_e;

typedef enum trigger_type {
    GO,
    GET,
    FIGHT,
    DISCUSS
} trigger_type_e;

typedef struct trigger_action {
    char const *key;
    void (*callback)();
} trigger_action_t;

typedef struct trigger {
    trigger_type_e trigger_type;
    sfFloatRect area;
    sfVector2f spawn;
    location_e new_map;
    char *name_item;
    struct entity_t *enemy;
    img_t *activity_img[2];
    bool activate;
    void (*callback)();
} trigger_t;

typedef enum move_type {
    VERTICAL,
    HORIZONTAL
} move_type_e;

typedef struct health
{
    int current_health;
    int max_health;
} health_t;

typedef struct pnj_move {
    move_type_e type;
    float delay;
    float curr_time;
    bool reverse;
} pnj_move_t;

typedef struct pnj
{
    char *name;
    img_t *sheet;
    sfFloatRect collision_mask;
    sfVector2f pos;
    sfVector2f move;
    pnj_move_t ia;
    list_t *animations;
    char *curr_animation;
    char **dialogs;
    trigger_t *trigger;
} pnj_t;

typedef struct experience
{
    int curr_xp;
    int max_xp;
    int lvl;
} exp_t;

typedef struct player
{
    img_t *sheet;
    int attck;
    sfFloatRect collision_mask;
    sfVector2f pos;
    sfVector2f move;
    health_t health;
    char *name;
    list_t *animations;
    char *curr_animation;
    list_t *bag;
    exp_t exp;
    struct quest_t **quests;
} player_t;

typedef struct enemy
{
    int attck;
    char *name;
    img_t *sheet;
    sfVector2f rect;
    health_t health;
    list_t *animations;
    char *curr_animation;
} enemy_t;

typedef struct map_t map_t;
struct map_t
{
    sfVector2f pos;
    sfVector2u size;
    img_t *img;
    label_t  *action_lbl;
    sfFloatRect *collision_masks;
    float *pnj_ids;
    location_e loc;
    int nb_ids;
    int nb_masks;
    trigger_t **triggers;
    void (*interact)();
    void *to_interact_with;
    trigger_t *selected_trigger;
    list_t *items;
};

typedef enum entity_type
{
    PNJ_ENT = 0,
    PLAYER_ENT = 1,
    ENEMY_ENT = 2
} entity_type_e;

typedef enum id_type
{
    BRANCH_ID_TYPE,
    ENTITY_ID_TYPE,
} id_type_e;

typedef union entity
{
    enemy_t *enemy;
    player_t *player;
    pnj_t *pnj;
} entity_u;

typedef struct entity_t
{
    entity_type_e type;
    float entity_id;
    entity_u entity_value;
} entity_t;

/* PLAYER */

player_t *create_player_from_json(char const *filepath);
exp_t get_exp_from_object(json_object_t *obj, char const *key);
sfFloatRect get_mask_from_obj(json_object_t *obj, char const *key,
sfVector2f pos);
sfIntRect get_int_rect_from_object(json_object_t *obj, char const *key);
sfVector2f get_position_from_object(json_object_t *obj, char const *key);
health_t get_health_from_object(json_object_t *obj, char const *key);
sfIntRect *load_frames_anim(json_array_t *arr_frames);
int add_animation_from_json(list_t **animations, json_array_t arr, int index);
list_t *load_animations(json_object_t *obj, char const *key);

int valid_quest(struct quest_t *quest, player_t *player, location_e e);
void check_validation_quests(player_t *player, location_e e);
void draw_player(player_t *player, sfRenderWindow *window);
player_t *change_position(player_t *player, sfVector2f new_pos);
void set_anim_player(player_t *obj, char *tag_anim, char *switch_after);
void player_destroy(player_t *player);

/* MAP */

map_t *create_map(char const *map_sprite, char const *json_data, list_t **ent);
map_t *create_map_from_type(location_e type, list_t **entities);
void map_destroy(map_t *map);
int load_map_data(map_t *map, char const *json_path, list_t **entities);
void draw_map(map_t *map, sfRenderWindow *window);
sfFloatRect *get_masks(json_array_t *j_array);
bool collide_with_walls(player_t *player, map_t *map, float dt);
bool collide_with_pnjs(
    player_t *player,
    map_t *map,
    list_t **entities,
    float dt
);
bool collide_with_player(
    pnj_t *pnj,
    list_t **entities,
    float dt
);
bool collide_with_walls_pnj(pnj_t *pnj, map_t *map, float dt);

/* PNJ */

pnj_t *create_pnj_from_json(json_value_t *pnj_obj);
void draw_pnj(pnj_t *pnj, sfRenderWindow *window);
void set_anim_pnj(pnj_t *obj, char *tag_anim, char *switch_after);
pnj_t *update_pnj(pnj_t *pnj, list_t **entities, map_t *map, float dt);
void move_pnjs(list_t *pnjs, sfClock *clock);

/* ENEMY */

enemy_t *create_enemy_from_json(json_value_t *j_value);
void destroy_enemy(enemy_t *enemy);
void set_anim_enemy(enemy_t *obj, char *tag_anim, char *switch_after);
void draw_enemy(enemy_t *enemy, sfRenderWindow *window);
entity_t *get_random_enemy(location_e loc);
entity_t *get_boss(location_e loc);

/* Manage entities */

void move(entity_t *ent, sfVector2f off);

int take_id(id_type_e type_id, long double id);
float create_id(float id_branch, float id_entity_pos);

void draw_entity(entity_t *ent, sfRenderWindow *window);
void draw_entities(list_t **entities, sfRenderWindow *window);
entity_u create_entity_from_type(entity_type_e type_entity, void *value);
entity_t *create_entity(entity_type_e type, void *entity_value);
float add_entity(list_t *entity_tab[], entity_t *entity, unsigned int bid);
void *get_entity_value(entity_t *entity);
void destroy_entity(entity_t *entity);
void animate_entities(list_t **entities, sfClock *clock);

void add_entity_branch(
list_t *tab_entity[], list_t *new_branch, unsigned int type_branch);
entity_t *get_entity_from_id(list_t *tab_entity[], float target_id);

static const sfVector2f MOVES[] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

/* TRIGGER */

void init_trigger_spawn(trigger_t *trigger, json_object_t *obj);
void init_trigger_discuss(trigger_t *trigger);
void init_trigger_get_item(trigger_t *trigger, json_object_t *obj);
void init_trigger_fight(trigger_t *trigger);

trigger_t *create_trigger(json_object_t *data);
void destroy_trigger(trigger_t *trigger);
void update_triggers(list_t *pnjs, map_t *map, player_t *player);
void draw_trigger(trigger_t *trigger, sfRenderWindow *window);
bool check_trigger_pnjs(list_t *pnjs, map_t *map, player_t *player);
bool check_trigger_map(map_t *map, player_t *player);

static const trigger_action_t TRIGGER_ACTIONS[] = {
    {"GO", init_trigger_spawn},
    {"DISCUSS", init_trigger_discuss},
    {"GET", init_trigger_get_item},
    {"FIGHT", init_trigger_fight}
};
static const int NB_TRIGGER_ACTIONS =
        sizeof(TRIGGER_ACTIONS) /
        sizeof(trigger_action_t);

#endif