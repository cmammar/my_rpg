/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** print string
*/

#include <unistd.h>
#include "my_rpg.h"

void my_putstr(char *str)
{
	write(STDOUT_FILENO, str, my_strlen(str));
}
