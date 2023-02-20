/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** menu
*/
#include "../include/my.h"

void draw_menu(menu_t *menu, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, menu->bg.sprite, NULL);
    sfRenderWindow_drawText(win, menu->t_title.text, NULL);
    sfRenderWindow_drawText(win, menu->t_epi.text, NULL);
    sfRenderWindow_drawText(win, menu->t_start.text, NULL);
    sfRenderWindow_drawText(win, menu->t_options.text, NULL);
}

void menu_manage_mouse_click(struct_t *skelet, menu_t *menu, sfEvent *event)
{
    if (event->mouseButton.x >= menu->t_start.pos.x &&
        event->mouseButton.x <= (menu->t_start.pos.x + 215)) {
        if (event->mouseButton.y >= menu->t_start.pos.y &&
            event->mouseButton.y <= (menu->t_start.pos.y + 100)) {
            skelet->set = 3;
        }
    }
    if (event->mouseButton.x >= menu->t_options.pos.x &&
        event->mouseButton.x <= (menu->t_options.pos.x + 290)) {
        if (event->mouseButton.y >= menu->t_options.pos.y &&
            event->mouseButton.y <= (menu->t_options.pos.y + 100)) {
            skelet->set = 2;
        }
    }
}

void menu_manage_events(struct_t *skelet, menu_t *menu, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        skelet->set = 0;
    }
    if (event->type == sfEvtMouseButtonPressed)
        menu_manage_mouse_click(skelet, menu, event);
}

void play_menu(struct_t *skelet, menu_t *menu, sfEvent *event)
{
    while (skelet->set == 1) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        draw_menu(menu, WIN);
        while (sfRenderWindow_pollEvent(WIN, event)) {
            menu_manage_events(skelet, menu, event);
        }
    }
    return;
}
