/*
** EPITECH PROJECT, 2024
** nbr_to str
** File description:
** ok
*/

#include "include/my.h"

int my_nbr_to_string(char *str, int nb)
{
    int count = 0;
    int divisor = 1;
    int digit = 0;
    int i = 0;

    while (nb / divisor >= 10) {
        divisor *= 10;
        count++;
    }
    for (; divisor > 0; i++) {
        digit = (nb / divisor) % 10;
        str[i] = digit + '0';
        divisor /= 10;
    }
    str[i] = '\0';
    return 0;
}
