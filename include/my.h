/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** .h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct bg {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    unsigned int limit;
} bg_t;

typedef struct score_max {
    sfText *text;
    char *str;
    sfVector2f pos;
    char *nbr;
} score_max_t;

typedef struct event {
    sfEvent event;
    sfSound *sound;
    sfSoundBuffer *sound_buf;
    sfSound *sound_ex;
    sfSoundBuffer *sound_ex_buf;
    int x;
    int y;
    float volume;
    float volume_ex;
    sfTexture *texture;
} event_t;

typedef struct kill {
    sfFloatRect hit_box;
} kill_t;

typedef struct m {
    sfTexture *texture;
    sfSprite *sprite;
    float sp;
    float sp_rotat;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f vec;
    sfVector2f vec_kill;
    sfFloatRect h_b;
    int random_pos_y;
    sfFloatRect e_h_b;
    sfFloatRect limit_m;
    sfVector2f origin;
    float orientation;
    sfSprite *sprite_m;
    bool is_dead;
    sfVector2f pos_expl;
    sfIntRect rect_mete;
    sfVector2f scale_expl;
} m_t;

typedef struct m2 {
    sfTexture *texture;
    sfSprite* sprit;
    float sp;
    float sp_rotat;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f vec;
    sfVector2f vec_kill;
    sfFloatRect h_b;
    int random_pos_y;
    sfFloatRect e_h_b;
    sfFloatRect limit_m;
    sfVector2f origin;
    float orientation;
    sfSprite *sprite_m;
    bool is_dead;
    sfVector2f pos_expl;
    sfIntRect rect_mete;
    sfVector2f scale_expl;
} m2_t;

typedef struct m3 {
    sfTexture *texture;
    sfSprite* spri;
    sfVector2f scale;
    float sp;
    float sp_rotat;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f vec;
    sfVector2f vec_kill;
    sfFloatRect h_b;
    int random_pos_y;
    sfFloatRect e_h_b;
    sfFloatRect limit_m;
    sfVector2f origin;
    float orientation;
    sfSprite *sprite_m;
    bool is_dead;
    sfVector2f pos_expl;
    sfIntRect rect_mete;
    sfVector2f scale_expl;
} m3_t;

typedef struct cursor {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vec;
    sfVector2f scale;
} cursor_t;

typedef struct score {
    sfText *text;
    char *str;
    sfFont *font;
    sfVector2f pos;
    sfVector2f scale;
    sfColor color;
    unsigned int size;
    int score_nbr;
    unsigned int e_life;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos_life;
    sfIntRect rect_life;
    sfVector2f scale_life;
} score_t;

typedef struct diffi {
    int difficulty;
} diffi_t;

typedef struct menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfSprite *sprite_pp;
    sfTexture *texture_pp;
    sfVector2f scale_pp;
    sfVector2f pos_pp;
    sfFloatRect rect_pp;
    sfBool game_is_on;
} menu_t;

typedef struct g_o {
    sfSprite *sprite;
    sfTexture *texture;
    sfBool is_over;
    sfVector2f pos;
} game_over_t;

typedef struct main {
    sfTime time;
    sfRenderWindow *window;
    char *n;
    sfVideoMode mode;
    bg_t *bg;
    menu_t *menu;
    m_t *m;
    m2_t *m2;
    m3_t *m3;
    event_t *event;
    kill_t kill;
    score_t *score;
    cursor_t *cursor;
    game_over_t *g_o;
    diffi_t *diffi;
    bool run_game;
    score_max_t *score_max;
} main_t;

#ifndef MY_H
    #define MY_H

void animation_expl(main_t *e);
void animation_expl3(main_t *e);
void animation_expl2(main_t *e);
void animation_duck(main_t *e);
void kill_function(main_t *e);
void duck_reach_earth(main_t *e);
void animation_duck2(main_t *e);
void kill2_function(main_t *e);
void duck2_reach_earth(main_t *e);
void animation_duck3(main_t *e);
void kill3_function(main_t *e);
void duck3_reach_earth(main_t *e);
void init_duck(main_t *e);
void init_m1_bis(main_t *e);
void init_m1(main_t *e);
void init_m2(main_t *e);
void init_m3(main_t *e);
void init_m3_bis(main_t *e);
void init_menu(main_t *e);
void init_game_over(main_t *e);
void game_is_over_condition(main_t *e);
void init_score(main_t *e);
void init_score_bis(main_t *e);
void play_game(main_t *e);
void duck_manage(main_t *e);
void event_function(main_t *e);
void init_game_over(main_t *e);
void set_score(main_t *e);
void set_highest_score(main_t *e);
void earth_kill(main_t *e);
void game_over(main_t *e);
void difficulty(main_t *e);
void destroy_all(main_t *e);
void destroy_all_bis(main_t *e);
void destroy_all_bis_bis(main_t *e);
void draw_all_sprites(main_t *e);
void h_flag(int argc, char **argv, main_t *e);
int my_put_nbr(int nb);
int my_nbr_to_string(char *str, int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strcat_int(char *dest, int nbr);
int my_strlen(char *str);
int my_putchar(char c);
int my_putstr(char *str);

#endif
