/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_str_isnum.c
*/

#include <stdbool.h>

bool is_num(char c);

bool m_str_isnum(char const *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (!is_num(s[i]))
            return false;
    }
    return true;
}