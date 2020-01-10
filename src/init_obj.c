/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include <stdlib.h>
#include "../inc/my_rpg.h"

void init_obj_inter(obj_t *obj)
{
	sfVector2f	pos1 = {0, 0};
	sfVector2f	pos2 = {2362, 1229};
	sfIntRect	rect2 = {32, 0, 25, 32};

	obj[HERO] = create_object("img/characters/hero.png", pos2, 
		(sfIntRect){32, 0, 25, 32}, 1.5);
	obj[HERO].clock = sfClock_create();
	obj[HERO].stat = set_stat(50, (sfVector2u){2, 3}, (sfVector2u){1, 2});
	obj[HERO].stat.lvl = 1;
	obj[HERO].stat.exp_max = 20;
	obj[HERO].stat.exp_now = 0;
	obj[HERO].stat.nb_kill = 0;
	obj[HERO].stat.hp_now = 50;
	obj[HERO].stat.hp_max = 50;
	obj[EXP_BAR] = create_object("img/exp_bar.png", (sfVector2f){699, 577},
	(sfIntRect){0, 0, 313, 26}, 1);
	obj[LVL_UP] = create_object("img/lvl_up.png", (sfVector2f){WINDOW_X,
	WINDOW_Y}, (sfIntRect){0, 0, 37, 9}, 2);
	obj[FLAKES] = create_object("img/flakes.png", (sfVector2f){WINDOW_X,
	WINDOW_Y}, (sfIntRect){0, 0, 123, 95}, 2);
	obj[FLAKES].clock = sfClock_create();
	obj[INV_SHEET] = create_object("img/sheet_inv.png", pos1, rect2, 1);
}

obj_t	*init_obj(void)
{
	obj_t		*obj = malloc(sizeof(obj_t) * NB_OBJ);

	obj[DRAGON] = create_object("img/characters/dragon.png", 
	(sfVector2f){9660, 870}, (sfIntRect){0, 0, 127, 79}, 1.5);
	init_obj_inter(obj);
	init_pnj(obj);
	return (obj);
}
