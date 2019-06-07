/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_getnbr(char const *);
int my_put_nbr(int);
void my_putchar(char);
int my_strcmp(char *, char *);
int my_putstr(char const *);
int my_strlen(char const *);
void print_map(char **, int, int);
int check_line(char *, int, int);
char *your_turn(char **, int, int);
int check_match(char *, int, int, int);
char **modifie_map(char **, int, int);
char **ais_turn(char **, int, int);
int is_letre(char *, char);
int check_win(char **, int);
int check_lose(char **, int);
void my_free(char **);

#endif
