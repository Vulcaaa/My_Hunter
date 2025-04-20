/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** main file
*/

#include "my.h"

void init_struct_bis(main_t *e)
{
    e->event->sound = sfSound_create();
    e->event->sound_buf = sfSoundBuffer_createFromFile("./image/laser.mp3");
    sfSound_setBuffer(e->event->sound, e->event->sound_buf);
    sfSound_setVolume(e->event->sound, e->event->volume);
    e->event->sound_ex = sfSound_create();
    e->event->sound_ex_buf = sfSoundBuffer_createFromFile("./image/exp.mp3");
    sfSound_setBuffer(e->event->sound_ex, e->event->sound_ex_buf);
    sfSound_setVolume(e->event->sound_ex, e->event->volume_ex);
    e->cursor->texture = sfTexture_createFromFile("./image/cross.png", NULL);
    e->cursor->sprite = sfSprite_create();
    sfSprite_setTexture(e->cursor->sprite, e->cursor->texture, sfFalse);
    e->run_game = true;
}

void init_struct(main_t *e, int argc, char **argv)
{
    e->bg = malloc(sizeof(bg_t));
    e->event = malloc(sizeof(event_t));
    e->mode = (sfVideoMode) {1920, 1080, 32};
    e->bg->limit = 60;
    e->window = malloc(sizeof(main_t));
    e->event->volume = 20.0;
    e->event->volume_ex = 20.0;
    e->cursor = malloc(sizeof(cursor_t));
    e->bg->texture = sfTexture_createFromFile("./image/bg.jpg", NULL);
    e->bg->sprite = sfSprite_create();
    e->bg->scale = (sfVector2f) {0.99, 0.99};
    sfSprite_setScale(e->bg->sprite, e->bg->scale);
    sfSprite_setTexture(e->bg->sprite, e->bg->texture, sfFalse);
    sfRenderWindow_setFramerateLimit(e->window, e->bg->limit);
    e->n = "My_Space_Defender";
    init_duck(e);
    init_struct_bis(e);
    init_menu(e);
    h_flag(argc, argv, e);
}

void game_menu_handle(main_t *e)
{
    if (!e->menu->game_is_on) {
        sfRenderWindow_drawSprite(e->window, e->menu->sprite, NULL);
        sfRenderWindow_drawSprite(e->window, e->menu->sprite_pp, NULL);
        play_game(e);
    }
}

int main(int argc, char **argv)
{
    main_t *e = malloc(sizeof(main_t));

    init_struct(e, argc, argv);
    e->window = sfRenderWindow_create(e->mode, e->n, sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(e->window)) {
        if (!e->run_game) {
            destroy_all(e);
            return 0;
        }
        event_function(e);
        sfRenderWindow_clear(e->window, sfBlack);
        game_menu_handle(e);
        if (e->menu->game_is_on) {
            draw_all_sprites(e);
            game_is_over_condition(e);
        }
        sfRenderWindow_display(e->window);
    }
    set_highest_score(e);
    destroy_all(e);
    return 0;
}
