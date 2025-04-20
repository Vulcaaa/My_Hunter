/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** earth life
*/

#include "include/my.h"

void earth_kill(main_t *e)
{
    if (e->score->e_life == 1) {
        e->score->rect_life.width -= 35;
        sfSprite_setTextureRect(e->score->sprite, e->score->rect_life);
        return;
    }
    if (e->score->e_life == 2) {
        e->score->rect_life.width -= 25;
        sfSprite_setTextureRect(e->score->sprite, e->score->rect_life);
        return;
    }
    if (e->score->e_life == 3) {
        e->score->rect_life.width -= 20;
        sfSprite_setTextureRect(e->score->sprite, e->score->rect_life);
        game_over(e);
    }
}
