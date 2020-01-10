/*
** EPITECH PROJECT, 2017
** MY_CAT
** File description:
** displays the content of a file in the output
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_rpg.h"

int	my_cat(char *path)
{
	int	fd;
	char	buf[30720];

	fd = open(path, O_RDONLY);
	read(fd, buf, 30720);
	my_putstr(buf);
	close(fd);
	return (0);
}
