/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/
 
#include <stdlib.h>
#include "../inc/my_rpg.h"

int	init_window(game_t *game)
{
	sfVideoMode	mode = {WINDOW_X, WINDOW_Y, 32};
	char		*title = GAME_NAME;

	game->window = sfRenderWindow_create(mode,
					title, sfResize | sfClose, NULL);
	if (!game->window)
		return (-1);
	sfRenderWindow_setFramerateLimit(game->window, 30);
	return (0);
}

int	init_view(view_t *view)
{
	sfVector2f	view_pos = {WINDOW_X / 2, WINDOW_Y / 2};
	sfVector2f	view_size = {WINDOW_X, WINDOW_Y};

	view->win_view = sfView_create();
	if (!view->win_view)
		return (-1);
	view->center = view_pos;
	sfView_setCenter(view->win_view, view->center);
	view->size = view_size;
	sfView_setSize(view->win_view, view->size);
	return (0);
}

int init_map(game_t *game)
{
	if (get_size_map(game) < 0)
		return (-1);
	if (open_map(game) < 0)
		return (-1);
	return (0);
}

int	init_game(game_t *game)
{
	if (init_window(game) < 0)
		return (-1);
	if (init_view(&game->view) < 0)
		return (-1);
	if (init_map(game) < 0)
		return (-1);
	if (init_inventory(&game->inventory) < 0)
		return (-1);
	game->quest.vs_drag = 0;
	game->quest.kill_drag = 0;
	game->rand_monster = 10000000;
	game->scene = GAME;
	game->battle.state = sfFalse;
	game->obj = init_obj();
	init_quest(&game->quest);
	return (0);
}
