/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_putstr.c
*/

#include <unistd.h>

int m_strlen(char const *str);

int m_putstr(char const *str)
{
    if (!str)
        write(1, "(null) ", 7);
    else
        write(1, str, m_strlen(str));
    return 0;
}