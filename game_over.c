/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** game over function
*/

#include "include/my.h"

void game_over(main_t *e)
{
    e->g_o->is_over = sfTrue;
    e->m->sp = 0;
    e->m2->sp = 0;
    e->m3->sp = 0;
    e->m->sp_rotat = 0;
    e->m2->sp_rotat = 0;
    e->m3->sp_rotat = 0;
    sfRenderWindow_setMouseCursorVisible(e->window, sfTrue);
}
