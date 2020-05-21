/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_strdup.c
*/

#include <stdlib.h>

int m_strlen(char const *s);

char *m_strcpy(char *dest, char const *src);

void m_memset(void *pointer, int value, int count);

char *m_strdup(char const *src)
{
    int len = m_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));

    if (!dest || !src)
        return NULL;
    m_memset(dest, '\0', len + 1);
    m_strcpy(dest, src);
    return dest;
}