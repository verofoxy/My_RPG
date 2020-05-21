/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_str_isprintable.c
*/

#include <stdbool.h>

bool is_printable(char c);

bool m_str_isprintable(char const *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (!is_printable(s[i]))
            return false;
    }
    return true;
}