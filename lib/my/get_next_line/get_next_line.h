/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line.h
*/

#ifndef CPE_GETNEXTLINE_2019_GET_NEXT_LINE_H
#define CPE_GETNEXTLINE_2019_GET_NEXT_LINE_H

#ifndef READ_SIZE
#define READ_SIZE (4096)
#endif

#include <stdbool.h>

char *get_next_line(int fd, bool change_fd);
char *m_strcat_dup(char *dest, char *src);

#endif
