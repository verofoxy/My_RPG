/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** my_str_isupper.c
*/

#include <stdbool.h>

bool is_upcase(char c);

bool m_str_isupper(char const *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (!is_upcase(s[i]))
            return false;
    }
    return true;
}