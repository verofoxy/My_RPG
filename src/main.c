/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "sound.h"
#include "rpg.h"
#include "scene.h"

bool is_enable_display(char *env[])
{
    int i = 0;
    char const *keyword = "DISPLAY";
    char **tab = NULL;

    for (i = 0; env[i]; i++) {
        if (m_strncmp(keyword, env[i], m_strlen(keyword)) == 0)
            break;
    }
    if (!env[i])
        return false;
    tab = m_str_split(env[i], '=');
    if (len_tab(tab) != 2) {
        splitstr_destroy(tab);
        return false;
    }
    splitstr_destroy(tab);
    return true;
}

int main(int ac, char *av[], char *env[])
{
    list_t *entities[] = {NULL, NULL, NULL, NULL};
    game_sys_t *sys = NULL;
    void (*new_scene)() = NULL;

    (void) ac;
    (void) av;
    if (!is_enable_display(env))
        return EXEC_FAIL;
    sys = init_game(entities);
    CHECK_NULL(sys)
    while (sys->actual_scene != EXIT_SCENE) {
        new_scene = get_scene(sys->actual_scene);
        if (!new_scene)
            break;
        new_scene(sys);
    }
    reset_all_sound(sys->sounds);
    destroy_game(sys);
}