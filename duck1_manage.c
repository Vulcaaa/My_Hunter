/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** main file
*/

#include "include/my.h"

void animation_duck(main_t *e)
{
    sfVector2f vec = sfSprite_getPosition(e->m->sprite);

    sfSprite_setPosition(e->m->sprite, (sfVector2f){vec.x + e->m->sp, vec.y});
    sfSprite_setOrigin(e->m->sprite, e->m->origin);
    sfSprite_setRotation(e->m->sprite, e->m->orientation);
    e->m->orientation += e->m->sp_rotat;
    sfRenderWindow_setMouseCursorVisible(e->window, sfFalse);
    e->m->h_b = sfSprite_getGlobalBounds(e->m->sprite);
}

void animation_expl(main_t *e)
{
    if (!e->m->is_dead)
        return;
    e->m->time = sfClock_getElapsedTime(e->m->clock);
    e->m->seconds = e->m->time.microseconds / 1000000.0;
    if (e->m->seconds >= 0.03) {
        e->m->rect_mete.left += 102;
        sfClock_restart(e->m->clock);
        if (e->m->rect_mete.left >= 102 * 40) {
            e->m->is_dead = false;
            e->m->rect_mete.left = 0;
        }
    }
    sfSprite_setPosition(e->m->sprite_m, e->m->pos_expl);
    sfSprite_setTextureRect(e->m->sprite_m, e->m->rect_mete);
    sfRenderWindow_drawSprite(e->window, e->m->sprite_m, NULL);
}

void kill_function(main_t *e)
{
    e->m->random_pos_y = rand() % 780;
    if (sfFloatRect_contains(&e->m->h_b, e->event->x, e->event->y)) {
        sfSound_play(e->event->sound_ex);
        e->m->pos_expl.x = e->event->event.mouseButton.x - 70;
        e->m->pos_expl.y = e->event->event.mouseButton.y - 100;
        e->m->vec_kill = (sfVector2f) {-200, e->m->random_pos_y};
        sfSprite_setPosition(e->m->sprite, e->m->vec_kill);
        e->m->is_dead = true;
        set_score(e);
    }
}

void duck_reach_earth(main_t *e)
{
    e->m->random_pos_y = rand() % 780;
    if (sfFloatRect_intersects(&e->m->e_h_b, &e->m->h_b, &e->m->limit_m)) {
        e->m->vec_kill = (sfVector2f) {-200, e->m->random_pos_y};
        sfSprite_setPosition(e->m->sprite, e->m->vec_kill);
        sfSound_play(e->event->sound_ex);
        e->score->e_life++;
        earth_kill(e);
    }
}
