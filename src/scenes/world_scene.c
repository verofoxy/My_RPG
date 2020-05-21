/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** word_scene.c
*/

#include "rpg.h"
#include "image.h"
#include "window.h"
#include "camera.h"
#include "entity.h"
#include "scene.h"
#include "keyboard_management.h"
#include "particle.h"
#include "menus.h"
#include "end.h"
#include "sound.h"

void game_event(game_sys_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(sys->window);
            change_scene(sys, EXIT_SCENE);
            break;
        }
        if (event.type == sfEvtKeyPressed)
            get_key_pressed(event.key.code, sys);
    }
}

void draw_world(game_sys_t *sys)
{
    int i = 0;

    clear_window(sys->window, sfBlack);
    draw_map(sys->map, sys->window);
    draw_entities(sys->entities, sys->window);
    for (i = 0; sys->map->triggers[i]; i++)
        draw_trigger(sys->map->triggers[i], sys->window);
    particles_effect_from_pos(
        get_img_pos(
            find_player_for_set_particle(sys->entities)->sheet
        ),
        FREQUENCY(10),
        PATH_PART_EYES,
        sys->window
    );
    display_window(sys->window);
}

void update_world(game_sys_t *sys)
{
    bool run_away = false;

    move_pnjs(sys->entities[PNJ_BRANCH], sys->clock);
    if (spawn_monster(sys)) {
        change_scene(sys, FIGHT_SCENE);
        MUSIC_ACTIVED(sound_handle(sys, ENV, 0, PAUSE));
        run_fight(sys, &run_away);
    }
    update_entities(sys->map, sys->entities, sys);
    update_camera(sys->camera, GET_PLAYER(sys->entities));
    apply_camera_map(sys->camera, sys->map);
    animate_entities(sys->entities, sys->clock);
    apply_cam_on_entities(sys->camera, sys->entities);
    update_triggers(
        sys->entities[PNJ_BRANCH], sys->map,
        GET_PLAYER(sys->entities)
    );
    check_validation_quests(GET_PLAYER(sys->entities), sys->map->loc);
    check_end(sys, ((player_t *) GET_PLAYER(sys->entities))->quests);
}

void world_scene(game_sys_t *sys)
{
    MUSIC_ACTIVED(sound_handle(sys, ENV, 10, PLAY));
    MUSIC_ACTIVED(sound_handle(sys, ENV, 10, VOLUME));

    while (is_open_window(sys->window) && sys->actual_scene == WORLD_SCENE) {
        game_event(sys);
        if (sys->actual_scene == EXIT_SCENE)
            break;
        draw_world(sys);
        update_world(sys);
        sfClock_restart(sys->clock);
    }
    sound_handle(sys, ENV, 50, STOP);
}
