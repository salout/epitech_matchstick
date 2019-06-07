/*
** EPITECH PROJECT, 2017
** utility.c
** File description:
** project
*/

#include "my.h"

int check_line(char *line, int max_size, int x)
{
    line[my_strlen(line) - 1] = '\0';
    if (x == -1)
        return (0);
    for (int i = 0; line[i]; i++)
        if (line[i] < '0' || line[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (0);
        }
    if (my_getnbr(line) <= 0 || my_getnbr(line) > max_size || my_getnbr(line) \
    > 99) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    } else
        return (1);
}

char **modifie_map(char **map, int line, int match)
{
    int i = 0;

    for (; map[line][i] != ' ' && map[line][i] != '\0'; i++);
    i--;
    for (int x = 0; x != match; x++)
        map[line][i--] = ' ';
    return (map);
}

int check_match(char *line, int max_match, int match_on_line, int x)
{
    line[my_strlen(line) - 1] = '\0';
    if (x == -1)
        return (0);
    for (int i = 0; line[i]; i++)
        if (line[i] < '0' || line[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (0);
        }
    if (my_getnbr(line) <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (0);
    } else if (my_getnbr(line) > max_match) {
        my_putstr("Error: you cannot remove more than 5 matches per turn\n");
        return (0);
    } else if (my_getnbr(line) > match_on_line) {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    } else
        return (1);
}

void disp_line(char **map, int x, int *line)
{
    *line = *line - 1;
    my_putchar('*');
    for (int i = 0; i != *line; i++)
        my_putchar(' ');
    my_putstr(map[x]);
    for (int i = 0; i != *line; i++)
        my_putchar(' ');
    my_putchar('*');
}

void print_map(char **map, int size_line, int line)
{
    int temp_line = line;

    for (int i = 0; i != size_line + 2; i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; i != line; i++) {
        disp_line(map, i, &temp_line);
        my_putchar('\n');
    }
    for (int i = 0; i != size_line + 2; i++)
        my_putchar('*');
    my_putchar('\n');
}
