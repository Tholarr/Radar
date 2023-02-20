/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** init_end
*/
#include "../include/my.h"

void set_landed_count(struct_t *skelet, end_t *end)
{
    char str[22] = "landed :            .";
    int div = 1;
    int char_nb = 1;
    int index = 9;

    str[20] = '\0';
    for (div; (skelet->landed / div) >= 10; div *= 10)
        char_nb++;

    if (skelet->landed < 10) {
        str[9] = skelet->landed + 48;
    } else {
        for (int i = 0; i < char_nb; i += 2) {
            str[index] = skelet->landed / div + 48;
            str[index + 1] = skelet->landed % div + 48;
            div /= 10;
        }
    }
    sfText_setString(end->t_landed.text, str);
}

void set_take_off_count(struct_t *skelet, end_t *end)
{
    char str[24] = "take off :            .";
    int div = 1;
    int char_nb = 1;
    int index = 12;

    str[22] = '\0';
    for (div; (skelet->take_off / div) >= 10; div *= 10)
        char_nb++;

    if (skelet->take_off < 10) {
        str[12] = skelet->take_off + 48;
    } else {
        for (int i = 0; i < char_nb; i += 2) {
            str[index] = skelet->take_off / div + 48;
            str[index + 1] = skelet->take_off % div + 48;
            div /= 10;
        }
    }
    sfText_setString(end->t_take_off.text, str);
}

void init_text_landed(struct_t *skelet, end_t *end)
{
    end->t_landed.text = sfText_create();
    end->t_landed.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setFont(end->t_landed.text, end->t_landed.font);
    sfText_setCharacterSize(end->t_landed.text, 75);
    end->t_landed.pos.x = 1050;
    end->t_landed.pos.y = 150;
    end->t_landed.scale.x = 0.8;
    end->t_landed.scale.y = 0.8;
    sfText_setPosition(end->t_landed.text, end->t_landed.pos);
    sfText_setScale(end->t_landed.text, end->t_landed.scale);
    end->t_landed.color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(end->t_landed.text, end->t_landed.color);
    set_landed_count(skelet, end);
}

void init_text_take_off(struct_t *skelet, end_t *end)
{
    end->t_take_off.text = sfText_create();
    end->t_take_off.font = sfFont_createFromFile("assets/sserif.ttf");
    sfText_setFont(end->t_take_off.text, end->t_take_off.font);
    sfText_setCharacterSize(end->t_take_off.text, 75);
    end->t_take_off.pos.x = 350;
    end->t_take_off.pos.y = 150;
    end->t_take_off.scale.x = 0.8;
    end->t_take_off.scale.y = 0.8;
    sfText_setPosition(end->t_take_off.text, end->t_take_off.pos);
    sfText_setScale(end->t_take_off.text, end->t_take_off.scale);
    end->t_take_off.color = sfColor_fromRGB(255, 255, 255);
    sfText_setColor(end->t_take_off.text, end->t_take_off.color);
    set_take_off_count(skelet, end);
}

void init_end(struct_t *skelet, end_t *end)
{
    sfVector2f scale = {0.5, 0.5};
    end->bg.texture = sfTexture_createFromFile("assets/menu_bg.jpg", NULL);
    end->bg.sprite = sfSprite_create();
    sfSprite_setTexture(end->bg.sprite, end->bg.texture, sfFalse);
    sfSprite_setScale(end->bg.sprite, scale);
    init_text_landed(skelet, end);
    init_text_take_off(skelet, end);
}
