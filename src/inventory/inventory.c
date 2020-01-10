/*
** EPITECH PROJECT, 2018
** inventory.c
** File description:
** create and manage inventory
*/

#include <stdio.h>
#include "my_rpg.h"
#include <stdlib.h>


const int limites[13] = {24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72};
const int item_values[] = {10, 13, 11, 14, 15, 18, 20, 30, 
				5, 7, 8, 8, 6, 9, 15, 18,
				7, 9, 9, 14, 8, 8, 15, 17,
				5, 10, 15, 20, 25, 50, -1, -1,
				15, 10, 5, 5, -1, -1, -1 ,-1,
				-1, -1, -1, -1, 7, 17, 20, 15,
				3, 5, 7, 4, -1, -1, -1, -1,
				9, 14, 16, 20, -1, -1, -1, -1,
				5, 10, 20, 20, -1, -1, -1, -1};

void init_player_infos(player_t *player)
{
	player->life = 10;
	player->life_max = 70;
	player->attack = 0;
	player->defense = 0;
	player->attack_min = 0;
	player->defense_min = 0;
	player->exp = 0;
	player->nb_kill = 0;
}

int get_item_type(int id)
{
	for (int i = 0; limites[i]; i++) {
		if (id < limites[i])
			return (i);
	}
	return (-1);
}

int get_obj_select(game_t *game)
{
	sfVector2f posi_mouse = sfRenderWindow_mapPixelToCoords(game->window, 
	sfMouse_getPositionRenderWindow(game->window), game->view.win_view);
	sfVector2f posi_item;

	for (int x = 0; x < 16; x++) {
		posi_item = sfConvexShape_getPosition(
		game->inventory.tab_items[x].block);
		if (posi_mouse.x >= posi_item.x && posi_mouse.x <= 
		posi_item.x + 60 && posi_mouse.y >= posi_item.y && 
		posi_mouse.y <= posi_item.y + 60)
			return (x);
	}
	return (-1);
}

void use_item(game_t *game)
{
	int posi = get_obj_select(game);
	item_inv_t item;
	int item_type;

	if (posi < 0)
		return;
	item = game->inventory.tab_items[posi];
	item_type = get_item_type(item.id);
	if (item_type == 2 || item_type == 11) {
		game->player_infos.life += item_values[item.id];
		if (game->player_infos.life > game->player_infos.life_max)
			game->player_infos.life = game->player_infos.life_max;
		game->inventory.tab_items[posi].id = -1;
	} else {
		unequip_item_type(game->inventory.tab_items, item_type);
		equip_item(game->inventory.tab_items, posi);
	}
}
