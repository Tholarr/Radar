/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** set_weather
*/
#include "../../include/my.h"

void set_weather(options_t *options)
{
    if (options->set_weather < 0)
        options->set_weather = 3;
    if (options->set_weather > 3)
        options->set_weather = 0;

    switch (options->set_weather) {
        case 0:
            init_sprite_weather(options, "assets/weather0.png");
            break;
        case 1:
            init_sprite_weather(options, "assets/weather1.png");
            break;
        case 2:
            init_sprite_weather(options, "assets/weather2.png");
            break;
        case 3:
            init_sprite_weather(options, "assets/weather3.png");
            break;
    }
}
