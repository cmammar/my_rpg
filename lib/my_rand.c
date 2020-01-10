/*
** EPITECH PROJECT, 2018
** MY_RAND
** File description:
** returns a random number (int)
*/

#include <stdlib.h>
#include <time.h>

int	my_rand(int min, int max)
{
	return (rand() % (max + 1 - min) + min);
}