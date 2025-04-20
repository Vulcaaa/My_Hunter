/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** main file
*/

#include "./include/my.h"

char *my_strcat_int(char *dest, int nbr)
{
    int i = 0;
    char *str_nb = malloc(sizeof(char) * 4);

    my_nbr_to_string(str_nb, nbr);
    for (; dest[i] != '\0'; i++);
    for (int j = 0; str_nb[j] != '\0'; j++) {
        dest[i] = str_nb[j];
        i++;
    }
    return dest;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
