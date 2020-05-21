/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** player.c
*/

#include "rpg.h"
#include "camera.h"
#include "image.h"
#include "entity.h"
#include "animation.h"
#include "sound.h"

player_t *change_position(player_t *player, sfVector2f new_pos)
{
    player->pos.x = new_pos.x;
    player->pos.y = new_pos.y;
    player->collision_mask.left = new_pos.x + 10;
    player->collision_mask.top = new_pos.y + 20;
    set_img_position(player->sheet, player->pos);
    return player;
}

player_t *update_player(
    player_t *player,
    map_t *map,
    list_t **entities,
    game_sys_t *sys
)
{
    float dt = sfTime_asSeconds(sfClock_getElapsedTime(sys->clock));

    if (collide_with_walls(player, map, dt) == false
    && collide_with_pnjs(player, map, entities, dt) == false) {
        player->pos.x += (player->move.x * MOVE_SPEED * dt);
        player->pos.y += (player->move.y * MOVE_SPEED * dt);
        player->collision_mask.left = player->pos.x + 10;
        player->collision_mask.top = player->pos.y + 20;
        set_img_position(player->sheet, player->pos);
        SFX_ACTIVED(sound_handle(sys, MOVE, 30, PLAY));
        SFX_ACTIVED(sound_handle(sys, MOVE, 30, VOLUME));
    }
    player->move = (sfVector2f) {0, 0};
    return player;
}

void draw_player(player_t *player, sfRenderWindow *window)
{
    draw_img(player->sheet, window);
}