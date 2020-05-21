/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** my_str_split.c
*/

#include <stdlib.h>
#include "my.h"

void splitstr_destroy(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
}

int len_tab(char **tab)
{
    int i = 0;

    for (i = 0; tab[i]; i++);
    return i;
}

static int get_nb_words(char *str, char to_find)
{
    int count = 0;
    int no_w = 1;
    int i;

    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] != to_find)
            no_w = 0;
        if (str[i] == to_find && !no_w) {
            count += 1;
            no_w = 1;
        }
    }
    return ((str[i - 1] != to_find) ? count + 1: count);
}

static void move_cursor(char *str, char to_find, int *j)
{
    while (str[*j] == to_find && str[*j] != '\0')
        *j += 1;
}

char **m_str_split(char *str, char to_find)
{
    char *tmp;
    int len_word;
    int j = 0, h = 0;
    int nb_words = get_nb_words(str, to_find);
    int cursor;
    char **words = malloc(sizeof(char *) * (nb_words + 1));

    for (int i = 0; i < nb_words; i += 1) {
        move_cursor(str, to_find, &j);
        cursor = j;
        for (len_word = 0; str[j] != to_find && str[j] != '\0'; j += 1)
            len_word += 1;
        tmp = malloc(sizeof(char) * (len_word + 1));
        for (h = 0; cursor < j; cursor += 1, h += 1)
            tmp[h] = str[cursor];
        tmp[h] = '\0';
        words[i] = tmp;
    }
    words[nb_words] = NULL;
    return (words);
}