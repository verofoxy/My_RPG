/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** is_special_char.c
*/

#include <stdbool.h>

bool is_special_char(char c)
{
    if ((c > 31 && c < 48) ||
    (c > 57 && c < 65) ||
    (c > 90 && c < 97) ||
    (c > 122 && c < 127))
        return true;
    return false;
}