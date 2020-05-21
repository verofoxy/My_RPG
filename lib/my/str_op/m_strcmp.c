/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_strcmp.c
*/

int m_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    if (s1[i] - s2[i] == 0)
        return (s1[i] - s2[i]);
    else if (s1[i] - s2[i] < 0)
        return (-1);
    else
        return (1);
}