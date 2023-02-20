/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** init_options
*/
#include "../../include/my.h"

void init_text_menu(options_t *options)
{
    options->t_menu.text = sfText_create();
    options->t_menu.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setString(options->t_menu.text, "menu");
    sfText_setFont(options->t_menu.text, options->t_menu.font);
    sfText_setCharacterSize(options->t_menu.text, 75);
    options->t_menu.pos.x = 840;
    options->t_menu.pos.y = 800;
    options->t_menu.scale.x = 0.8;
    options->t_menu.scale.y = 0.8;
    sfText_setPosition(options->t_menu.text, options->t_menu.pos);
    sfText_setScale(options->t_menu.text, options->t_menu.scale);
    options->t_menu.color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(options->t_menu.text, options->t_menu.color);
}

void init_text_weather(options_t *options)
{
    options->t_weather.text = sfText_create();
    options->t_weather.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setString(options->t_weather.text, "< weather >");
    sfText_setFont(options->t_weather.text, options->t_weather.font);
    sfText_setCharacterSize(options->t_weather.text, 50);
    options->t_weather.pos.x = 805;
    options->t_weather.pos.y = 200;
    options->t_weather.scale.x = 0.8;
    options->t_weather.scale.y = 0.8;
    sfText_setPosition(options->t_weather.text, options->t_weather.pos);
    sfText_setScale(options->t_weather.text, options->t_weather.scale);
    options->t_weather.color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(options->t_weather.text, options->t_weather.color);
}

void init_sprite_weather(options_t *opt, char *filepath)
{
    sfVector2f scale = {0.7, 0.7};
    sfVector2f pos = {825, 300};
    opt->s_wthr.sprite = sfSprite_create();
    opt->s_wthr.texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(opt->s_wthr.sprite, opt->s_wthr.texture, sfFalse);
    sfSprite_setScale(opt->s_wthr.sprite, scale);
    sfSprite_setPosition(opt->s_wthr.sprite, pos);
}

void init_options(options_t *options)
{
    sfVector2f scale = {0.5, 0.5};
    options->bg.texture = sfTexture_createFromFile("assets/opt_bg.png", NULL);
    options->bg.sprite = sfSprite_create();
    sfSprite_setTexture(options->bg.sprite, options->bg.texture, sfFalse);
    sfSprite_setScale(options->bg.sprite, scale);
    init_sprite_weather(options, "assets/weather0.png");
    init_text_weather(options);
    init_text_menu(options);
}
