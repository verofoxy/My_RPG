/*
** EPITECH PROJECT, 2020
** rtyhj
** File description:
** hjklm
*/

#include "system.h"
#include "rpg.h"
#include "keyboard_management.h"
#include "my.h"

void get_key_pressed(sfKeyCode code, game_sys_t *sys)
{
    int i = 0;

    for (i = 0; i < nbr_keys; i++) {
        if (code == KEY_PRESSED[i].code)
            break;
    }
    if (i >= nbr_keys)
        return;
    KEY_PRESSED[i].callback(sys);
}
