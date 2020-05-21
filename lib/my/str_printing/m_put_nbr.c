/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_put_nbr.c
*/

int m_putstr(char const *s);

char *m_revstr(char *str);

void m_memset(void *ptr, int value, int count);

int get_nb_str(int nb, char *buf, int i)
{
    if (nb > 9)
        get_nb_str(nb / 10, buf, i + 1);
    buf[i] = (char) (nb % 10 + 48);
}

int m_put_nbr(int nb)
{
    char buffer[10];
    m_memset(buffer, 0, 10);

    if (nb < 0) {
        nb *= -1;
        m_putstr("-");
    }
    get_nb_str(nb, buffer, 0);
    m_revstr(buffer);
    m_putstr(buffer);
    return 0;
}