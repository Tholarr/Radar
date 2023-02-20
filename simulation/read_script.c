/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** read_script
*/
#include "../include/my.h"

int verif_script(char *buffer)
{
    if (buffer[0] != 'A' && buffer[0] != 'T')
        return 84;

    for (int i = 1; buffer[i] != '\0'; i++) {

        if (buffer[i] != 'A' && buffer[i] != 'T' &&
            buffer[i] != ' ' && buffer[i] != '\n' &&
            (buffer[i] < '0' || buffer[i] > '9')) {
            return 84;
        }

        if ((buffer[i] == 'A' || buffer[i] == 'T') && buffer[i - 1] != '\n')
            return 84;
    }
    return 0;
}

void create_tabs(struct_t *skelet, tower_t **tow, plane_t **plane, char *buf)
{
    sfVector2f scale = {0.17, 0.17};
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == 'T') {
            get_tower_script(skelet, buf, i);
            add_tower(skelet, tow);
        }
        if (buf[i] == 'A') {
            get_plane_script(skelet, buf, i);
            add_plane(skelet, plane, scale);
        }
    }
}

void script_navig(struct_t *skelet, tower_t **tow, plane_t **plane, char *buf)
{
    skelet->tower_nb = 0;
    skelet->airplane_nb = 0;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == 'A')
            skelet->airplane_nb++;
        if (buf[i] == 'T')
            skelet->tower_nb++;
    }
    skelet->take_off = skelet->airplane_nb;
    create_tabs(skelet, tow, plane, buf);
}

int rd_script(char *path, struct_t *skelet, tower_t **tow, plane_t **plane)
{
    struct stat sb;
    stat(path, &sb);
    char buffer[sb.st_size + 1];

    read(open(path, O_RDONLY), buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    if (verif_script(buffer) == 84)
        return 84;
    script_navig(skelet, tow, plane, buffer);
    return 0;
}
