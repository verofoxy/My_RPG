/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** is_alpha.c
*/

#include <stdbool.h>

bool is_alpha(char c)
{
    return ((c >= 65 && c <= 90) ||
    (c >= 97 && c <= 122))
    ? true
    : false;
}