/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** m_getnbr.c
*/

#include <stdbool.h>
#include "my.h"

int m_getnbr(char const *str)
{
    int result = 0, i = 0;
    bool is_neg = 1;

    for (i = 0; str[i] && !is_num(str[i]); i++) {
        is_neg *= str[i] == '-' ? -1 : 1;
    }
    for (; str[i] && is_num(str[i]); i++)
        result = result * 10 + str[i] - '0';
    return result * is_neg;
}