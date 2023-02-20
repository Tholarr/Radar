/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** play_simulation
*/
#include "../include/my.h"

void manage_events(struct_t *skelet)
{
    if (skelet->settings.event.type == sfEvtClosed)
        skelet->set = 0;

    if (skelet->settings.event.type == sfEvtKeyReleased &&
        skelet->settings.event.key.code == sfKeyS) {
        if (skelet->sprite_visibility == 1)
            skelet->sprite_visibility = 0;
        else
            skelet->sprite_visibility = 1;
    }

    if (skelet->settings.event.type == sfEvtKeyReleased &&
        skelet->settings.event.key.code == sfKeyL) {
        if (skelet->area_visibility == 1)
            skelet->area_visibility = 0;
        else
            skelet->area_visibility = 1;
    }
}

void play_simu(struct_t *skelet, tower_t *tow, plane_t *plane, options_t *opt)
{
    plane_t *cloud = NULL;
    skelet->set_weather = opt->set_weather;
    init_weather(skelet, &cloud);
    while (skelet->set == 3) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        sfRenderWindow_drawSprite(WIN, skelet->bg.sprite, NULL);

        if (skelet->airplane_nb == 0)
            skelet->set = 4;

        countdown(skelet, plane);
        moves(skelet, plane, cloud);
        display(skelet, tow, plane, cloud);
        collisions(plane, tow, skelet);
        while (sfRenderWindow_pollEvent(WIN, &skelet->settings.event)) {
            manage_events(skelet);
        }
    }
    return;
}
