/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_strcat.c
*/

int m_strlen(char const *s);

char *m_strcat(char *dest, char const *src)
{
    int i = m_strlen(dest);

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}