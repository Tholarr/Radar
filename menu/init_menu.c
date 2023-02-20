/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** init_menu
*/
#include "../include/my.h"

void init_text_start(menu_t *menu)
{
    menu->t_start.text = sfText_create();
    menu->t_start.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setString(menu->t_start.text, "start");
    sfText_setFont(menu->t_start.text, menu->t_start.font);
    sfText_setCharacterSize(menu->t_start.text, 100);
    menu->t_start.pos.x = 100;
    menu->t_start.pos.y = 900;
    menu->t_start.scale.x = 0.8;
    menu->t_start.scale.y = 0.8;
    sfText_setPosition(menu->t_start.text, menu->t_start.pos);
    sfText_setScale(menu->t_start.text, menu->t_start.scale);
    menu->t_start.color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(menu->t_start.text, menu->t_start.color);
}

void init_text_options(menu_t *menu)
{
    menu->t_options.text = sfText_create();
    menu->t_options.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setString(menu->t_options.text, "options");
    sfText_setFont(menu->t_options.text, menu->t_options.font);
    sfText_setCharacterSize(menu->t_options.text, 100);
    menu->t_options.pos.x = 450;
    menu->t_options.pos.y = 900;
    menu->t_options.scale.x = 0.8;
    menu->t_options.scale.y = 0.8;
    sfText_setPosition(menu->t_options.text, menu->t_options.pos);
    sfText_setScale(menu->t_options.text, menu->t_options.scale);
    menu->t_options.color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(menu->t_options.text, menu->t_options.color);
}

void init_text_epi(menu_t *menu)
{
    menu->t_epi.text = sfText_create();
    menu->t_epi.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setString(menu->t_epi.text, "1st year epitech project");
    sfText_setFont(menu->t_epi.text, menu->t_epi.font);
    sfText_setCharacterSize(menu->t_epi.text, 75);
    menu->t_epi.pos.x = 1000;
    menu->t_epi.pos.y = 190;
    menu->t_epi.scale.x = 0.45;
    menu->t_epi.scale.y = 0.45;
    sfText_setPosition(menu->t_epi.text, menu->t_epi.pos);
    sfText_setScale(menu->t_epi.text, menu->t_epi.scale);
    menu->t_epi.color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(menu->t_epi.text, menu->t_epi.color);
}

void init_text_title(menu_t *menu)
{
    menu->t_title.text = sfText_create();
    menu->t_title.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setString(menu->t_title.text, "MY RADAR");
    sfText_setFont(menu->t_title.text, menu->t_title.font);
    sfText_setCharacterSize(menu->t_title.text, 75);
    menu->t_title.pos.x = 325;
    menu->t_title.pos.y = 125;
    menu->t_title.scale.x = 1.1;
    menu->t_title.scale.y = 1.1;
    sfText_setPosition(menu->t_title.text, menu->t_title.pos);
    sfText_setScale(menu->t_title.text, menu->t_title.scale);
    menu->t_title.color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(menu->t_title.text, menu->t_title.color);
}

void init_menu(menu_t *menu)
{
    sfVector2f scale = {0.5, 0.49};
    menu->bg.texture = sfTexture_createFromFile("assets/menu_bg.jpg", NULL);
    menu->bg.sprite = sfSprite_create();
    sfSprite_setTexture(menu->bg.sprite, menu->bg.texture, sfFalse);
    sfSprite_setScale(menu->bg.sprite, scale);
    init_text_title(menu);
    init_text_epi(menu);
    init_text_start(menu);
    init_text_options(menu);
}
