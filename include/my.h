/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** my
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
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "define.h"

#ifndef MY_H_
    #define MY_H_

// int my_putstr (char const *str);
// int my_put_nbr(int nb);
// int my_get_nbr(int i, char *str);

// void init_menu(menu_t *menu);
// void play_menu(struct_t *skelet, menu_t *menu, sfEvent *event);

// int rd_script(char *path, struct_t *skelet, tower_t **tow, plane_t **plane);
// void get_tower_script(struct_t *skelet, char *buffer, int i);
// void get_plane_script(struct_t *skelet, char *buffer, int i);
// void add_tower(struct_t *skelet, tower_t **tower);
// void add_plane(struct_t *skelet, plane_t **plane);

// void play_simulation(struct_t *skelet, tower_t *tower, plane_t *plane);
// void display(struct_t *skelet, tower_t *tower, plane_t *plane);
// void move_plane(struct_t *skelet, plane_t *plane);
// void collisions(plane_t *plane, tower_t *tower, struct_t *skelet);
// void countdown(struct_t *skelet, plane_t *plane);

// void init_end(end_t *end);
// void play_end(struct_t *skelet, end_t *end, sfEvent *event);

// Lib
int my_putstr (char const *str);
int my_put_nbr(int nb);
int my_get_nbr(int i, char *str);

// Menu
void init_menu(menu_t *menu);
void play_menu(struct_t *skelet, menu_t *menu, sfEvent *event);

// Options
void init_options(options_t *options);
void init_sprite_weather(options_t *options, char *filepath);
void play_opt(struct_t *skelet, options_t *options, sfEvent *event);
void set_weather(options_t *options);

// Simulation
void init_bg(struct_t *skelet);
void init_clock(struct_t *skelet);
void init_countdown(struct_t *skelet);
void init_weather(struct_t *skelet, plane_t **cloud);
sfVector2f init_direction(plane_t *new_plane);;
int rd_script(char *path, struct_t *skelet, tower_t **tow, plane_t **plane);
void get_tower_script(struct_t *skelet, char *buffer, int i);
void get_plane_script(struct_t *skelet, char *buffer, int i);
void add_tower(struct_t *skelet, tower_t **tower);
void add_plane(struct_t *skelet, plane_t **plane, sfVector2f scale);
void play_simu(struct_t *skelet, tower_t *tow, plane_t *plane, options_t *opt);
void display(struct_t *skelet, tower_t *tower, plane_t *plane, plane_t *cloud);;
void moves(struct_t *skelet, plane_t *plane, plane_t *cloud);
void collisions(plane_t *plane, tower_t *tower, struct_t *skelet);
void countdown(struct_t *skelet, plane_t *plane);

// End
void init_end(struct_t *skelet, end_t *end);
void play_end(struct_t *skelet, sfEvent *event);

// Destroy
void destroy_simulation(tower_t *tower, plane_t *plane);
void destroy_menu(menu_t *menu, options_t *options);
void destroy_end(end_t *end);
void destroy_skelet(struct_t *skelet);


#endif /* !MY_H_ */
