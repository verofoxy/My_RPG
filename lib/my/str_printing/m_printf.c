/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** m_printf.c
*/

#include "../my.h"
#include "printf.h"
#include <stdbool.h>

bool check_flags2(char const *str, va_list args, int *pos)
{
    switch (str[*pos + 1]) {
        case 'd' :
            m_put_nbr(va_arg(args, int));
            break;
        case 'i' :
            m_put_nbr(va_arg(args, int));
            break;
        case 'f' :
            m_put_double(va_arg(args, double));
            break;
        default:
            m_putchar(str[*pos]);
            m_putchar(str[*pos + 1]);
    }
}

void check_flags(char const *str, va_list args, int *pos)
{
    bool find = false;
    switch (str[*pos + 1]) {
        case 'c' :
            m_putchar((char) va_arg(args, int));
            break;
        case 's' :
            m_putstr(va_arg(args, char const *));
            break;
        case '%' :
            break;
        default:
            find = check_flags2(str, args, pos);
    }
    (*pos)++;
}

int m_printf(char const *str, ...)
{
    char buffer[1025];
    int i = 0, len_buf = 0;
    va_list args;

    va_start(args, str);
    m_memset(buffer, 0, 1025);
    for (i = 0; str[i]; i++) {
        if (str[i] != '%') {
            CHECK_BUFFER(buffer)
            buffer[len_buf++] = str[i];
        } else {
            m_putstr(buffer);
            CLEAR_BUFF(buffer)
            check_flags(str, args, &i);
        }
    }
    if (m_strlen(buffer) > 0)
        m_putstr(buffer);
    va_end(args);
    return 0;
}