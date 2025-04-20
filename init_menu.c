/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** ini m3
*/

#include "include/my.h"

void init_menu(main_t *e)
{
    e->menu = malloc(sizeof(menu_t));
    e->menu->texture = sfTexture_createFromFile("ressources/menu_bg.jpg", NULL);
    e->menu->sprite = sfSprite_create();
    sfSprite_setTexture(e->menu->sprite, e->menu->texture, sfFalse);
    e->menu->scale = (sfVector2f) {1.0, 1.0};
    sfSprite_setScale(e->menu->sprite, e->menu->scale);
    e->menu->texture_pp = sfTexture_createFromFile("ressources/pp.png", NULL);
    e->menu->sprite_pp = sfSprite_create();
    sfSprite_setTexture(e->menu->sprite_pp, e->menu->texture_pp, sfFalse);
    e->menu->scale_pp = (sfVector2f) {0.26, 0.26};
    e->menu->pos_pp = (sfVector2f) {700, 820};
    sfSprite_setScale(e->menu->sprite_pp, e->menu->scale_pp);
    sfSprite_setPosition(e->menu->sprite_pp, e->menu->pos_pp);
    e->menu->rect_pp = sfSprite_getGlobalBounds(e->menu->sprite_pp);
    e->menu->game_is_on = sfFalse;
    init_game_over(e);
    init_score(e);
}
