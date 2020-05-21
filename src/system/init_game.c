/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_game.c
*/

#include "list.h"
#include "sound.h"
#include "rpg.h"
#include "window.h"
#include "scene.h"

game_sys_t *init_game(list_t **entities)
{
    game_sys_t *sys = malloc(sizeof(game_sys_t));

    CHECK_MALLOC(sys);
    CHECK_MALLOC((sys->window = create_window(
            W_SCREEN, H_SCREEN,
            TITLE, 60
    )));
    CHECK_MALLOC((sys->clock = sfClock_create()));
    sys->actual_scene = MENU_SCENE;
    sys->entities = entities;
    sys->paused = false;
    sys->map = NULL;
    sys->camera = NULL;
    sys->dialog_box = init_dialog(BOX_BCK);
    sys->sounds = set_sound();
    sys->settings = (settings_t) {true, true};
    return sys;
}

void run_game(game_sys_t *sys)
{
    int i = 0;

    intro_forest_scene(sys);
    intro_cave_scene(sys);
    UNEXPECTED_EXIT(sys->map = create_map_from_type(CITY, sys->entities));
    sys->camera = init_camera(sys->map->size.x, sys->map->size.y);
    add_entity(
            sys->entities,
            create_entity(
                    PLAYER_ENT,
                    create_player_from_json(PLAYER_DATA)
            ),
            PLAYER_BRANCH
    );
    world_scene(sys);
    for (i = 0; i < 3; i++)
        list_destroy(&sys->entities[i], destroy_entity);
    camera_destroy(sys->camera);
    list_destroy(&sys->map->items, destroy_item);
    map_destroy(sys->map);
}

void change_world(game_sys_t *sys, map_t *map, trigger_t *selected_trigger)
{
    if (selected_trigger->trigger_type != GO)
        return;
    if (sys->map->loc == selected_trigger->new_map) {
        change_position(GET_PLAYER(sys->entities), selected_trigger->spawn);
        return;
    }
    fade_in(sys);
    list_destroy(&sys->entities[PNJ_BRANCH], destroy_entity);
    sys->map = create_map_from_type(selected_trigger->new_map, sys->entities);
    UNEXPECTED_EXIT(sys->map)
    sys->camera->map_width = sys->map->size.x;
    sys->camera->map_height = sys->map->size.y;
    change_position(GET_PLAYER(sys->entities), selected_trigger->spawn);
    map_destroy(map);
    update_camera(sys->camera, GET_PLAYER(sys->entities));
    apply_camera_map(sys->camera, sys->map);
    apply_cam_on_entities(sys->camera, sys->entities);
    fade_out(sys, WORLD_SCENE);
}