/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** dialog.c
*/

#include <time.h>
#include "rpg.h"
#include "system.h"
#include "window.h"
#include "scene.h"
#include "my.h"

dialog_t *init_dialog(char const *back)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));

    CHECK_MALLOC(dialog)
    dialog->name = create_label(MAIN_FONT, 30, "", sfWhite);
    dialog->label = create_label(MAIN_FONT, 30, "", sfWhite);
    dialog->background = create_image(back, NULL);
    CHECK_MALLOC(dialog->name)
    CHECK_MALLOC(dialog->label)
    CHECK_MALLOC(dialog->background)
    set_img_position(dialog->background, (sfVector2f) {0, 350});
    set_pos_label(dialog->name, (sfVector2f) {100, 420});
    set_pos_label(dialog->label, (sfVector2f) {100, 470});
    m_memset(dialog->draw_txt, '\0', 255);
    dialog->curr_time = 0;
    dialog->curr_index = 0;
    dialog->sentence = NULL;
    return dialog;
}

int get_random_dialog(dialog_t *dialog, pnj_t *pnj)
{
    int length = len_tab(pnj->dialogs);
    int index_dialog = rand() % length;

    dialog->sentence = pnj->dialogs[index_dialog];
    change_text(dialog->name, pnj->name);
    change_text(dialog->label, dialog->sentence);
    return EXEC_SUCCESS;
}

void update_dialog(dialog_t *dialog, sfClock *clock)
{
    dialog->curr_time += sfTime_asSeconds(sfClock_getElapsedTime(clock));
    dialog->curr_index = dialog->curr_time *
    (float) m_strlen(dialog->sentence) / DIALOG_SPEED;
    if (dialog->curr_index >= m_strlen(dialog->sentence)) {
        dialog->curr_index -=
        (dialog->curr_index - (float) m_strlen(dialog->sentence)) + 1;
    }
    m_memset(dialog->draw_txt, '\0', 255);
    m_strncpy(dialog->draw_txt, dialog->sentence, (int) dialog->curr_index + 1);
    change_text(dialog->label, dialog->draw_txt);
}

void draw_dialog(dialog_t *dialog, sfRenderWindow *window)
{
    draw_img(dialog->background, window);
    draw_lbl(dialog->name, window);
    draw_lbl(dialog->label, window);
}

void destroy_dialog(dialog_t *dialog)
{
    image_destroy(dialog->background);
    label_destroy(dialog->label);
    label_destroy(dialog->name);
    free(dialog);
}