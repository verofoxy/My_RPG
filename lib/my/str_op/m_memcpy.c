/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** m_memcpy.c
*/

void *m_memcpy(void *dst, void *src, unsigned int size)
{
    char *cdst = (char *) dst;
    char *csrc = (char const *) src;

    while (size) {
        *(cdst++) = *(csrc++);
        size--;
    }
    return dst;
}