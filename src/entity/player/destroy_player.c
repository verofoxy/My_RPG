/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_player.c
*/

#include "rpg.h"
#include "camera.h"
#include "image.h"
#include "entity.h"
#include "animation.h"
#include "quest.h"

void player_destroy(player_t *player)
{
    image_destroy(player->sheet);
    list_destroy(&player->animations, animation_destroy);
    destroy_quest(player->quests);
    free(player->name);
    free(player);
}