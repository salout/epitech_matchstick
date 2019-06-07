/*
** EPITECH PROJECT, 2017
** game_phase.c
** File description:
** project
*/

#include "my.h"

int check_win(char **map, int line)
{
    int win = 1;

    for (int i = 0; i != line; i++)
        if (is_letre(map[i], '|') == 1)
            win = 0;
    if (win == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (win);
}

int check_lose(char **map, int line)
{
    int lose = 1;

    for (int i = 0; i != line; i++)
        if (is_letre(map[i], '|') == 1)
            lose = 0;
    if (lose == 1)
        my_putstr("You lost, too bad...\n");
    return (lose);
}

char *your_turn(char **map, int max_match, int line)
{
    char *buff = NULL;
    int chose_line;
    int x;
    size_t len = 0;
    int match_on_line = 0;

    my_putstr("Line: ");
    x = getline(&buff, &len, stdin);
    if (x == -1)
        return (NULL);
    else if (check_line(buff, line, x) == 0)
        return("again");
    chose_line = my_getnbr(buff) - 1;
    for (int x = 0; map[chose_line][x] == '|'; x++)
        match_on_line++;
    my_putstr("Matches: ");
    x = getline(&buff, &len, stdin);
    if (x == -1)
        return (NULL);
    else if (check_match(buff, max_match, match_on_line, x) == 0)
        return ("again");
    my_putstr("Player removed ");
    my_putstr(buff);
    my_putstr(" match(es) from line ");
    my_put_nbr(chose_line + 1);
    my_putchar('\n');
    modifie_map(map, chose_line, my_getnbr(buff));
    return (buff);
}

int check_last_line(char **map)
{
    int x = 0;
    int line = 0;

    for (; map[x] != NULL; x++)
        if (is_letre(map[x], '|') == 1)
            line++;
    if (line > 1)
        return (-1);
    for (x = 0; map[x] != NULL; x++)
        if (is_letre(map[x], '|') == 1)
            break;
    return (x);
}

char **ais_turn(char **map, int line, int max_match)
{
    int ais_line = 0;
    int ais_match = 0;
    int match_on_line = 0;

    my_putstr("AI's turn...\n");
    while ((ais_line = random() % line)) {
        if (check_last_line(map) != -1)
            ais_line = check_last_line(map);
        if (is_letre(map[ais_line], '|') == 1)
            break ;
    }
    for (int x = 0; map[ais_line][x] == '|'; x++)
        match_on_line++;
    while ((ais_match = random() % (max_match + 1)) >= match_on_line);
    my_putstr("AI removed ");
    my_put_nbr(ais_match + 1);
    my_putstr(" match(es) from line ");
    my_put_nbr(ais_line + 1);
    my_putchar('\n');
    return (modifie_map(map, ais_line, ais_match + 1));
}
