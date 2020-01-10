/*
** EPITECH PROJECT, 2018
** init_inventory.c
** File description:
** initialise inventory
*/

#include "../../inc/my_rpg.h"
#include <stdlib.h>

static const char font_inv[] = "fnt/rpg.ttf";
static const char path_inventory[] = "img/inventor3.png";

void init_txt(text_t *item, char *text, sfFont *font)
{
	item->obj_text = sfText_create();
	sfText_setString(item->obj_text, text);
	sfText_setFont(item->obj_text, font);
	sfText_setCharacterSize(item->obj_text, 36);
}

void init_text_inventory(text_inv_t *text)
{
	sfFont *font = sfFont_createFromFile(font_inv);

	init_txt(&text->attack, "0", font);
	init_txt(&text->defense, "0", font);
	init_txt(&text->life, "50", font);
	init_txt(&text->attack_min, "0", font);
	init_txt(&text->defense_min, "0", font);
	init_txt(&text->tiret1, "-", font);
	init_txt(&text->tiret2, "-", font);
	init_txt(&text->exp, "EXP", font);
}

int init_inventory(invent_t *inv)
{
	inv->tab_items = malloc(sizeof(item_inv_t) * 16);

	if (inv->tab_items == NULL)
		return (-1);
	for (int i = 0; i < 16; i++) {
		inv->tab_items[i].id = -1;
		inv->tab_items[i].is_equip = 0;
	}
	inv->inventory.sprite = sfSprite_create();
	inv->inventory.texture = sfTexture_createFromFile(
		path_inventory, NULL);
	sfSprite_setTexture(inv->inventory.sprite,
		inv->inventory.texture, sfFalse);
	inv->display = 0;
	init_text_inventory(&inv->text);
	return (0);
}
