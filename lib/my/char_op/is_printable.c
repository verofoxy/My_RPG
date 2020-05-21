/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** is_printable.c
*/

#include <stdbool.h>

bool is_num(char c);

bool is_alpha(char c);

bool is_special_char(char c);

bool is_printable(char c)
{
    return (is_num(c) || is_alpha(c) || is_special_char(c));
}