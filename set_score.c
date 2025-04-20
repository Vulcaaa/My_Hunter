/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** score manage
*/

#include "include/my.h"

void set_score(main_t *e)
{
    e->score->score_nbr++;
    my_strcpy(e->score->str, "score : ");
    e->score->str = my_strcat_int(e->score->str, e->score->score_nbr);
    sfText_setString(e->score->text, e->score->str);
}
