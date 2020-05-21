/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** is_num.c
*/

#include <stdbool.h>

bool is_num(char c)
{
    return (c >= 48 && c <= 57)
    ? true
    : false;
}