/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** init_simulation
*/
#include "../include/my.h"

void init_bg(struct_t *skelet)
{
    skelet->bg.texture = sfTexture_createFromFile("assets/bg.jpg", NULL);
    skelet->bg.sprite = sfSprite_create();
    sfSprite_setTexture(skelet->bg.sprite, skelet->bg.texture, sfFalse);
}

void init_clock(struct_t *skelet)
{
    skelet->move.clock = sfClock_create();
    skelet->delay.clock = sfClock_create();
    skelet->minutes.clock = sfClock_create();
    skelet->seconds.clock = sfClock_create();
    skelet->minutes.cmp = 0;
    skelet->seconds.cmp = 0;
}

void init_countdown(struct_t *skelet)
{
    sfVector2f scale = {0.8, 0.8};
    skelet->countdown.text = sfText_create();
    skelet->countdown.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setFont(skelet->countdown.text, skelet->countdown.font);
    sfText_setCharacterSize(skelet->countdown.text, 50);
    skelet->countdown.pos.x = 1800;
    skelet->countdown.pos.y = 12;
    skelet->countdown.color = sfColor_fromRGB(255, 255, 255);
    sfText_setPosition(skelet->countdown.text, skelet->countdown.pos);
    sfText_setColor(skelet->countdown.text, skelet->countdown.color);
    sfText_setScale(skelet->countdown.text, scale);
    sfText_setString(skelet->countdown.text, "00:00");
    sfRenderWindow_drawText(WIN, skelet->countdown.text, NULL);
}

void init_weather(struct_t *skelet, plane_t **cloud)
{
    for (int i = 0; i < skelet->set_weather * 4; i++) {
        plane_t *new_cloud = malloc(sizeof(plane_t));
        sfVector2f scale = {0.7, 0.7};
        new_cloud->end_pos.x = rand() % 1920;
        new_cloud->end_pos.y = rand() % 1080;
        new_cloud->pos.x = rand() % 1920;
        new_cloud->pos.y = rand() % 1080;
        new_cloud->end = 0;
        new_cloud->speed = 10;
        new_cloud->dir = init_direction(new_cloud);
        new_cloud->sprite = sfSprite_create();
        new_cloud->texture = sfTexture_createFromFile("assets/cloud.png", NULL);
        sfVector2f origin = {193, 139};
        sfSprite_setTexture(new_cloud->sprite, new_cloud->texture, sfFalse);
        sfSprite_setScale(new_cloud->sprite, scale);
        sfSprite_setOrigin(new_cloud->sprite, origin);
        sfSprite_setPosition(new_cloud->sprite, new_cloud->pos);
        new_cloud->next = (*cloud);
        (*cloud) = new_cloud;
    }
}
