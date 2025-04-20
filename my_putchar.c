/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** ok
*/

#include "./include/my.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}
