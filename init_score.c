/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** ini m3
*/

#include "my.h"

void set_highest_score(main_t *e)
{
    FILE *FILE_score = fopen("max_score.txt", "w");

    if (e->score->score_nbr > atoi(e->score_max->nbr)) {
        fprintf(FILE_score, "%d", e->score->score_nbr);
        return;
    }
    fprintf(FILE_score, "%s", e->score_max->nbr);
    return;
}

void get_score_max(main_t *e)
{
    FILE *file = fopen("max_score.txt", "r");
    e->score_max->nbr = malloc(sizeof(char) * 6);

    if (fgets(e->score_max->nbr, 6, file) == NULL)
        my_strcpy(e->score_max->nbr, "0");
    return;
}

void init_highest_score(main_t *e)
{
    e->score_max = malloc(sizeof(score_max_t));
    e->score_max->text = sfText_create();
    sfText_setFont(e->score_max->text, e->score->font);
    e->score_max->pos = (sfVector2f) {40, 880};
    sfText_setPosition(e->score_max->text, e->score_max->pos);
    sfText_setCharacterSize(e->score_max->text, e->score->size);
    sfText_setScale(e->score_max->text, e->score->scale);
    sfText_setColor(e->score_max->text, e->score->color);
    /*score_text*/
    e->score_max->str = malloc(sizeof(char) * 13);
    my_strcpy(e->score_max->str, "score max : ");
    sfText_setString(e->score_max->text, e->score_max->str);
    get_score_max(e);
    strcat(e->score_max->str, e->score_max->nbr);
    sfText_setString(e->score_max->text, e->score_max->str);
}

void init_score_bis(main_t *e)
{
    e->score->str = malloc(sizeof(char) * 13);
    my_strcpy(e->score->str, "score : ");
    e->score->score_nbr = 0;
    e->score->e_life = 0;
    my_strcat_int(e->score->str, e->score->score_nbr);
    sfText_setString(e->score->text, e->score->str);
    e->score->texture = sfTexture_createFromFile("image/Heart.png", NULL);
    e->score->sprite = sfSprite_create();
    sfSprite_setTexture(e->score->sprite, e->score->texture, sfFalse);
    e->score->pos_life = (sfVector2f) {1630, -40};
    sfSprite_setPosition(e->score->sprite, e->score->pos_life);
    e->score->scale_life = (sfVector2f) {2, 2};
    sfSprite_setScale(e->score->sprite, e->score->scale_life);
    e->score->rect_life = (sfIntRect) {0, 0, 100, 100};
    sfSprite_setTextureRect(e->score->sprite, e->score->rect_life);
}

void init_score(main_t *e)
{
    e->score = malloc(sizeof(score_t));
    e->diffi = malloc(sizeof(diffi_t));
    e->score->text = sfText_create();
    e->score->font = sfFont_createFromFile("image/Storan.otf");
    sfText_setFont(e->score->text, e->score->font);
    e->score->pos = (sfVector2f) {40, 830};
    sfText_setPosition(e->score->text, e->score->pos);
    e->score->size = 40;
    sfText_setCharacterSize(e->score->text, e->score->size);
    e->score->color = sfWhite;
    e->score->scale = (sfVector2f) {1.2, 1.2};
    sfText_setScale(e->score->text, e->score->scale);
    sfText_setColor(e->score->text, e->score->color);
    init_score_bis(e);
    e->diffi->difficulty = 25;
    init_highest_score(e);
}
