/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** get_script
*/
#include "../include/my.h"

sfVector2f init_direction(plane_t *new_plane)
{
    float hyp;
    sfVector2f direction;
    direction.x = new_plane->end_pos.x - new_plane->pos.x;
    direction.y = new_plane->end_pos.y - new_plane->pos.y;
    hyp = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    direction.x /= hyp;
    direction.y /= hyp;
    return direction;
}

void add_plane(struct_t *skelet, plane_t **plane, sfVector2f scale)
{
    plane_t *new_plane = malloc(sizeof(plane_t));
    new_plane->pos.x = skelet->a_start_x;
    new_plane->pos.y = skelet->a_start_y;
    new_plane->end_pos.x = skelet->a_end_x;
    new_plane->end_pos.y = skelet->a_end_y;
    new_plane->speed = skelet->a_speed;
    new_plane->delay = skelet->a_delay;
    new_plane->rotate_value = 0;
    new_plane->end = 0;
    new_plane->landed = 0;
    new_plane->take_off = 0;
    new_plane->color = sfWhite;
    new_plane->dir = init_direction(new_plane);
    new_plane->sprite = sfSprite_create();
    new_plane->texture = sfTexture_createFromFile("assets/plane.png", NULL);
    sfSprite_setPosition(new_plane->sprite, new_plane->pos);
    sfSprite_setTexture(new_plane->sprite, new_plane->texture, sfFalse);
    sfSprite_setScale(new_plane->sprite, scale);
    new_plane->next = (*plane);
    (*plane) = new_plane;
}

void get_plane_script(struct_t *skelet, char *buffer, int i)
{
    i += 5;
    skelet->a_start_x = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    skelet->a_start_y = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    skelet->a_end_x = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    skelet->a_end_y = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    skelet->a_speed = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    skelet->a_delay = my_get_nbr(i, buffer);
}

void add_tower(struct_t *skelet, tower_t **tower)
{
    tower_t *new_tower = malloc(sizeof(tower_t));
    new_tower->pos.x = skelet->t_x;
    new_tower->pos.y = skelet->t_y;
    new_tower->radius = (1920 / 100) * skelet->t_radius;
    new_tower->color = sfWhite;
    new_tower->sprite = sfSprite_create();
    new_tower->texture = sfTexture_createFromFile("assets/tower.png", NULL);
    sfSprite_setTexture(new_tower->sprite, new_tower->texture, sfFalse);
    sfVector2f scale = {0.07, 0.07};
    sfVector2f sprite_pos = {skelet->t_x - 13, skelet->t_y - 20};
    sfSprite_setPosition(new_tower->sprite, sprite_pos);
    sfSprite_setScale(new_tower->sprite, scale);
    new_tower->next = (*tower);
    (*tower) = new_tower;
}

void get_tower_script(struct_t *skelet, char *buffer, int i)
{
    i += 5;
    skelet->t_x = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    skelet->t_y = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    skelet->t_radius = my_get_nbr(i, buffer);
}
