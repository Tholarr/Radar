/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** countdown
*/
#include "../include/my.h"

char *set_countdown_chars(struct_t *skelet, char *str, int div, int div2)
{
    if (skelet->seconds.cmp < 10)
        str[4] = skelet->seconds.cmp + 48;
    if (skelet->seconds.cmp > 9 && skelet->seconds.cmp < 60 &&
        skelet->minutes.cmp <= 60) {
        str[3] = skelet->seconds.cmp / div + 48;
        str[4] = skelet->seconds.cmp % div + 48;
    }
    if (skelet->minutes.cmp < 10)
        str[1] = skelet->minutes.cmp + 48;
    if (skelet->minutes.cmp > 9 && skelet->minutes.cmp < 60) {
        str[0] = skelet->minutes.cmp / div2 + 48;
        str[1] = skelet->minutes.cmp % div2 + 48;
    }
    sfText_setString(skelet->countdown.text, str);
    sfRenderWindow_drawText(WIN, skelet->countdown.text, NULL);
    return str;
}

void display_countdown(struct_t *skelet)
{
    char str[6] = "00:00";
    int div = 1;
    int div2 = 1;

    str[5] = '\0';
    for (div; (skelet->seconds.cmp / div) >= 10; div *= 10);
    for (div2; (skelet->minutes.cmp / div2) >= 10; div2 *= 10);
    if (skelet->seconds.cmp == 60)
        skelet->seconds.cmp = 0;
    if (skelet->minutes.cmp >= 59) {
        sfText_setString(skelet->countdown.text, ">59:59");
        sfRenderWindow_drawText(WIN, skelet->countdown.text, NULL);
        return;
    } else {
        set_countdown_chars(skelet, str, div, div2);
    }
}

void set_countdown(struct_t *skelet)
{
    skelet->minutes.time = sfClock_getElapsedTime(skelet->minutes.clock);
    skelet->seconds.time = sfClock_getElapsedTime(skelet->seconds.clock);
    skelet->delay.time = sfClock_getElapsedTime(skelet->delay.clock);
    skelet->minutes.seconds = skelet->minutes.time.microseconds / 1000000.0;
    skelet->seconds.seconds = skelet->seconds.time.microseconds / 1000000.0;
    skelet->delay.seconds = skelet->delay.time.microseconds / 1000000.0;
}

void countdown(struct_t *skelet, plane_t *plane)
{
    set_countdown(skelet);
    if (skelet->minutes.seconds >= 60.0) {
        skelet->minutes.cmp++;
        display_countdown(skelet);
        sfClock_restart(skelet->minutes.clock);
    }
    if (skelet->seconds.seconds >= 1.0) {
        skelet->seconds.cmp++;
        display_countdown(skelet);
        sfClock_restart(skelet->seconds.clock);
    }
    while (plane != NULL) {
        if (skelet->delay.seconds >= plane->delay)
            plane->take_off = 1;
        else
            plane->take_off = 0;
        plane = plane->next;
    }
}
