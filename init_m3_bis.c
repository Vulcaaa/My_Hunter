/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** ini m3
*/

#include "include/my.h"

void init_m3_bis(main_t *e)
{
    e->m3->sprite_m = sfSprite_create();
    sfSprite_setTexture(e->m3->sprite_m, e->event->texture, sfFalse);
    e->m3->rect_mete = (sfIntRect) {0, 0, 102, 102};
    e->m3->scale_expl = (sfVector2f) {2, 2};
    sfSprite_setScale(e->m3->sprite_m, e->m3->scale_expl);
    e->m3->sp = 0.1;
    e->m3->sp_rotat = 0.03;
}
