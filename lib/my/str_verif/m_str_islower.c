/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_str_islower.c
*/

#include <stdbool.h>

bool is_lowcase(char c);

bool m_str_islower(char const *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (!is_lowcase(s[i]))
            return false;
    }
    return true;
}
