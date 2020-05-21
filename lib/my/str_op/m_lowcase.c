/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_lowcase.c
*/

#include <stdbool.h>

bool is_upcase(char c);

char *m_lowcase(char *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (is_upcase(s[i]))
            s[i] += 32;
    }
    return s;
}