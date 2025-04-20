/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** event
*/

#include "./include/my.h"

void game_is_on_condition(main_t *e)
{
    if (e->menu->game_is_on) {
        sfSound_play(e->event->sound);
        kill_function(e);
        kill2_function(e);
        kill3_function(e);
    }
}

void event_function(main_t *e)
{
    while (sfRenderWindow_pollEvent(e->window, &e->event->event)) {
        if (e->event->event.type == sfEvtMouseMoved) {
            e->cursor->vec.x = e->event->event.mouseMove.x - 90;
            e->cursor->vec.y = e->event->event.mouseMove.y - 128;
            sfSprite_setPosition(e->cursor->sprite, e->cursor->vec);
        }
        if (e->event->event.type == sfEvtClosed)
            sfRenderWindow_close(e->window);
        if (e->event->event.type == sfEvtMouseButtonPressed) {
            e->event->x = e->event->event.mouseButton.x;
            e->event->y = e->event->event.mouseButton.y;
            game_is_on_condition(e);
        }
    }
}
