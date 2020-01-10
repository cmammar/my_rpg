/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** Print number
*/

#include "my_rpg.h"

int is_num(char nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	else
		return (0);
}

int limites2(int nb)
{
	if (nb + 1 <= -2147483647)
		return (0);
	else
		return (nb);
}

int my_getnbr(char *str, int *n)
{
	int resul = 0;
	int moins = 1;

	while (is_num(str[*n]) == 0)
		*n += 1;
	moins = (str[*n - 1] == '-') ? -1 : 1;
	while (is_num(str[*n]) == 1) {
		resul = resul * 10 + (str[*n] - 48);
		*n += 1;
	}
	resul = limites2(resul * moins);
	return (resul);
}
