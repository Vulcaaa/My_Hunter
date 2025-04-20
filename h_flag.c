/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** main file
*/

#include "include/my.h"

void h_flag(int argc, char **argv, main_t *e)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("/!\\My_Space_Defender/!\\\n");
        my_putstr("-This game is based on user skills-\n");
        my_putstr("In this game you'll be asked to defend earth ");
        my_putstr("from a meteorite attack.\n");
        my_putstr("For that you will be using the brand new MegaLaser3000 ");
        my_putstr("developped by the U.S. army.\n");
        my_putstr("Keep in mind that you can't win the game.\n");
        my_putstr("The more you destroy asteroids, the ");
        my_putstr("faster they will come.\n");
        my_putstr("Now let's test your accuracy.\nTry to get ");
        my_putstr("the highest score possible by clicking with");
        my_putstr("your mouse on the asteroids.\n");
        my_putstr("Once 3 asteroids have reach the earth you loose.\n");
        my_putstr("Enjoy !\n");
        e->run_game = false;
    }
}
