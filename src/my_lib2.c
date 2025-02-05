/*
** EPITECH PROJECT, 2024
** lib2.c
** File description:
** lib
*/
#include "my_lib.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
    my_putchar(str[i]);
    i++;
    }
    return 0;
}

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
    }
    dest[i] = '\0';
    return dest;
}
