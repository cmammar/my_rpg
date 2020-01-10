/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** our own role playing game
*/

#include <stdio.h>
#include "../../inc/my_rpg.h"

sfText	*set_text(char *str, sfColor color, int size, sfVector2f position)
{
	sfText	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("fnt/badaboom.TTF");

	sfText_setString(text, str);
	sfText_setFont(text, font);
	sfText_setColor(text, color);
	sfText_setCharacterSize(text, size);
	sfText_setPosition(text, position);
	return (text);
}

int	check_end(game_t *game, obj_t *obj, list_t *turn, sfText **result)
{
	int	status = 0;

	if (obj[HERO].stat.hp_now == 0) {
		sfSprite_setTextureRect(obj[HERO].sprite, (sfIntRect){32, 0, 25, 32});
		*result = set_text("DEFEAT", sfBlack, 50, (sfVector2f){WINDOW_X / 2 - ((my_strlen("DEFEAT") * 20) / 2), WINDOW_Y / 2 - 25 - 20});
		status = 1;
		sfSprite_setPosition(obj[HERO].sprite, 
		(sfVector2f){2362, 1229});
	} else if (obj[ENEMY].stat.hp_now == 0) {
		sfSprite_setTextureRect(obj[ENEMY].sprite, (sfIntRect){0, 0, 0, 0});
		sfSprite_setTextureRect(obj[HERO].sprite, (sfIntRect){32, 0, 25, 32});
		*result = set_text("VICTORY", sfRed, 50, (sfVector2f){WINDOW_X / 2 - ((my_strlen("VICTORY") * 20) / 2), WINDOW_Y / 2 - 25 - 20});
		obj[HERO].stat.nb_kill = obj[HERO].stat.nb_kill + 1;
		status = 1;
		if (game->quest.vs_drag == 1)
			game->quest.kill_drag = 1;
	}
	if (status == 1)
		*turn = -1;
	return (status);
}

int	check_click(sfRenderWindow *window, obj_t *obj)
{
	sfVector2i	mouse = sfMouse_getPositionRenderWindow(window);

	if (sfMouse_isButtonPressed(sfMouseLeft)
	&& (mouse.x >= obj->position.x && mouse.x <= obj->position.x + (float)obj->rectangle.width * 1.75)
	&& (mouse.y >= obj->position.y && mouse.y <= obj->position.y + (float)obj->rectangle.height * 1.75))
		return (1);
	return (0);
}

void	display_dmg(battle_t *battle, obj_t *chara, obj_t *effect, obj_t *hp)
{
	char		*str_atk = my_strcat("ATK -", my_itoa(battle->atk));
	char		*str_def = my_strcat("DEF +", my_itoa(battle->def));
	sfVector2f	pos = sfSprite_getPosition(chara->sprite);

	battle->live_atk = set_text(str_atk, sfRed, 20, (sfVector2f){pos.x, pos.y - 50});
	battle->live_def = set_text(str_def, sfBlue, 20, (sfVector2f){pos.x, pos.y - 30});
	*effect = create_object("img/battle/hit_effect.png", (sfVector2f){pos.x - 10, pos.y - 10}, (sfIntRect){4, 4, 56, 64}, 1);
	hp->rectangle.width = sfSprite_getTextureRect(hp->sprite).width - (battle->dmg * 148 / chara->stat.hp_max);
	sfSprite_setTextureRect(hp->sprite, hp->rectangle);
	effect->clock = sfClock_create();
}

void	damage_calc(game_t *game, obj_t *p1, obj_t *p2, obj_t *hp)
{
	game->battle.atk = my_rand(p1->stat.atk_min, p1->stat.atk_max);
	game->battle.def = my_rand(p2->stat.def_min, p2->stat.def_max);
	game->battle.dmg = game->battle.atk - game->battle.def;
	if (game->battle.dmg < 0)
		game->battle.dmg = 0;
	if (game->battle.dmg > p2->stat.hp_now)
		p2->stat.hp_now = 0;
	else
		p2->stat.hp_now -= game->battle.dmg;
	display_dmg(&game->battle, p2, &game->obj[SMASH], hp);
}

void	switch_turn(game_t *game, battle_t *battle, obj_t *obj)
{
	static int	ite = 1;

	if (ite == 1) {
		if (battle->turn == HERO)
			damage_calc(game, &obj[HERO], &obj[ENEMY], 
				&obj[HP_ENEMY]);
		else if (battle->turn == ENEMY)
			damage_calc(game, &obj[ENEMY], &obj[HERO], 
				&obj[HP_HERO]);
		ite = 0;
	}
	if (sfTime_asSeconds(sfClock_getElapsedTime(battle->clock)) > 1) {
		battle->turn = (battle->turn == HERO) ? ENEMY : -1;
		ite = 1;
		sfClock_restart(battle->clock);
	}
}

void	battle(game_t *game, battle_t *battle)
{
	if (game->battle.state == sfFalse)
		init_battle(game, game->obj);
	if (battle->clock == NULL)
		battle->clock = sfClock_create();
	if (battle->turn == HERO) {
		switch_turn(game, battle, game->obj);
	} else if (check_end(game, game->obj, &game->battle.turn, 
		&game->battle.result) != 1 && battle->turn == ENEMY) {
		switch_turn(game, battle, game->obj);
	} else {
		if (check_end(game, game->obj, &game->battle.turn, 
			&game->battle.result) != 1 && check_click(game->window,
			&game->obj[ENEMY]) == 1) {
			battle->turn = HERO;
			sfClock_restart(battle->clock);
		}
		// if (game->obj[HERO].stat.exp_now >= game->obj[HERO].stat.exp_max)
		// 	xxx;
	}
}
