/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int verif_open_map(FILE *file, map_size_t *map_size)
{
	map_size->x = 1;
	map_size->y = 1;
	if (file == NULL)
		return (-1);
	return (0);
}

int get_size_map(game_t *game)
{
	FILE *file = fopen("txt/map_id.csv", "r");
	char *line = NULL;
	size_t len = 0;
	int x = 0;

	if (verif_open_map(file, &game->map_size) == 84)
		return (-1);
	if (getline(&line, &len, file) < 1)
		return (-1);
	while (line[x]) {
		if (line[x] == ',')
			game->map_size.x += 1;
		x++;
	}
	while (getline(&line, &len, file) > 1)
		game->map_size.y++;
	if (game->map_size.x < 4 || game->map_size.y < 4)
		return (-1);
	fclose(file);
	return (0);
}

int create_map(game_t *game, FILE *file, char *line, size_t size)
{
	int k = 0;

	game->map = malloc(sizeof(map_t*) * game->map_size.y + 1);
	if (game->map == NULL)
		return (-1);
	for (int i = 0; i < game->map_size.y; i++) {
		game->map[i] = malloc(sizeof(map_t) * (game->map_size.x + 1));
		if (game->map[i] == NULL)
			return (-1);
		getline(&line, &size, file);
		if (line == NULL)
			return (-1);
		for (int j = 0; j < game->map_size.x; j++) {
			game->map[i][j].id = my_getnbr(line, &k);
			k++;
		}
		k = 0;
	}
	return (0);
}

int open_map(game_t *game)
{
	FILE *file = fopen("txt/map_id.csv", "r");
	char *line = NULL;
	size_t size = 0;

	if (file == NULL) {
		return (-1);
	}
	if (create_map(game, file, line, size) == 84) {
		return (-1);
	}
	create_shape(game);
	fclose(file);
	return (0);
}
