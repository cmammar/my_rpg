/*
** EPITECH PROJECT, 2018
** inventory.c
** File description:
** create and manage inventory
*/

#include "../../inc/my_rpg.h"

const int item_values2[] = {10, 13, 11, 14, 15, 18, 20, 30, 
				5, 7, 8, 8, 6, 9, 15, 18,
				7, 9, 9, 14, 8, 8, 15, 17,
				5, 10, 15, 20, 25, 50, 10, 10,
				-1, -1, -1, -1, -1, -1, -1 ,-1,
				-1, -1, -1, -1, 7, 17, 20, 15,
				3, 5, 7, 4, -1, -1, -1, -1,
				9, 14, 16, 20, -1, -1, -1, -1,
				5, 10, 20, 20, -1, -1, -1, -1};

const int item_values_min[] = {5, 10, 6, 10, 10, 16, 18, 28, 
				2, 3, 4, 4, 3, 4, 11, 16,
				3, 5, 4, 10, 4, 4, 13, 15,
				2, 6, 12, 18, 25, 50, -1, -1,
				15, 10, 5, 5, -1, -1, -1 ,-1,
				-1, -1, -1, -1, 5, 15, 18, 13,
				1, 2, 3, 4, -1, -1, -1, -1,
				6, 12, 14, 19, -1, -1, -1, -1,
				5, 10, 20, 20, -1, -1, -1, -1};

void maj_stats(stat_t *player, item_inv_t *tab_items)
{
	int defense = 0;
	int defense_min = 0;
	int type;

	for (int i = 0; i < 16; i++) {
		type = get_item_type(tab_items[i].id);
		if (type == 0 && tab_items[i].is_equip == 1) {
			player->atk_max = item_values2[tab_items[i].id];
			player->atk_min = item_values_min[tab_items[i].id];
		}
		else if ((type == 1 || type == 6 || type == 7 || type == 9) && 
			tab_items[i].is_equip == 1) {
			defense_min += item_values2[tab_items[i].id];
			defense += item_values_min[tab_items[i].id];
		}
	}
	player->def_max = defense;
	player->def_min = defense_min;
}

void maj_text_inv(stat_t player, text_inv_t *text)
{
	sfText_setString(text->attack.obj_text, itch(player.atk_max));
	sfText_setString(text->defense.obj_text, itch(player.def_max));
	sfText_setString(text->life.obj_text, itch(player.hp_now));
	sfText_setString(text->attack_min.obj_text, itch(player.atk_min));
	sfText_setString(text->defense_min.obj_text, itch(player.def_min));
}
