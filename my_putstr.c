/*
** EPITECH PROJECT, 2024
** Day04
** File description:
** task02
*/

#include "./include/my.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
