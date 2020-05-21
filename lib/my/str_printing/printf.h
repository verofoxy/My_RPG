/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** printf.h
*/

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#define CHECK_BUFFER(buf) if (m_strlen(buf) == 1024) {\
    m_putstr(buf); \
    CLEAR_BUFF(buf) }
#define CLEAR_BUFF(buf) m_memset(buf, 0, 1024); \
    len_buf = 0;


int m_putchar(char c);
int m_putstr(char const *str);
int m_put_nbr(int nb);
int m_put_double(double nb);

#endif