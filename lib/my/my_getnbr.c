/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr.c
*/

int check_nbr(char const *str, int i)
{
    if (str[i] > 47 && str[i] < 58)
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    long res = 0;
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check_nbr(str, i) == 1 && x == 0) {
            x = 1;
            res = res + (str[i] - 48);
        } else if (check_nbr(str, i) == 1 && x == 1) {
            res = res * 10;
            res = res + (str[i] - 48);
        }
    }
    return (res);
}
