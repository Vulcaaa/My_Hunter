/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** main file
*/

#include "include/my.h"

void animation_duck2(main_t *e)
{
    sfVector2f vec = sfSprite_getPosition(e->m2->sprit);

    sfSprite_setPosition(e->m2->sprit, (sfVector2f){vec.x + e->m2->sp, vec.y});
    sfSprite_setOrigin(e->m2->sprit, e->m2->origin);
    sfSprite_setRotation(e->m2->sprit, e->m2->orientation);
    e->m2->orientation += e->m2->sp_rotat;
    sfRenderWindow_setMouseCursorVisible(e->window, sfFalse);
    e->m2->h_b = sfSprite_getGlobalBounds(e->m2->sprit);
}

void animation_expl2(main_t *e)
{
    if (e->m2->is_dead == false) {
        return;
    }
    e->m2->time = sfClock_getElapsedTime(e->m2->clock);
    e->m2->seconds = e->m2->time.microseconds / 1000000.0;
    if (e->m2->seconds >= 0.03) {
        e->m2->rect_mete.left += 102;
        sfClock_restart(e->m2->clock);
        if (e->m2->rect_mete.left >= 102 * 40) {
            e->m2->is_dead = false;
            e->m2->rect_mete.left = 0;
        }
    }
    sfSprite_setPosition(e->m2->sprite_m, e->m2->pos_expl);
    sfSprite_setTextureRect(e->m2->sprite_m, e->m2->rect_mete);
    sfRenderWindow_drawSprite(e->window, e->m2->sprite_m, NULL);
}

void kill2_function(main_t *e)
{
    e->m2->random_pos_y = rand() % 780;
    if (sfFloatRect_contains(&e->m2->h_b, e->event->x, e->event->y)) {
        sfSound_play(e->event->sound_ex);
        e->m2->pos_expl.x = e->event->event.mouseButton.x - 100;
        e->m2->pos_expl.y = e->event->event.mouseButton.y - 130;
        e->m2->vec_kill = (sfVector2f) {-100, e->m2->random_pos_y};
        sfSprite_setPosition(e->m2->sprit, e->m2->vec_kill);
        e->m2->is_dead = true;
        set_score(e);
    }
}

void duck2_reach_earth(main_t *e)
{
    e->m2->random_pos_y = rand() % 780;
    if (sfFloatRect_intersects(&e->m2->e_h_b, &e->m2->h_b, &e->m2->limit_m)) {
        e->m2->vec_kill = (sfVector2f) {-200, e->m2->random_pos_y};
        sfSprite_setPosition(e->m2->sprit, e->m2->vec_kill);
        sfSound_play(e->event->sound_ex);
        e->score->e_life++;
        earth_kill(e);
    }
}
