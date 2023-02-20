/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** struct
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef STRUCT__H_
    #define STRUCT__H_

    typedef struct PARAMETER {
        sfVideoMode video_mode;
        sfRenderWindow *window;
        sfEvent event;
        int height;
        int width;
    } PARAMETER_T;

    typedef struct countdown {
        sfTime time;
        sfClock *clock;
        float seconds;
        int cmp;
    } countdown_t;

    typedef struct sprite {
        sfTexture* texture;
        sfSprite* sprite;
        sfVector2f scale;
        sfVector2f pos;
    } sprite_t;

    typedef struct text {
        sfText *text;
        sfFont* font;
        sfColor color;
        sfVector2f scale;
        sfVector2f pos;
    } text_t;

    typedef struct tower{
        sfSprite *sprite;
        sfTexture *texture;
        sfColor color;
        sfVector2f pos;
        float radius;
        struct tower *next;
    } tower_t;

    typedef struct plane{
        sfSprite *sprite;
        sfTexture *texture;
        sfColor color;
        sfVector2f pos;
        sfVector2f end_pos;
        sfVector2f dir;
        sfVector2f diff;
        float speed;
        float rotate_value;
        int end;
        int delay;
        int take_off;
        int landed;
        struct plane *next;
    } plane_t;

    typedef struct {
        int p_diff_x;
        int p_diff_y;
        int np_diff_x;
        int np_diff_y;
        int dist_x_p_to_np;
        int dist_y_p_to_np;
        int max_speed;
    } collision_t;

    typedef struct {
        sprite_t bg;
        text_t t_title;
        text_t t_epi;
        text_t t_start;
        text_t t_options;
    } menu_t;

    typedef struct {
        sprite_t bg;
        sprite_t s_wthr;
        text_t t_weather;
        text_t t_menu;
        int set_weather;
        char *filepath;
    } options_t;

    typedef struct {
        sprite_t bg;
        text_t t_landed;
        text_t t_take_off;
    } end_t;

    typedef struct {
        PARAMETER_T settings;
        sprite_t bg;
        countdown_t move;
        countdown_t seconds;
        countdown_t minutes;
        countdown_t delay;
        text_t countdown;
        int tower_nb;
        int t_x;
        int t_y;
        int t_radius;
        int area_visibility;
        int sprite_visibility;
        int airplane_nb;
        int a_start_x;
        int a_start_y;
        int a_end_x;
        int a_end_y;
        int a_speed;
        int a_delay;
        int landed;
        int take_off;
        int set;
        int set_weather;
    } struct_t;

#endif /* !STRUCT__H_ */
