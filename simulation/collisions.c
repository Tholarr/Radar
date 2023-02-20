/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** collisions
*/
#include "../include/my.h"

int check_area(plane_t *plane, tower_t *tower)
{
    float dist;
    float p_x;
    float p_y;
    float t_x;
    float t_y;
    while (tower != NULL) {
        p_x = plane->pos.x;
        p_y = plane->pos.y;
        t_x = tower->pos.x;
        t_y = tower->pos.y;
        dist = sqrt(pow(p_x - t_x, 2) + pow(p_y - t_y, 2));
        if (dist <= tower->radius)
            return 1;
        tower = tower->next;
    }
    return 0;
}

void check_cols(plane_t *plane, plane_t *next, tower_t *tow, struct_t *skelet)
{
    float p_x = plane->pos.x;
    float p_y = plane->pos.y;
    float np_x = next->pos.x;
    float np_y = next->pos.y;
    float dist = sqrt(pow(p_x - np_x, 2) + pow(p_y - np_y, 2));
    if (check_area(plane, tow) || check_area(next, tow))
        return;
    if (dist <= 20 && (plane->end == 0 || next->end == 0)) {
        plane->end = 1;
        next->end = 1;
        skelet->airplane_nb -= 2;
    }
}

void collisions(plane_t *plane, tower_t *tower, struct_t *skelet)
{
    while (plane != NULL) {
        plane_t *next_plane = plane->next;
        while (next_plane != NULL) {
            check_cols(plane, next_plane, tower, skelet);
            next_plane = next_plane->next;
        }
        plane = plane->next;
    }
}
