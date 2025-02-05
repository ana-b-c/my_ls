/*
** EPITECH PROJECT, 2024
** lib.c
** File description:
** lib
*/
#include "my_lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return 0;
}

char *my_strcat(char *dest, const char *src)
{
    char *ptr;
    int dest_length;

    dest_length = my_strlen(dest);
    ptr = dest + dest_length;
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}
