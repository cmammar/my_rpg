/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include "my_rpg.h"

obj_t	create_object(const char *path, sfVector2f pos, sfIntRect rect, float factor)
{
	obj_t	obj;

	obj.texture = sfTexture_createFromFile(path, NULL);
	obj.sprite = sfSprite_create();
	sfSprite_setTexture(obj.sprite, obj.texture, sfTrue);
	obj.rectangle = rect;
	sfSprite_setTextureRect(obj.sprite, obj.rectangle);
	obj.position = pos;
	sfSprite_setPosition(obj.sprite, obj.position);
	sfSprite_scale(obj.sprite, (sfVector2f){factor, factor});
	return (obj);
}