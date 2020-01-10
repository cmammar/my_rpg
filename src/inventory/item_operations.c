/*
** EPITECH PROJECT, 2018
** inventory.c
** File description:
** operations in items in inventory.
*/

#include "my_rpg.h"

void unequip_item_type(item_inv_t *tab_items, int type)
{
	for (int i = 0; i < 16; i++) {
		if (type == get_item_type(tab_items[i].id)) {
			tab_items[i].is_equip = 0;
		}
	}
}

void remove_item(game_t *game)
{
	int posi = get_obj_select(game);

	if (posi < 0)
		return;
	game->inventory.tab_items[posi].id = -1;
	return;
}

void add_item(item_inv_t *tab_items, int posi, int id)
{
	tab_items[posi].id = id;
}

void equip_item(item_inv_t *tab_items, int posi)
{
	tab_items[posi].is_equip = 1;
}

void unequip_item(item_inv_t *tab_items, int posi)
{
	tab_items[posi].is_equip = 0;
}
