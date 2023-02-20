/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** display_simulation
*/
#include "../include/my.h"

void draw_hitbox(plane_t *plane, sfRenderWindow *win)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f pos = {plane->pos.x, plane->pos.y};
    sfVector2f size = {20, 20};
    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineColor(rectangle, plane->color);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRenderWindow_drawRectangleShape(win, rectangle, NULL);
    sfRectangleShape_destroy(rectangle);
}

void draw_circle(float radius, tower_t *tower, sfRenderWindow *win)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos = {tower->pos.x - radius, tower->pos.y - radius};
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, tower->color);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfRenderWindow_drawCircleShape(win, circle, NULL);
    sfCircleShape_destroy(circle);
}

void display_plane(struct_t *skelet, plane_t *plane)
{
    if (skelet->sprite_visibility == 1)
        sfRenderWindow_drawSprite(WIN, plane->sprite, NULL);
    if (skelet->area_visibility == 1)
        draw_hitbox(plane, WIN);
}

void display(struct_t *skelet, tower_t *tower, plane_t *plane, plane_t *cloud)
{
    sfRenderWindow_drawText(WIN, skelet->countdown.text, NULL);
    while (cloud != NULL)  {
        if (skelet->sprite_visibility == 1)
            sfRenderWindow_drawSprite(WIN, cloud->sprite, NULL);
        cloud = cloud->next;
    }
    while (tower != NULL) {
        if (skelet->sprite_visibility == 1)
            sfRenderWindow_drawSprite(WIN, tower->sprite, NULL);
        if (skelet->area_visibility == 1)
            draw_circle(tower->radius, tower, WIN);
        tower = tower->next;
    }
    while (plane != NULL) {
        if (plane->end != 1 && plane->take_off == 1) {
            display_plane(skelet, plane);
        }
        plane = plane->next;
    }
}
