/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_revstr.c
*/

int m_strlen(char const *s);

char *m_revstr(char *str)
{
    int length = m_strlen(str);
    int i = 0;
    char temp = 0;

    for (i = 0; i < length; i++) {
        temp  = *(str + i);
        *(str + i) = *(str + length - 1);
        *(str + length - 1) = temp;
        length--;
    }
    return str;
}
