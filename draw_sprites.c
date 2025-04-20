/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** draw all sprites
*/

#include "include/my.h"

void difficulty(main_t *e)
{
    if (e->score->score_nbr >= e->diffi->difficulty) {
        e->diffi->difficulty += 25;
        e->m->sp += 0.02;
        e->m2->sp += 0.02;
        e->m3->sp += 0.02;
    }
}

void draw_all_sprites(main_t *e)
{
    sfRenderWindow_drawSprite(e->window, e->bg->sprite, NULL);
    sfRenderWindow_drawSprite(e->window, e->m->sprite, NULL);
    sfRenderWindow_drawSprite(e->window, e->m2->sprit, NULL);
    sfRenderWindow_drawSprite(e->window, e->m3->spri, NULL);
    sfRenderWindow_drawSprite(e->window, e->cursor->sprite, NULL);
    duck_manage(e);
    sfRenderWindow_drawText(e->window, e->score->text, NULL);
    sfRenderWindow_drawText(e->window, e->score_max->text, NULL);
    sfRenderWindow_drawSprite(e->window, e->score->sprite, NULL);
    difficulty(e);
}
