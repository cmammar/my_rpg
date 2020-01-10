/*
** EPITECH PROJECT, 2018
** ./check_next_case.c
** File description:
** check if is to possible to go in the next case.
*/

#include "../inc/my_rpg.h"

int is_accessible(int id)
{
	int accessible[] = {-1, 1, 2, 7, 10, 13, 14, 16, 18, 22, 23, 24, 31,
	33, 38, 41, 44, 45, 47, 49, 53, 54, 55, 62, 64, 68, 70, 72, 75, 76,
	78, 80, 84, 85, 86, 87, 88, 89, 93, 95, 96, 97, 98, 99, 100, 101, 103,
	106, 107, 108, 109, 110, 111, 115, 116, 118, 119, 120, 131, 134, 139,
	140, 141, 142, 146, 147, 154, 158, 160, 162, 167, 168, 169, 170, 171,
	172, 173, 177, 178, 187, 188, 189, 190, 191, 193, 198, 199, 200, 201,
	202, 203, 204, 208, 209, 218, 119, 220, 221, 222, 224, 229, 230, 231,
	233, 234, 235, 251, 252, 253, 255, 260, 261, 262, 270, 271, 272, 286,
	301, 302, 303, 304, 306, 309, 317, 332, 333, 334, 335, 336, 337, 448,
	450, 451, 452, 459, 470};

	if (id == 0)
		id = -1;
	for (int i = 0; accessible[i]; i++) {
		if (id == accessible[i])
			return (1);
	}
	return (0);
}

int check_around(map_t **map, obj_t hero, int add_x, int add_y)
{
	int x = (int)((hero.position.x + 20 + (add_x * 20)) / 40);
	int y = (int)((hero.position.y + 37 + (add_y * 20)) / 40);

	if (is_accessible(map[y][x].id) == 1)
		return (1);
	return (0);
}

int	is_spawnable(int id)
{
	int	spawnable[] = {-1, 1, 2, 7, 10, 13, 14, 18, 22, 23, 24,
	31, 33, 38, 41, 44, 45, 53, 54, 55,
	62, 64, 68, 70, 72, 75, 76, 84, 85, 86,
	93, 95, 99, 100, 101, 103, 106, 107, 108, 109, 110, 111, 115, 116,
	131, 134, 139, 140, 141, 142, 146, 147,
	162, 167, 168, 169, 170, 171, 172, 173, 177, 178,
	187, 188, 189, 190, 191, 193, 198, 199, 200, 201, 202, 203, 204, 208, 209,
	218, 119, 220, 221, 222, 224, 229, 230, 231, 233, 234, 235,
	251, 252, 253, 255, 260, 261, 262, 270, 271, 272,
	286, 301, 302, 303, 304, 306,
	317, 332, 333, 334, 335, 336, 337,
	448, 450, 451, 452, 459, 470};

	if (id == 0)
		id = -1;
	for (int i = 0; spawnable[i]; i++) {
		if (id == spawnable[i])
			return (1);
	}
	return (0);
}

int	check_spawn(map_t **map, obj_t hero)
{
	int x = (int)((hero.position.x + 20) / 40);
	int y = (int)((hero.position.y + 37) / 40);

	if (hero.position.x >= 4163 && hero.position.x <= 7283
	&& hero.position.y >= 4600 && hero.position.y <= 7550)
		return (0);
	if (is_spawnable(map[y][x].id) == 1)
		return (1);
	return (0);
}
