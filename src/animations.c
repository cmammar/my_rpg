/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include "my_rpg.h"

void	anim_sprite(obj_t *obj, int rect, sfVector2f pos)
{
	sfInt32	time;

	time = sfTime_asMilliseconds(sfClock_getElapsedTime(obj->clock));
	obj->rectangle.top = rect;
	if (time % 1 == 0) {
		obj->position.x += pos.x;
		obj->position.y += pos.y;
	}
	if (time >= 100) {
		if (obj->rectangle.left >= 160)
			obj->rectangle.left = 0;
		else
			obj->rectangle.left += 32;
		sfClock_restart(obj->clock);
	}
}