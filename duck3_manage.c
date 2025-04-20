/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** main file
*/

#include "include/my.h"

void animation_duck3(main_t *e)
{
    sfVector2f vec = sfSprite_getPosition(e->m3->spri);

    sfSprite_setPosition(e->m3->spri, (sfVector2f) {vec.x + e->m3->sp, vec.y});
    sfSprite_setOrigin(e->m3->spri, e->m3->origin);
    sfSprite_setRotation(e->m3->spri, e->m3->orientation);
    e->m3->orientation += e->m3->sp_rotat;
    sfRenderWindow_setMouseCursorVisible(e->window, sfFalse);
    e->m3->h_b = sfSprite_getGlobalBounds(e->m3->spri);
}

void animation_expl3(main_t *e)
{
    if (!e->m3->is_dead)
        return;
    e->m3->time = sfClock_getElapsedTime(e->m3->clock);
    e->m3->seconds = e->m3->time.microseconds / 1000000.0;
    if (e->m3->seconds >= 0.03) {
        e->m3->rect_mete.left += 102;
        sfClock_restart(e->m3->clock);
        if (e->m3->rect_mete.left >= 102 * 40) {
            e->m3->is_dead = false;
            e->m3->rect_mete.left = 0;
        }
    }
    sfSprite_setPosition(e->m3->sprite_m, e->m3->pos_expl);
    sfSprite_setTextureRect(e->m3->sprite_m, e->m3->rect_mete);
    sfRenderWindow_drawSprite(e->window, e->m3->sprite_m, NULL);
}

void kill3_function(main_t *e)
{
    e->m3->random_pos_y = rand() % 780;
    if (sfFloatRect_contains(&e->m3->h_b, e->event->x, e->event->y)) {
        sfSound_play(e->event->sound_ex);
        e->m3->pos_expl.x = e->event->event.mouseButton.x - 70;
        e->m3->pos_expl.y = e->event->event.mouseButton.y - 100;
        e->m3->vec_kill = (sfVector2f) {-200, e->m3->random_pos_y};
        sfSprite_setPosition(e->m3->spri, e->m3->vec_kill);
        e->m3->is_dead = true;
        set_score(e);
    }
    e->event->x = 0;
    e->event->y = 0;
}

void duck3_reach_earth(main_t *e)
{
    e->m3->random_pos_y = rand() % 780;
    if (sfFloatRect_intersects(&e->m3->e_h_b, &e->m3->h_b, &e->m3->limit_m)) {
        e->m3->vec_kill = (sfVector2f) {-200, e->m3->random_pos_y};
        sfSprite_setPosition(e->m3->spri, e->m3->vec_kill);
        sfSound_play(e->event->sound_ex);
        e->score->e_life++;
        earth_kill(e);
    }
}
