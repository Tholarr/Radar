/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** play_options
*/
#include "../../include/my.h"

void draw_options(struct_t *skelet, options_t *options)
{
    sfRenderWindow_drawSprite(WIN, options->bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, options->s_wthr.sprite, NULL);
    sfRenderWindow_drawText(WIN, options->t_weather.text, NULL);
    sfRenderWindow_drawText(WIN, options->t_menu.text, NULL);
}

void manage_go_menu(struct_t *skelet, options_t *options, sfEvent *event)
{
    if (event->mouseButton.x >= options->t_menu.pos.x &&
        event->mouseButton.x <= options->t_menu.pos.x + 160) {
        if (event->mouseButton.y >= options->t_menu.pos.y &&
            event->mouseButton.y <= options->t_menu.pos.y + 80) {
            skelet->set = 1;
        }
    }
}

void options_manage_click(struct_t *skelet, options_t *options, sfEvent *event)
{
    if (event->mouseButton.x >= 1035 &&
        event->mouseButton.x <= 1050) {
        if (event->mouseButton.y >= 205 &&
            event->mouseButton.y <= 245) {
            options->set_weather++;
            set_weather(options);
        }
    }
    if (event->mouseButton.x >= 800 &&
        event->mouseButton.x <= 825) {
        if (event->mouseButton.y >= 205 &&
            event->mouseButton.y <= 245) {
            options->set_weather--;
            set_weather(options);
        }
    }
    manage_go_menu(skelet, options, event);
}

void options_manage_events(struct_t *skelet, options_t *options, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(WIN, event)) {
        if (event->type == sfEvtClosed)
            skelet->set = 0;
        if (event->type == sfEvtMouseButtonPressed)
            options_manage_click(skelet, options, event);
    }
}

void play_opt(struct_t *skelet, options_t *options, sfEvent *event)
{
    init_options(options);
    while (skelet->set == 2) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        draw_options( skelet, options);
        options_manage_events(skelet, options, event);
    }
}
