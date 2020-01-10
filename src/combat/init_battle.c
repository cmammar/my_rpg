/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include <stdlib.h>
#include <time.h>
#include "../../inc/my_rpg.h"

static const char *monsters[9] = { "img/characters/monster1.png",
	"img/characters/monster2.png", "img/characters/monster3.png",
	"img/characters/monster4.png", "img/characters/monster5.png", 
	"img/characters/monster6.png", "img/characters/monster7.png",
	"img/characters/monster8.png", "img/characters/monster9.png" };

stat_t	set_stat(int hp, sfVector2u atk, sfVector2u def)
{
	stat_t	stat;

	stat.hp_now = hp;
	stat.hp_max = hp;
	stat.atk_min = atk.x;
	stat.atk_max = atk.y;
	stat.def_min = def.x;
	stat.def_max = def.y;
	return (stat);
}

void	init_battle_obj(game_t *game, obj_t *obj, int dragon)
{
	int		index = my_rand(0, 8);
	sfIntRect	rect;

	obj[BTL_BKGD] = create_object("img/battle/battle_bkgd.png", 
	(sfVector2f){329, 206}, (sfIntRect){0, 0, 272, 208}, 2);
	if (dragon == 1) {
		obj[ENEMY] = create_object("img/characters/dragon.png", 
		(sfVector2f){679, 331}, (sfIntRect){0, 0, 127, 79}, 1.5);
		game->quest.vs_drag = 1;
		return;
	} else
		game->quest.vs_drag = 0;
	if (index >= 0 && index <= 2)
		rect = (sfIntRect){10, 9, 25, 27};
	else if (index >= 3 && index <= 5)
		rect = (sfIntRect){10, 9, 26, 27};
	else
		rect = (sfIntRect){6, 12, 28, 21};
	obj[ENEMY] = create_object(monsters[index], (sfVector2f){679, 331}, 
	rect, 1.75);
}

void init_obj_stats(game_t *game, obj_t *obj)
{
	sfRectangleShape_setSize(game->battle.blur, (sfVector2f){1202, 828});
	sfRectangleShape_setFillColor(game->battle.blur,
		(sfColor){0, 0, 0, 128});
	game->battle.blur = sfRectangleShape_create();
	sfRectangleShape_setSize(game->battle.blur, (sfVector2f){1202, 828});
	sfRectangleShape_setFillColor(game->battle.blur,
	(sfColor){0, 0, 0, 128});
	obj[LB_HERO] = create_object("img/lifebar/lifebar.png",
		(sfVector2f){389, 531}, (sfIntRect){0, 110, 180, 32}, 0.75);
	obj[HP_HERO] = create_object("img/lifebar/lifebar.png",
	(sfVector2f){389, 531}, (sfIntRect){0, 147,
	(obj[HERO].stat.hp_now * 175 / obj[HERO].stat.hp_max), 25}, 0.75);
	obj[LB_ENEMY] = create_object("img/lifebar/lifebar.png",
		(sfVector2f){639, 286}, (sfIntRect){0, 110, 180, 32}, 0.75);
	obj[HP_ENEMY] = create_object("img/lifebar/lifebar.png",
		(sfVector2f){639, 286}, (sfIntRect){0, 147, 175, 25}, 0.75);
	obj[SMASH] = create_object("img/battle/hit_effect.png",
	(sfVector2f){WINDOW_X, WINDOW_Y}, (sfIntRect){4, 4, 56, 64}, 1);
	obj[SMASH].clock = sfClock_create();
	game->battle.state = sfTrue;
}

void	init_battle(game_t *game, obj_t *obj)
{
	srand((unsigned) time(NULL));
	game->battle.turn = -1;
	game->battle.clock = NULL;
	game->battle.live_atk = sfText_create();
	game->battle.live_def = sfText_create();
	game->battle.result = sfText_create();
	game->battle.hero_pos = sfSprite_getPosition(obj[HERO].sprite);
	if (is_near_pnj(game, DRAGON) == 1) {
		init_battle_obj(game, game->obj, 1);
		obj[ENEMY].stat = set_stat(50, (sfVector2u){40, 50},
		(sfVector2u){1, 15});
	}
	else {
		init_battle_obj(game, game->obj, 0);
		obj[ENEMY].stat = set_stat(6, (sfVector2u){1, 2}, 
		(sfVector2u){0, 3});
	}
	game->battle.blur = sfRectangleShape_create();
	init_obj_stats(game, obj);
}
