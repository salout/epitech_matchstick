/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** project
*/

#include "my.h"

int is_letre(char *opt, char l)
{
    for (int i = 0; opt[i] != '\0'; i++)
        if (opt[i] == l)
            return (1);
    return (0);
}

int check_error(char **av)
{
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100)
        return (1);
    else if (my_getnbr(av[2]) <= 0)
        return (1);
    else
        return (0);
}

char **get_map(int line, int *size_line)
{
    char **map = malloc(sizeof (char *) * line + 1);
    int x = 0;
    int plus = 0;

    for (; x < line; x++) {
        map[x] = malloc(sizeof (char) * (x * 2) + 1);
        for (int i = 0; i != (x + 1) + plus; i++)
            map[x][i] = i == ((x + 1) + plus) ? '\0' : '|';
        plus++;
    }
    *size_line = my_strlen(map[x - 1]);
    map[x] = NULL;
    return (map);
}

int matchstick(char **av)
{
    int max_match = my_getnbr(av[2]);
    int size_line = 0;
    char *temp;
    int line = my_getnbr(av[1]);
    char **map = get_map(line, &size_line);

    while (42) {
        print_map(map, size_line, line);
        my_putchar('\n');
        if (check_win(map, line) == 1)
            return (1);
        my_putstr("Your turn:\n");
        while ((temp = your_turn(map, max_match, line)) == NULL || my_strcmp(temp, "again") == 1)
            if (temp == NULL)
                return (0);
        print_map(map, size_line, line);
        my_putchar('\n');
        if (check_lose(map, line) == 1)
            return (2);
        map = ais_turn(map, line, max_match);
    }
}

int main(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Bad argument.\n", 15);
        return (84);
    } else if (check_error(av) == 1) {
        write(2, "./matchstick [nbr of line] [match can be taken]\n", 48);
        return (84);
    } else
        return (matchstick(av));
}
