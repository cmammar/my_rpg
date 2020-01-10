/*
** EPITECH PROJECT, 2018
** itch.c
** File description:
** convert int to str
*/

#include "my_rpg.h"
#include <stdlib.h>

char *itch(int nb)
{
	int nb_inter = nb;
	int n = 0;
	char *resul;
	int end = 0;

	while (nb_inter / 10 != 0) {
		nb_inter = nb_inter / 10;
		n++;
	}
	end = n + 1;
	resul = malloc(sizeof(char) * n + 1);
	while (n >= 0) {
		resul[n] = (nb % 10) + 48;
		nb = nb / 10;
		n--;
	}
	resul[end] = '\0';
	return (resul);
}
