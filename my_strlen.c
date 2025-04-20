/*
** EPITECH PROJECT, 2024
** mathys
** File description:
** my
*/

#include "include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
