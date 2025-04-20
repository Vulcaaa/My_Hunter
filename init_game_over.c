/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** init game over
*/

#include "include/my.h"

void game_is_over_condition(main_t *e)
{
    if (e->g_o->is_over)
        sfRenderWindow_drawSprite(e->window, e->g_o->sprite, NULL);
}

void init_game_over(main_t *e)
{
    e->g_o = malloc(sizeof(game_over_t));
    e->g_o->sprite = sfSprite_create();
    e->g_o->texture = sfTexture_createFromFile("image/game_over.png", NULL);
    sfSprite_setTexture(e->g_o->sprite, e->g_o->texture, sfFalse);
    e->g_o->is_over = sfFalse;
    e->g_o->pos = (sfVector2f) {670, 100};
    sfSprite_setPosition(e->g_o->sprite, e->g_o->pos);
}

void play_game(main_t *e)
{
    e->menu->rect_pp = sfSprite_getGlobalBounds(e->menu->sprite_pp);
    if (sfFloatRect_contains(&e->menu->rect_pp, e->event->x, e->event->y)) {
        e->menu->game_is_on = sfTrue;
    }
}
