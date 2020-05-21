/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_strlen.c
*/

int m_strlen(char const *str)
{
    int len = 0;

    for (len = 0; str[len] != '\0'; len++);
    return len;
}