/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include "my_rpg.h"

void	set_flakes(obj_t *flakes)
{
	flakes->rectangle.left = 0;
	sfSprite_setPosition(flakes->sprite,
		(sfVector2f){(WINDOW_X / 2) - (flakes->rectangle.width),
		(WINDOW_Y / 2) - (flakes->rectangle.height)});
}

void	set_lvl_up_txt(obj_t *lvlup)
{
	sfSprite_setPosition(lvlup->sprite,
		(sfVector2f){(WINDOW_X / 2) - (lvlup->rectangle.width),
		(WINDOW_Y / 2) - (lvlup->rectangle.height)});
}

void	check_lvl(game_t *game, obj_t *hero)
{
	if (hero->stat.exp_now >= hero->stat.exp_max) {
		hero->stat.lvl += 1;
		hero->stat.exp_max += 10;
		hero->stat.exp_now = 0;
		set_flakes(&game->obj[FLAKES]);
		set_lvl_up_txt(&game->obj[LVL_UP]);
	}
}