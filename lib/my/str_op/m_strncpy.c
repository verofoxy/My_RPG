/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_strncpy.c
*/

char *m_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (int x = 0; dest[x] != 0; x++)
        dest[x] = 0;
    for (i = 0; src[i] != 0 && i < n; i++)
        dest[i] = src[i];
    dest[i + 1] = 0;
    return dest;
}