/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include <CSFML/Graphics.h>
#include <stdlib.h>
#include "my_rpg.h"

int	game_loop(game_t *game)
{
	poll_event(game);
	if (game->scene == BATTLE)
		battle(game, &game->battle);
	if (quest(game) == 1) {
		//print fin du game image
		return (-1);
	}
	check_lvl(game, &game->obj[HERO]);
	draw_objects(game);
	return (0);
}

int	main(int ac, char *av[], char *envp[])
{
	game_t	game;
	
	if (ac >= 2 && (my_strcmp(av[1], "-h") == 0)) {
		my_cat("txt/usage");
		return (0);
	}
	if (envp[0] == NULL)
		return (84);

	if (init_game(&game) < 0)
		return (84);
	while (sfRenderWindow_isOpen(game.window)) {
		if (game_loop(&game) < 0)
			break;
	}
	destroyer(&game);
	return (0);
}
