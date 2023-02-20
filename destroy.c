/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** destroy
*/
#include "./include/my.h"

void destroy_simulation(tower_t *tower, plane_t *plane)
{
    while (tower != NULL) {
        sfSprite_destroy(tower->sprite);
        sfTexture_destroy(tower->texture);
        free(tower);
        tower = tower->next;
    }
    while (plane != NULL) {
        sfSprite_destroy(plane->sprite);
        sfTexture_destroy(plane->texture);
        free(plane);
        plane = plane->next;
    }
}

void destroy_menu(menu_t *menu, options_t *options)
{
    sfText_destroy(menu->t_start.text);
    sfText_destroy(menu->t_options.text);
    sfText_destroy(menu->t_title.text);
    sfText_destroy(menu->t_epi.text);
    sfFont_destroy(menu->t_start.font);
    sfFont_destroy(menu->t_options.font);
    sfFont_destroy(menu->t_title.font);
    sfFont_destroy(menu->t_epi.font);
    sfSprite_destroy(menu->bg.sprite);
    sfTexture_destroy(menu->bg.texture);
    sfText_destroy(options->t_weather.text);
    sfText_destroy(options->t_menu.text);
    sfFont_destroy(options->t_weather.font);
    sfFont_destroy(options->t_menu.font);
    sfSprite_destroy(options->bg.sprite);
    sfTexture_destroy(options->bg.texture);
    sfSprite_destroy(options->s_wthr.sprite);
    sfTexture_destroy(options->s_wthr.texture);
}

void destroy_end(end_t *end)
{
    sfText_destroy(end->t_landed.text);
    sfFont_destroy(end->t_landed.font);
    sfSprite_destroy(end->bg.sprite);
    sfTexture_destroy(end->bg.texture);
}

void destroy_skelet(struct_t *skelet)
{
    sfSprite_destroy(skelet->bg.sprite);
    sfTexture_destroy(skelet->bg.texture);
    sfClock_destroy(skelet->move.clock);
    sfClock_destroy(skelet->seconds.clock);
    sfClock_destroy(skelet->minutes.clock);
    sfClock_destroy(skelet->delay.clock);
    sfText_destroy(skelet->countdown.text);
    sfFont_destroy(skelet->countdown.font);
}

void destroy_cloud(plane_t *cloud)
{
    while (cloud != NULL) {
        sfSprite_destroy(cloud->sprite);
        sfTexture_destroy(cloud->texture);
        free(cloud);
        cloud = cloud->next;
    }
}
