/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_itos.c
*/

#include <stdlib.h>
#include "my.h"

char *m_itos(int i)
{
    char buf[255];
    char *str = NULL;
    int is_neg = (i < 0) ? 1 : 0;
    int nb_char = 0, j = 0;

    i = ABS(i);
    m_memset(buf, '\0', 255);
    if (i == 0) {
        buf[0] = '0';
        return m_strdup(buf);
    }
    for (j = 0; i != 0; j++) {
        buf[j] = NTA(i % 10);
        i /= 10;
    }
    buf[j] = is_neg ? '-' : '\0';
    return m_strdup(m_revstr(buf));
}
