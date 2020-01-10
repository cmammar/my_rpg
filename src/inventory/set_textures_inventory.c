/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** set the texture of the inventory
*/

#include <stdio.h>
#include "my_rpg.h"
#include <stdlib.h>

void init_shape_data2(shape_datas_t *data, sfSprite *hero)
{
	sfVector2f pos_h = sfSprite_getPosition(hero);
	int vector[] = {0, 0, 60, 0, 0, 60, 60, 60, pos_h.x - 452,
	pos_h.y + 221};
	sfVector2f *tab[] = {&data->l_top, &data->r_top, &data->l_down,
	&data->r_down, &data->posi};

	data->rect.left = 0;
	data->rect.top = 0;
	data->rect.width = 60;
	data->rect.height = 60;
	data->sheet.x = 0;
	data->sheet.y = 0;
	for (int i = 0, j = 0; i < 5; i++) {
		tab[i]->x = vector[j];
		j++;
		tab[i]->y = vector[j];
		j++;
	}
}

void calc_rect2(game_t *game, sfConvexShape *square, int x, sfSprite *hero)
{
	sfVector2f pos_h = sfSprite_getPosition(hero);

	game->shape_d.sheet.y = game->inventory.tab_items[x].id / 8;
	game->shape_d.sheet.x = game->inventory.tab_items[x].id % 8;
	game->shape_d.rect.left = 60 * game->shape_d.sheet.x;
	game->shape_d.rect.top = 60 * game->shape_d.sheet.y;
	sfConvexShape_setTextureRect(square, game->shape_d.rect);
	game->inventory.tab_items[x].block = square;
	game->shape_d.posi.x += 60 + 60;
	if (x == 7) {
		game->shape_d.posi.y += 95;
		game->shape_d.posi.x = pos_h.x - 452;
	}
}

void	create_shape_inventory(game_t *game)
{
	sfTexture *sheet = game->obj[INV_SHEET].texture;
	sfConvexShape	*square = sfConvexShape_create();
	init_shape_data2(&game->shape_d, game->obj[HERO].sprite);

	for (int x = 0; x < 16; x++) {
		square = sfConvexShape_create();
		sfConvexShape_setPointCount(square, 4);
		sfConvexShape_setPoint(square, 0, game->shape_d.l_top);
		sfConvexShape_setPoint(square, 1, game->shape_d.r_top);
		sfConvexShape_setPoint(square, 2,
		game->shape_d.r_down);
		sfConvexShape_setPoint(square, 3,
		game->shape_d.l_down);
		sfConvexShape_setPosition(square, game->shape_d.posi);
		sfConvexShape_setTexture(square, sheet, sfTrue);
		calc_rect2(game, square, x, game->obj[HERO].sprite);
	}
}
