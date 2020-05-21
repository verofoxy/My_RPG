/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_str_is_alpha.c
*/

#include <stdbool.h>

bool is_alpha(char c);

bool m_str_isalpha(char const *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (!is_alpha(s[i]))
            return false;
    }
    return true;
}