/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_memset.c
*/

void m_memset(void *pointer, int value, int count)
{
    char *p = (char *) pointer;
    for (int i = 0; i < count; i += 1) {
        p[i] = (char) value;
    }
}