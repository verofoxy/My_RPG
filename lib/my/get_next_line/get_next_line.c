/*
** EPITECH PROJECT, 2019
** GetNextLine
** File description:
** get_next_line.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdbool.h>

char *my_strdup(char const *src)
{
    int len;

    for (len = 0; src[len] != '\0'; len += 1);
    char *dest = malloc(sizeof(char) * len + 1);

    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = 0;
    return dest;
}

int find_return(char const *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i += 1) {
        if (buffer[i] == '\n')
            return i;
    }
    return -1;
}

char *get_line(char *buffer, char *old, char **remaining, char *result)
{
    int offset_max, len_buffer;
    if (old != NULL)
        buffer = m_strcat_dup(old, buffer);
    for (len_buffer = 0; buffer[len_buffer] != '\0'; len_buffer += 1);
    offset_max = find_return(buffer);
    if (offset_max >= 0) {
        result = malloc(sizeof(char) * offset_max + 1);
        if (buffer[offset_max + 1] != '\0')
            *remaining = my_strdup(buffer + offset_max + 1);
        else
            *remaining = NULL;
    } else {
        result = malloc(sizeof(char) * (len_buffer + 1));
        *remaining = NULL;
    }
    if (result == NULL)
        return NULL;
    len_buffer = (offset_max >= 0) ? offset_max : len_buffer;
    for (int i = 0; i < len_buffer; result[i] = buffer[i], i += 1);
    result[len_buffer] = '\0';
    return result;
}

char *rec_line(char *buffer, int fd, int j)
{
    int bytes_read = 0;
    char tmp[READ_SIZE + 1];

    for (int i = 0; i < READ_SIZE + 1; i += 1)
        tmp[i] = '\0';
    bytes_read = read(fd, tmp, READ_SIZE);
    buffer = m_strcat_dup(buffer, tmp);
    if (buffer == NULL)
        return NULL;
    if (find_return(buffer) == -1 && bytes_read > 0)
        buffer = rec_line(buffer, fd, ++j);
    if (bytes_read <= 0 && j == 0)
        return NULL;
    return buffer;
}

char *get_next_line(int fd, bool change_fd)
{
    char *buffer = NULL;
    char *result = NULL;
    static char *remaining = NULL;

    if (fd == -1)
        return NULL;
    if (change_fd && remaining) {
        free(remaining);
        remaining = NULL;
    }
    buffer = rec_line(NULL, fd, 0);
    if (buffer == NULL && remaining == NULL)
        return NULL;
    result = get_line(buffer, remaining, &remaining, result);
    return result;
}