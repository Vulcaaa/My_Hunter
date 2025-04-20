/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** ok
*/

#include "./include/my.h"

int my_put_nbr(int nb)
{
    int count = 0;
    int divisor = 1;
    int digit = 0;

    if (nb == -2147483647 - 1)
        return write(1, "-2147483648", 11);
    if (nb < 0) {
        count = my_putchar('-');
        nb = -nb;
    }
    while (nb / divisor >= 10) {
        divisor *= 10;
        count++;
    }
    while (divisor > 0) {
        digit = (nb / divisor) % 10;
        my_putchar(digit + '0');
        divisor /= 10;
    }
    return count;
}
