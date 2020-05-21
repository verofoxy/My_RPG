/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** m_strcat_dup.c
*/

#include <stdlib.h>

char *m_strcat_dup(char *dest, char *src)
{
    int len, len2, i;
    char *d = NULL;
    if (src == NULL)
        return dest;
    for (len = 0; dest != NULL && dest[len] != '\0'; len += 1);
    for (len2 = 0; src[len2] != '\0'; len2 += 1);
    d = malloc(sizeof(char) * (len + len2 + 1));
    if (d == NULL)
        return NULL;
    for (i = 0; dest != NULL && dest[i] != 0; d[i] = dest[i], i += 1);
    for (i = 0; src[i] != 0; d[len + i] = src[i], i += 1);
    d[len + len2] = '\0';
    return d;
}