/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** system.h
*/

#ifndef MUL_MY_RPG_2019_SYSTEM_H
#define MUL_MY_RPG_2019_SYSTEM_H

#include <SFML/Graphics.h>
#include "json_parser.h"
#include "list.h"
#include "entity.h"
#include "camera.h"

#define TITLE           "Princess of Persia"
#define MAIN_FONT       "./assets/font/indie.ttf"
#define BOX_BCK         "./assets/img/dialogbox.png"
#define ACTION_TXT      "Press e to interact"

#define DIALOG_SPEED    2

#define FADE_SPEED      0.5
#define FADE_MAX        255

typedef struct dialog {
    img_t *background;
    float curr_time;
    float curr_index;
    char draw_txt[255];
    char *sentence;
    label_t *name;
    label_t *label;
} dialog_t;

typedef struct settings {
    bool sfx_allowed;
    bool music_allowed;
} settings_t;

typedef struct game_system {
    int actual_scene;
    list_t **entities;
    list_t *sounds;
    sfRenderWindow *window;
    sfClock *clock;
    map_t *map;
    camera_t *camera;
    dialog_t *dialog_box;
    settings_t settings;
    bool paused;
} game_sys_t;

game_sys_t *init_game(list_t **entities);
void destroy_game(game_sys_t *sys);

void change_scene(game_sys_t *sys, int new_scene);
void (*get_scene(int id))(game_sys_t *);


bool spawn_monster(game_sys_t *sys);

void change_world(game_sys_t *sys, map_t *map, trigger_t *selected_trigger);
void get_object(game_sys_t *sys, map_t *map, trigger_t *trigger);

player_t *update_player(
    player_t *player,
    map_t *map,
    list_t **entities,
    game_sys_t *sys
);
void update_entity(entity_t *ent, map_t *map, list_t **entities,
struct game_system *s);
void update_entities(
        map_t *map,
        list_t **entities,
        game_sys_t *s
);

dialog_t *init_dialog(char const *back);
void draw_dialog(dialog_t *dialog, sfRenderWindow *window);
int get_random_dialog(dialog_t *dialog, pnj_t *pnj);
void update_dialog(dialog_t *dialog, sfClock *clock);
void destroy_dialog(dialog_t *dialog);

sfRectangleShape *init_shader(void);
void update_fade_in(sfRectangleShape *shader, sfClock *clock, float *time);
void update_fade_out(sfRectangleShape *shader, sfClock *clock, float *time);

#endif
