/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** m_putchar.c
*/

#include <unistd.h>

int m_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}