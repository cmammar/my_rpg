/*
** EPITECH PROJECT, 2017
** MY_ITOA
** File description:
** puts a number in a string
*/

#include <stdlib.h>

char	*my_itoa(int nb)
{
	int	tmp = nb;
	int	len = 1;
	char	*str = NULL;

	while ((tmp > 10) || (tmp < (-10))) {
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (int i = len - 1; i >= 0; i--) {
		str[i] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
