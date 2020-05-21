/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_upcase.c
*/

#include <stdbool.h>

bool is_lowcase(char c);

char *m_upcase(char *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (is_lowcase(s[i]))
            s[i] -= 32;
    }

    return s;
}
