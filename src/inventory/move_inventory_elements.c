/*
** EPITECH PROJECT, 2018
** move_inventory_elements.c
** File description:
** move elements of the inventory in function of the player position.
*/

#include "my_rpg.h"

void move_inventory_back(invent_t *inv, sfSprite *hero)
{
	sfVector2f new_posi;
	sfVector2f position = sfSprite_getPosition(hero);

	new_posi.x = position.x - 492;
	new_posi.y = position.y + 153;
	sfSprite_setPosition(inv->inventory.sprite, new_posi);
}

void move_inventory_text(text_inv_t *text, sfSprite *hero)
{
	sfVector2f new_posi;
	sfVector2f position = sfSprite_getPosition(hero);

	new_posi.x = position.x - 380;
	new_posi.y = position.y + 152;
	sfText_setPosition(text->attack.obj_text, new_posi);
	new_posi.x += 40;
	sfText_setPosition(text->tiret1.obj_text, new_posi);
	new_posi.x += 25;
	sfText_setPosition(text->attack_min.obj_text, new_posi);
	new_posi.x += 85;
	sfText_setPosition(text->defense.obj_text, new_posi);
	new_posi.x += 45;
	sfText_setPosition(text->tiret2.obj_text, new_posi);
	new_posi.x += 25;
	sfText_setPosition(text->defense_min.obj_text, new_posi);
	new_posi.x += 90;
	sfText_setPosition(text->life.obj_text, new_posi);
	new_posi.x += 105;
	sfText_setPosition(text->exp.obj_text, new_posi);
}
