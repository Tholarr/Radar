/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** end
*/
#include "../include/my.h"

void draw_end(struct_t *skelet, end_t *end)
{
    sfRenderWindow_drawSprite(WIN, end->bg.sprite, NULL);
    sfRenderWindow_drawText(WIN, end->t_landed.text, NULL);
    sfRenderWindow_drawText(WIN, end->t_take_off.text, NULL);
}

void end_manage_events(struct_t *skelet, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(WIN, event)) {
        if (event->type == sfEvtClosed)
            skelet->set = 0;
    }
}

void play_end(struct_t *skelet, sfEvent *event)
{
    end_t end;
    init_end(skelet, &end);

    while (skelet->set == 4) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        draw_end(skelet, &end);
        end_manage_events(skelet, event);
    }
    destroy_end(&end);
}
