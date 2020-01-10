/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include "my_rpg.h"

void	poll_event(game_t *game)
{
	int	id = 0;

	while (sfRenderWindow_pollEvent(game->window, &game->event)) {
		if ((game->event.type == sfEvtClosed)
		|| ((game->event.type == sfEvtKeyPressed)
		&& (game->event.key.code == sfKeyEscape
		|| game->event.key.code == sfKeyQ)))
			sfRenderWindow_close(game->window);
		if ((game->event.type == sfEvtKeyPressed)
		&& (game->event.key.code == sfKeySpace)
		&& (game->scene == BATTLE)) {
			game->battle.state = sfFalse;
			game->scene = GAME;
			game->obj[HERO].stat.exp_now += 10;
			game->obj[HERO].position = game->battle.hero_pos;
			sfSprite_setPosition(game->obj[HERO].sprite, game->obj[HERO].position);
			game->obj[HERO].rectangle = (sfIntRect){32, 0, 25, 32};
		}
		if (game->event.type == sfEvtKeyPressed) {
			if (game->event.key.code == sfKeyI)
				game->inventory.display++;
		}
		if (game->event.type == sfEvtMouseButtonPressed) {
			if (game->event.mouseButton.button == sfMouseLeft && 
			game->inventory.display % 2 != 0)
				use_item(game);
			else if (game->event.mouseButton.button == sfMouseRight && 
			game->inventory.display % 2 != 0)
				remove_item(game);
		}
	}
	if (game->scene != BATTLE) {
		if ((sfKeyboard_isKeyPressed(sfKeyUp) == 1) && (sfKeyboard_isKeyPressed(sfKeyLeft) == 1) && check_around(game->map, game->obj[HERO], -1, -1) == 1) {
			anim_sprite(&game->obj[HERO], 192, (sfVector2f){-5, -5});
			id = my_rand(0, game->rand_monster);
		} else if ((sfKeyboard_isKeyPressed(sfKeyDown) == 1) && (sfKeyboard_isKeyPressed(sfKeyLeft) == 1) && check_around(game->map, game->obj[HERO], -1, 1) == 1) {
			anim_sprite(&game->obj[HERO], 128, (sfVector2f){-5, 5});
			id = my_rand(0, game->rand_monster);
		} else if ((sfKeyboard_isKeyPressed(sfKeyUp) == 1) && (sfKeyboard_isKeyPressed(sfKeyRight) == 1) && check_around(game->map, game->obj[HERO], 1, -1) == 1) {
			anim_sprite(&game->obj[HERO], 224, (sfVector2f){5, -5});
			id = my_rand(0, game->rand_monster);
		} else if ((sfKeyboard_isKeyPressed(sfKeyDown) == 1) && (sfKeyboard_isKeyPressed(sfKeyRight) == 1) && check_around(game->map, game->obj[HERO], 1, 1) == 1) {
			anim_sprite(&game->obj[HERO], 160, (sfVector2f){5, 5});
			id = my_rand(0, game->rand_monster);
		} else if (sfKeyboard_isKeyPressed(sfKeyLeft) == 1
		&& ((sfSprite_getPosition(game->obj[HERO].sprite).x / TILE_WIDTH) - (WINDOW_X / (2 * TILE_WIDTH)) > 0) && check_around(game->map, game->obj[HERO], -1, 0) == 1) {
			anim_sprite(&game->obj[HERO], 32, (sfVector2f){-7, 0});
			id = my_rand(0, game->rand_monster);
		} else if (sfKeyboard_isKeyPressed(sfKeyRight) == 1
		&& ((sfSprite_getPosition(game->obj[HERO].sprite).x / TILE_WIDTH) + (WINDOW_X / (2 * TILE_WIDTH)) < game->map_size.x) && (check_around(game->map, game->obj[HERO], 1, 0) == 1)) {
			anim_sprite(&game->obj[HERO], 64, (sfVector2f){7, 0});
			id = my_rand(0, game->rand_monster);
		} else if (sfKeyboard_isKeyPressed(sfKeyUp) == 1
		&& ((sfSprite_getPosition(game->obj[HERO].sprite).y / TILE_WIDTH) - (WINDOW_Y / (2 * TILE_WIDTH)) - 1) > 0 && (check_around(game->map, game->obj[HERO], 0, -1) == 1)) {
			anim_sprite(&game->obj[HERO], 96, (sfVector2f){0, -7});
			id = my_rand(0, game->rand_monster);
		} else if (sfKeyboard_isKeyPressed(sfKeyDown) == 1
		&& ((sfSprite_getPosition(game->obj[HERO].sprite).y / TILE_WIDTH) + (WINDOW_Y / (2 * TILE_WIDTH)) + 1 < game->map_size.y) && (check_around(game->map, game->obj[HERO], 0, 1) == 1)) {
			anim_sprite(&game->obj[HERO], 0, (sfVector2f){0, 7});
			id = my_rand(0, game->rand_monster);
		}
		if (is_near_pnj(game, DRAGON) == 1 || 
		(check_spawn(game->map, game->obj[HERO]) == 1 &&  id == 1)) {
			game->scene = BATTLE;
			game->obj[HERO].rectangle = (sfIntRect){32, 224, 25, 32};
			game->obj[HERO].position = (sfVector2f){429, 456};
		}
	}
}
