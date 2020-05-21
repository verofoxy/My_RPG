/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_put_double.c
*/

int m_put_nbr(int nb);

int m_putstr(char const *s);

int m_put_double(double nb)
{
    int dec = 0;

    m_put_nbr((int) nb);
    m_putstr(".");
    dec = (int) (nb * 1000000) % 1000000;
    dec *= dec < 0 ? -1 : 1;
    m_put_nbr(dec);
}