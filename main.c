/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** main
*/
#include "./include/my.h"

void help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my radar [OPTIONS] path_to_script\n");
    my_putstr("    path_to_script    The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  'L' key       enable/disable hitboxes and areas.\n");
    my_putstr("  'S' key       enable/disable sprites.\n");
    my_putstr("MENU\n");
    my_putstr("  Select weather\n");
}

void init_window(struct_t *skelet)
{
    skelet->settings.height = 1080;
    skelet->settings.width = 1920;
    MODE.bitsPerPixel = 32;
    MODE.height = skelet->settings.height;
    MODE.width = skelet->settings.width;
    WIN = sfRenderWindow_create(MODE, "my_radar", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WIN, 60);
}

int main_loop(struct_t *skelet, tower_t *tower, plane_t *plane)
{
    menu_t menu;
    options_t options;
    options.set_weather = 0;
    init_menu(&menu);
    skelet->set = 1;
    while (sfRenderWindow_isOpen(WIN)) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        switch (skelet->set) {
            case 0: sfRenderWindow_close(WIN); return 0;
            case 1: play_menu(skelet, &menu, &skelet->settings.event); break;
            case 2: play_opt(skelet, &options, &skelet->settings.event); break;
            case 3: play_simu(skelet, tower, plane, &options); break;
            case 4: play_end(skelet, &skelet->settings.event); break;
        }
    }
    destroy_simulation(tower, plane);
    destroy_menu(&menu, &options);
    destroy_skelet(skelet);
    return 0;
}

int start(char *filepath, struct_t *skelet)
{
    tower_t *tower = NULL;
    plane_t *plane = NULL;
    skelet->area_visibility = 1;
    skelet->sprite_visibility = 1;
    skelet->landed = 0;
    init_window(skelet);
    if (rd_script(filepath, skelet, &tower, &plane) == 84)
        return 84;
    init_bg(skelet);
    init_clock(skelet);
    init_countdown(skelet);
    main_loop(skelet, tower, plane);
    return 0;
}

int main(int ac, char **av)
{
    struct_t skelet;

    if (ac != 2) {
        my_putstr("./my radar: bad argument: ");
        my_put_nbr(ac - 1);
        my_putstr(" given but 84 is required\n");
        my_putstr("retry with -h\n");
        return 84;
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return 0;
    }
    if (start(av[1], &skelet) == 84) {
        my_putstr("Script incorrect\n");
        return 84;
    }
    return 0;
}
