/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** my.h
*/

#ifndef MYPRINTF_MY_H
#define MYPRINTF_MY_H

#define NTA(x) x + '0'
#define ABS(x) x < 0 ? x * -1 : x

#include <stdbool.h>

bool is_alpha(char c);
bool is_num(char c);
bool is_lowcase(char c);
bool is_upcase(char c);
bool is_printable(char c);
bool is_special_char(char c);

int m_strlen(char const *s);
void m_memset(void *pointer, int value, int count);
char *m_revstr(char *str);
char *m_strcat(char *dest, char const *src);
int m_strcmp(char const *s1, char const *s2);
char *m_strcpy(char *dest, char const *src);
char *m_strdup(char const *src);
int m_strlen(char const *s);
int m_strncmp(char const *s1, char const *s2, int n);
char *m_strncpy(char *dest, char const *src, int n);
char *m_upcase(char *s);
char *m_lowcase(char *s);
int m_getnbr(char const *str);

bool m_str_isalpha(char const *s);
bool m_str_islower(char const *s);
bool m_str_isnum(char const *s);
bool m_str_isprintable(char const *s);
bool m_str_isupper(char const *s);

void splitstr_destroy(char **tab);
int len_tab(char **tab);
char **m_str_split(char *str, char to_find);

int m_putchar(char c);
int m_putstr(char const *str);
int m_put_nbr(int nb);
int m_put_double(double nb);
int m_printf(char const *str, ...);

void *m_memcpy(void *dst, void *src, unsigned int size);
char *m_strcat_dup(char *dest, char *src);
char *get_next_line(int fd, bool change_fd);
char *m_itos(int i);
#endif
