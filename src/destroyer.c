/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include "my_rpg.h"

void	destroy_object(obj_t obj)
{
	sfSprite_destroy(obj.sprite);
	sfTexture_destroy(obj.texture);
}

void	destroyer(game_t *game)
{
	// for (int i = 0; i < NB_OBJ; i++)
	// 	destroy_object(game->obj[i]);
	sfView_destroy(game->view.win_view);
	sfRenderWindow_destroy(game->window);
}
