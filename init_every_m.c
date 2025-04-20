/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** main file
*/

#include "my.h"

void init_m1_bis(main_t *e)
{
    e->m = malloc(sizeof(m_t));
    e->m->texture = sfTexture_createFromFile("./ressources/mete.png", NULL);
    e->m->sprite = sfSprite_create();
    sfSprite_setTexture(e->m->sprite, e->m->texture, sfFalse);
}

void init_m1(main_t *e)
{
    init_m1_bis(e);
    e->m->vec = (sfVector2f) {-50, 700};
    e->m->vec_kill = (sfVector2f){-200, 400};
    sfSprite_setPosition(e->m->sprite, (sfVector2f) e->m->vec);
    e->m->scale = (sfVector2f) {1.1, 1.1};
    sfSprite_setScale(e->m->sprite, e->m->scale);
    e->m->clock = sfClock_create();
    e->m->e_h_b = (sfFloatRect) {1900, 0, 220, 1080};
    e->m->limit_m = (sfFloatRect) {1900, 0, 220, 1080};
    e->m->origin = (sfVector2f) {150, 100.0};
    e->m->orientation = 190.0;
    e->m->is_dead = false;
    e->m->sprite_m = sfSprite_create();
    e->event->texture = sfTexture_createFromFile("ressources/explosion.png", NULL);
    sfSprite_setTexture(e->m->sprite_m, e->event->texture, sfFalse);
    e->m->rect_mete = (sfIntRect) {0, 0, 102, 102};
    e->m->scale_expl = (sfVector2f) {2, 2};
    sfSprite_setScale(e->m->sprite_m, e->m->scale_expl);
    e->m->sp = 0.09;
    e->m->sp_rotat = 0.02;
}

void init_m2_bis(main_t *e)
{
    e->m2->sprite_m = sfSprite_create();
    sfSprite_setTexture(e->m2->sprite_m, e->event->texture, sfFalse);
    e->m2->rect_mete = (sfIntRect) {0, 0, 102, 102};
    e->m2->scale_expl = (sfVector2f) {2, 2};
    sfSprite_setScale(e->m2->sprite_m, e->m2->scale_expl);
    e->m2->sp = 0.08;
    e->m2->sp_rotat = 0.018;
}

void init_m2(main_t *e)
{
    e->m2 = malloc(sizeof(m2_t));
    e->m2->texture = sfTexture_createFromFile("./ressources/mete.png", NULL);
    e->m2->sprit = sfSprite_create();
    sfSprite_setTexture(e->m2->sprit, e->m2->texture, sfFalse);
    e->m2->vec = (sfVector2f){-100, 190};
    e->m2->vec_kill = (sfVector2f){-250, 400};
    sfSprite_setPosition(e->m2->sprit, (sfVector2f) e->m2->vec);
    e->m2->scale = (sfVector2f) {0.6, 0.6};
    sfSprite_setScale(e->m2->sprit, e->m2->scale);
    e->m2->clock = sfClock_create();
    e->m2->e_h_b = (sfFloatRect) {1900, 0, 220, 1080};
    e->m2->limit_m = (sfFloatRect) {1900, 0, 220, 1080};
    e->m2->origin = (sfVector2f) {150, 100.0};
    e->m2->orientation = 200.0;
    e->m2->is_dead = false;
    init_m2_bis(e);
}

void init_m3(main_t *e)
{
    e->m3 = malloc(sizeof(m3_t));
    e->m3->texture = sfTexture_createFromFile("./ressources/mete.png", NULL);
    e->m3->spri = sfSprite_create();
    sfSprite_setTexture(e->m3->spri, e->m3->texture, sfFalse);
    e->m3->vec = (sfVector2f){-250, 80};
    e->m3->vec_kill = (sfVector2f){-200, 400};
    sfSprite_setPosition(e->m3->spri, (sfVector2f) e->m3->vec);
    e->m3->scale = (sfVector2f) {0.4, 0.4};
    sfSprite_setScale(e->m3->spri, e->m3->scale);
    e->m3->clock = sfClock_create();
    e->m3->e_h_b = (sfFloatRect) {1900, 0, 220, 1080};
    e->m3->limit_m = (sfFloatRect) {1900, 0, 220, 1080};
    e->m3->origin = (sfVector2f) {150, 100.0};
    e->m3->orientation = 30.0;
    e->m3->is_dead = false;
    init_m3_bis(e);
}
