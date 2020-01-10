/*
** EPITECH PROJECT, 2018
** MY_STRLEN
** File description:
** returns the length of the string given as parameter
*/

int	my_strlen(char const *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}