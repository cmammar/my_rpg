/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** init all pnj
*/

#include "../../inc/my_rpg.h"

void init_pnj(obj_t *obj)
{
	sfVector2f posi = {2483, 1263};
	sfIntRect rect = {0, 0, 23, 39};
	sfVector2f factor = {1.5, 1.5};

	obj[SISTER] = create_object("img/g3.png", posi, rect, 1);
	posi = (sfVector2f){4758, 6613};
	rect = (sfIntRect){0, 0, 31, 43};
	obj[CHIEF] = create_object("img/h1.png", posi, rect, 1);
	posi = (sfVector2f){8640, 3936};
	rect = (sfIntRect){0, 0, 25, 41};
	obj[SOLDIER] = create_object("img/h2.png", posi, rect, 1);
	posi = (sfVector2f){800, 600};
	rect = (sfIntRect){0, 0, 884, 626};//797, 564};
	obj[PARCHEMIN] = create_object("img/par.png", posi, rect, 1);
	sfSprite_scale(obj[SISTER].sprite, factor);
	sfSprite_scale(obj[CHIEF].sprite, factor);
	sfSprite_scale(obj[SOLDIER].sprite, factor);
}

void draw_pnj(sfRenderWindow *win, obj_t *obj)
{
	sfRenderWindow_drawSprite(win, obj[SISTER].sprite, NULL);
	sfRenderWindow_drawSprite(win, obj[CHIEF].sprite, NULL);
	sfRenderWindow_drawSprite(win, obj[SOLDIER].sprite, NULL);
	sfRenderWindow_drawSprite(win, obj[DRAGON].sprite, NULL);
}

int is_near_pnj(game_t *game, int pnj_name)
{
	sfVector2f hero = sfSprite_getPosition(game->obj[HERO].sprite);
	sfVector2f pnj;

	if (pnj_name < 0)
		return (-1);
	pnj = sfSprite_getPosition(game->obj[pnj_name].sprite);
	if ((pnj.x - hero.x < 50 && pnj.x - hero.x > 0 && hero.y - pnj.y < 50 
	&& hero.y - pnj.y > 0) || (pnj.x - hero.x < 35 && pnj.x - hero.x > 0 &&
	hero.y - pnj.y < 43 && hero.y - pnj.y > 0) || (pnj.y - hero.y < 50 &&
	pnj.y - hero.y > 0 && hero.x - pnj.x < 43 && hero.x - pnj.x > -20) 
	|| (hero.y - pnj.y < 50 && hero.y - pnj.y > 0 && hero.x - pnj.x < 43 &&
	hero.x - pnj.x > 0))
		return (1);
	return (-1);
}
