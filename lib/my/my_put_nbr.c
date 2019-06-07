/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

void my_putchar(char);

int my_put_nbr(int nb)
{
        int num;

        if (nb < 0) {
            my_putchar(45);
            nb = -nb;
        }
        if (nb > 9) {
            num = nb % 10;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(48 + num);
        } else
            my_putchar(48 + nb);
        return (0);
}
