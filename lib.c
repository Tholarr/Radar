/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myradar-thomas.cluseau
** File description:
** lib
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr (char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i ++;
    }

}

int put_nbr_display(int nb)
{
    int div = 1;
    int m;

    while ((nb / div) >= 10) {
        div = div * 10;
    }
    while (div > 0) {
        m = nb / div;
        my_putchar( m % 10 + '0' );
        div = div / 10;
    }
}

int my_put_nbr(int nb)
{
    if (nb > 0) {
        put_nbr_display(nb);
    } else if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
        put_nbr_display(nb);
    }
}

int my_get_nbr(int i, char *str)
{
    long nb = 0;
    int is_neg = 0;

    for (i; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] == '-')
            is_neg = 1;
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - 48;
        }
    }
    if (nb < -2147483648 || nb > 2147483647)
        return (0);
    if (is_neg == 1)
        return (-nb);
    return nb;
}
