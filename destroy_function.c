/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** destroy
*/

#include "./include/my.h"

void destroy_all_bis(main_t *e)
{
    sfClock_destroy(e->m->clock);
    sfClock_destroy(e->m2->clock);
    sfClock_destroy(e->m3->clock);
    sfSound_destroy(e->event->sound);
    sfSound_destroy(e->event->sound_ex);
    sfSoundBuffer_destroy(e->event->sound_buf);
    sfSoundBuffer_destroy(e->event->sound_ex_buf);
    free(e->m);
    free(e->m2);
    free(e->m3);
    free(e->score);
    free(e->diffi);
    free(e->bg);
    free(e->event);
    free(e->cursor);
    free(e->menu);
    free(e->g_o);
    free(e);
}

void destroy_all_texture(main_t *e)
{
    sfTexture_destroy(e->g_o->texture);
    sfTexture_destroy(e->menu->texture);
    sfTexture_destroy(e->menu->texture_pp);
    sfTexture_destroy(e->score->texture);
    sfTexture_destroy(e->cursor->texture);
    sfTexture_destroy(e->m->texture);
    sfTexture_destroy(e->m2->texture);
    sfTexture_destroy(e->m3->texture);
    sfTexture_destroy(e->event->texture);
    sfTexture_destroy(e->bg->texture);
    sfFont_destroy(e->score->font);
    sfRenderWindow_destroy(e->window);
    destroy_all_bis(e);
}

void destroy_all(main_t *e)
{
    sfSprite_destroy(e->cursor->sprite);
    sfSprite_destroy(e->bg->sprite);
    sfSprite_destroy(e->menu->sprite);
    sfSprite_destroy(e->menu->sprite_pp);
    sfSprite_destroy(e->m->sprite);
    sfSprite_destroy(e->m->sprite_m);
    sfSprite_destroy(e->m2->sprit);
    sfSprite_destroy(e->m2->sprite_m);
    sfSprite_destroy(e->m3->sprite_m);
    sfSprite_destroy(e->m3->spri);
    sfSprite_destroy(e->score->sprite);
    sfSprite_destroy(e->g_o->sprite);
    destroy_all_texture(e);
}
