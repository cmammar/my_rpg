/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** functions for create and convert map
*/

#include "my_rpg.h"

void init_shape_data(shape_datas_t *data)
{
	int vector[] = {0, 0, 40, 0, 0, 40, 40, 40, 0, 0, 0, 0};
	sfVector2f *tab[] = {&data->l_top, &data->r_top, &data->l_down,
	&data->r_down, &data->posi};

	data->rect.left = 0;
	data->rect.top = 0;
	data->rect.width = 40;
	data->rect.height = 40;
	data->sheet.x = 0;
	data->sheet.y = 0;
	for (int i = 0, j = 0; i < 5; i++) {
		tab[i]->x = vector[j];
		j++;
		tab[i]->y = vector[j];
		j++;
	}
}

void calc_rect(game_t *game, sfConvexShape *square, int y, int x)
{
	game->shape_d.sheet.y = game->map[y][x].id / TILESET_X;
	game->shape_d.sheet.x = game->map[y][x].id % TILESET_X;
	game->shape_d.rect.left = 40 * game->shape_d.sheet.x;
	game->shape_d.rect.top = 40 * game->shape_d.sheet.y;
	sfConvexShape_setTextureRect(square, game->shape_d.rect);
	game->map[y][x].block = square;
	game->shape_d.posi.x += 40;

}

void	create_shape(game_t *game)
{
	sfTexture *test = sfTexture_createFromFile("img/sprite_sheet_map.png", NULL);
	sfConvexShape	*square = sfConvexShape_create();
	init_shape_data(&game->shape_d);

	for (int y = 0; y < game->map_size.y; y++) {
		for (int x = 0; x < game->map_size.x; x++) {
			square = sfConvexShape_create();
			sfConvexShape_setPointCount(square, 4);
			sfConvexShape_setPoint(square, 0, game->shape_d.l_top);
			sfConvexShape_setPoint(square, 1, game->shape_d.r_top);
			sfConvexShape_setPoint(square, 2,
			game->shape_d.r_down);
			sfConvexShape_setPoint(square, 3,
			game->shape_d.l_down);
			sfConvexShape_setPosition(square, game->shape_d.posi);
			sfConvexShape_setTexture(square, test, sfTrue);
			calc_rect(game, square, y, x);
		}
		game->shape_d.posi.y += 40;
		game->shape_d.posi.x = 0;
	}
}
