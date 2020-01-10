/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include "my_rpg.h"
#include <stdlib.h>

void	draw_convextab(sfRenderWindow *win, map_t **tab, obj_t hero, game_t *game)
{
	sfVector2f	center;

	if (game->scene == BATTLE) {
		center = game->battle.hero_pos;
	} else
		center = sfSprite_getPosition(hero.sprite);
	for (int y = (center.y / TILE_WIDTH) - (WINDOW_Y / (2 * TILE_WIDTH)) - 1; y < (center.y / TILE_WIDTH) + (WINDOW_Y / (2 * TILE_WIDTH)) + 1; y++) {
		for (int x = (center.x / TILE_WIDTH) - (WINDOW_X / (2 * TILE_WIDTH)); x < (center.x / TILE_WIDTH) + (WINDOW_X / (2 * TILE_WIDTH)); x++)
			sfRenderWindow_drawConvexShape(win, tab[y][x].block, NULL);
	}
}

void	draw_text(game_t *game)
{
	sfColor	color_atk;
	sfColor	color_def;

	color_atk = sfText_getColor(game->battle.live_atk);
	color_def = sfText_getColor(game->battle.live_def);
	color_atk.a = (color_atk.a >= 7) ? color_atk.a - 7 : 0;
	color_def.a = (color_def.a >= 7) ? color_def.a - 7 : 0;
	sfText_setColor(game->battle.live_atk, color_atk);
	sfText_setColor(game->battle.live_def, color_def);
	sfText_move(game->battle.live_atk, (sfVector2f){0, -3});
	sfText_move(game->battle.live_def, (sfVector2f){0, -3});
	sfRenderWindow_drawText(game->window, game->battle.live_atk, NULL);
	sfRenderWindow_drawText(game->window, game->battle.live_def, NULL);
}

void	anim_effect(sfRenderWindow *window, obj_t *obj, int max, int width)
{
	sfInt32	time;

	time = sfTime_asMilliseconds(sfClock_getElapsedTime(obj->clock));
	if (time >= 100) {
		if (obj->rectangle.left >= max)
			sfSprite_setPosition(obj->sprite, (sfVector2f){WINDOW_X, WINDOW_Y});
		else
			obj->rectangle.left += width;
		sfSprite_setTextureRect(obj->sprite, obj->rectangle);
		sfRenderWindow_drawSprite(window, obj->sprite, NULL);
		sfClock_restart(obj->clock);
	}
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}

void	update_lifebar(game_t *game)
{
	sfRenderWindow_drawSprite(game->window, game->obj[HP_HERO].sprite, NULL);
	sfRenderWindow_drawSprite(game->window, game->obj[LB_HERO].sprite, NULL);
	sfRenderWindow_drawSprite(game->window, game->obj[HP_ENEMY].sprite, NULL);
	sfRenderWindow_drawSprite(game->window, game->obj[LB_ENEMY].sprite, NULL);
}

void	lvl_up_anim(game_t *game)
{
	sfVector2f	pos = sfSprite_getPosition(game->obj[LVL_UP].sprite);

	anim_effect(game->window, &game->obj[FLAKES], 1353, 123);
	if (pos.y >= 325) {
		sfSprite_move(game->obj[LVL_UP].sprite, (sfVector2f){0, -2});
		sfRenderWindow_drawSprite(game->window, game->obj[LVL_UP].sprite, NULL);
	}
}

void	draw_objects(game_t *game)
{
	sfRenderWindow_clear(game->window, sfBlack);
	if (game->scene == GAME) {
		/* preliminaries */
		sfSprite_setTextureRect(game->obj[HERO].sprite, game->obj[HERO].rectangle);
		sfSprite_setPosition(game->obj[HERO].sprite, game->obj[HERO].position);
		sfView_setCenter(game->view.win_view, sfSprite_getPosition(game->obj[HERO].sprite));
		/* MY VIEW */
		sfRenderWindow_setView(game->window, game->view.win_view);
		/* draw map */
		draw_convextab(game->window, game->map, game->obj[HERO], game);
		draw_pnj(game->window, game->obj);
		/* draw hero */
		sfRenderWindow_drawSprite(game->window, game->obj[HERO].sprite, NULL);
		if (game->inventory.display % 2 != 0)
			print_inventory(game);
		draw_text_quest(game);
		/* DEFAULT VIEW */
		sfRenderWindow_setView(game->window, sfRenderWindow_getDefaultView(game->window));
		/* level up animation */
		lvl_up_anim(game);
	} else if (game->scene == BATTLE) {
		/* preliminaries */
		sfSprite_setTextureRect(game->obj[HERO].sprite, game->obj[HERO].rectangle);
		sfSprite_setPosition(game->obj[HERO].sprite, game->obj[HERO].position);
		sfView_setCenter(game->view.win_view, game->battle.hero_pos);
		/* MY VIEW */
		sfRenderWindow_setView(game->window, game->view.win_view);
		/* draw map */
		draw_convextab(game->window, game->map, game->obj[HERO], game);
		draw_pnj(game->window, game->obj);
		/* DEFAULT VIEW */
		sfRenderWindow_setView(game->window, sfRenderWindow_getDefaultView(game->window));
		/* battle related stuff */
		sfRenderWindow_drawRectangleShape(game->window, game->battle.blur, NULL);
		sfRenderWindow_drawSprite(game->window, game->obj[BTL_BKGD].sprite, NULL);
		/* draw hero */
		sfRenderWindow_drawSprite(game->window, game->obj[HERO].sprite, NULL);
		/* battle related stuff pt. 2 */
		sfRenderWindow_drawSprite(game->window, game->obj[ENEMY].sprite, NULL);
		update_lifebar(game);
		draw_text(game);
		anim_effect(game->window, &game->obj[SMASH], 132, 64);
		sfRenderWindow_drawText(game->window, game->battle.result, NULL);
	}
	sfRenderWindow_display(game->window);
}
