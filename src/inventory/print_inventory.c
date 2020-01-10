/*
** EPITECH PROJECT, 2018
** print_inventory.c
** File description:
** print inventory elements.
*/

#include "../../inc/my_rpg.h"

void print_items(sfRenderWindow *window, invent_t inventory)
{
	sfRenderWindow_drawSprite(window, inventory.inventory.sprite, NULL);
	for (int i = 0; i < 16; i++) {
		if (inventory.tab_items[i].id >= 0 && 
		inventory.tab_items[i].is_equip == 1) {
			sfConvexShape_setOutlineThickness(
				inventory.tab_items[i].block, 8);
			sfConvexShape_setOutlineColor(
				inventory.tab_items[i].block, sfYellow);
		}
		if (inventory.tab_items[i].id >= 0)
			sfRenderWindow_drawConvexShape(window, 
			inventory.tab_items[i].block, NULL);
	}
}

void print_text_inventory(sfRenderWindow *window, text_inv_t text)
{
	sfRenderWindow_drawText(window, text.attack.obj_text, NULL);
	sfRenderWindow_drawText(window, text.tiret1.obj_text, NULL);
	sfRenderWindow_drawText(window, text.attack_min.obj_text, NULL);
	sfRenderWindow_drawText(window, text.defense.obj_text, NULL);
	sfRenderWindow_drawText(window, text.tiret2.obj_text, NULL);
	sfRenderWindow_drawText(window, text.defense_min.obj_text, NULL);
	sfRenderWindow_drawText(window, text.life.obj_text, NULL);
	sfRenderWindow_drawText(window, text.exp.obj_text, NULL);
}

void	update_exp_bar(sfRenderWindow *window, obj_t *hero, obj_t *exp)
{
	exp->rectangle.width = hero->stat.exp_now * 313 / hero->stat.exp_max;
	sfSprite_setTextureRect(exp->sprite, exp->rectangle);
	sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
	sfRenderWindow_drawSprite(window, exp->sprite, NULL);
}

void print_inventory(game_t *game)
{
	move_inventory_back(&game->inventory, game->obj[HERO].sprite);
	move_inventory_text(&game->inventory.text, game->obj[HERO].sprite);
	create_shape_inventory(game);
	maj_stats(&game->obj[HERO].stat, game->inventory.tab_items);
	maj_text_inv(game->obj[HERO].stat, &game->inventory.text);
	print_items(game->window, game->inventory);
	print_text_inventory(game->window, game->inventory.text);
	update_exp_bar(game->window, &game->obj[HERO], &game->obj[EXP_BAR]);
}
