/*
** EPITECH PROJECT, 2017
** MY_STRCAT
** File description:
** appending a src string to a dest string
*/

#include <string.h>
#include <stdlib.h>
#include "my_rpg.h"

char	*my_strcat(char const *first, char const *last)
{
	int	len_a = strlen(first);
	int	len_b = strlen(last);
	char	*dest = malloc(sizeof(char) * (len_a + len_b + 1));
	int	i;

	for (i = 0; i < len_a; i++)
		dest[i] = first[i];
	for (i = 0; i < len_b; i++)
		dest[i + len_a] = last[i];
	dest[len_a + len_b] = '\0';
	return (dest);
}
