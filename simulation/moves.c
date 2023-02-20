/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** moves
*/
#include "../include/my.h"

void moves_plane(plane_t *plane, struct_t *skelet, plane_t *cloud)
{
    if (plane->diff.x > plane->speed / 20 ||
        plane->diff.y > plane->speed / 20 ) {
        plane->pos.x += plane->dir.x * (plane->speed / 20);
        plane->pos.y += plane->dir.y * (plane->speed / 20);
        sfSprite_setPosition(plane->sprite, plane->pos);
    } else {
        plane->pos.x += (plane->dir.x * (plane->speed / 20)) - plane->diff.x;
        plane->pos.y += (plane->dir.y * (plane->speed / 20)) - plane->diff.y;
        sfSprite_setPosition(plane->sprite, plane->pos);
        plane->end = 1;
        plane->end = 1;
        plane->landed = 1;
        skelet->landed++;
        skelet->airplane_nb--;
    }
}

void plane_take_off(plane_t *plane, struct_t *skelet, plane_t *cloud)
{
    plane->diff.x = plane->end_pos.x - plane->pos.x;
    plane->diff.y = plane->end_pos.y - plane->pos.y;
    if (plane->diff.x < 0)
        plane->diff.x = plane->pos.x - plane->end_pos.x;
    if (plane->diff.y < 0)
        plane->diff.y = plane->pos.y - plane->end_pos.y;
    moves_plane(plane, skelet, cloud);
}

void in_clock(plane_t *plane, struct_t *skelet, plane_t *cloud)
{
    while (plane != NULL) {
        if (plane->take_off == 1 && plane->landed == 0 && plane->end == 0)
            plane_take_off(plane, skelet, cloud);
        plane = plane->next;
    }
}

void moves(struct_t *skelet, plane_t *plane, plane_t *cloud)
{
    skelet->move.time = sfClock_getElapsedTime(skelet->move.clock);
    skelet->move.seconds = skelet->move.time.microseconds / 1000000.0;
    if (skelet->move.seconds > 0.05) {
        in_clock(plane, skelet, cloud);
        sfClock_restart(skelet->move.clock);
    }
}
