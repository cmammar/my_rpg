/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** manage quests
*/

#include "../../inc/my_rpg.h"

static char txt_sister[] = "LISA\n\nOu etais tu passer ?! Ca fait 2 jours \
qu'on te cherche\n\npartout ! La legende disait vrai, Mahfaklaar es revenu\
.\n\nVa vite voir le generaln en ville, il a ton equipement.\n\n\n\nQuete : \
Trouver le general en ville (Sud-Est).";

static char txt_chief[] = "Te voila enfin, ca fait 2 jours que nous avons \
distribue les\n\narmes. Ou etais-tu ? Bref treve de bavargades, nous \
avons\n\nbesoin de renfort pour battre Mahfaklaar et ses sbires.\n\nIl est \
retranche aux ruines de l'ancien chateau.\n\nMais avant va t'entrainer au \
combat au sud du villages.\n\nVoici ton equipement. Reviens me voir apres.";

static char txt_chief2[] = "Bravo, tu es maintenant fin pret pour la guerre.\
\n\nL'assaut au chateau de Ascii va bientot etre lance.\n\nL'avant-garde y est \
deja, va la rejoindre.\n\n";

static char txt_soldier[] = "Mahfaklaar s'est transforme en dragon, nous\
avons ete\n\ndescime. 50 hommes sont morts et seulement 2 sont\n\nrevenues.\
Nous devons donner nos vies pour Ascii mais\n\n si tu entres dans ce chateau tu\
n'en ressortiras\n\n pas vivant..\n\nQue dieu de garde.";

void init_quest(quest_t *quest)
{
	quest->font = sfFont_createFromFile("fnt/hermandec.ttf");
	quest->obj_text = sfText_create();
	quest->pnj_name = -5;
}

void init_text_quest(game_t *game, char *text, int pnj_name)
{
	sfVector2f h = sfSprite_getPosition(game->obj[HERO].sprite);
	sfVector2f new_posi;

	game->quest.pnj_name = pnj_name;
	sfText_setString(game->quest.obj_text, text);
	sfText_setFont(game->quest.obj_text, game->quest.font);
	sfText_setCharacterSize(game->quest.obj_text, 30);
	new_posi = (sfVector2f){h.x - 445, h.y - 310};
	sfSprite_setPosition(game->obj[PARCHEMIN].sprite, new_posi);
	new_posi = (sfVector2f){h.x - 360, h.y - 230};
	sfText_setPosition(game->quest.obj_text, new_posi);
	sfText_setColor(game->quest.obj_text, sfBlack);
}

void draw_text_quest(game_t *game)
{
	int item = game->quest.pnj_name;

	if (is_near_pnj(game, item) < 0)
		return;
	sfRenderWindow_drawSprite(game->window, game->obj[PARCHEMIN].sprite, NULL);
	sfRenderWindow_drawText(game->window, game->quest.obj_text, NULL);
}

int quest2(game_t *game, int *status)
{
	if (*status == 3 && is_near_pnj(game, SOLDIER) == 1) {
		init_text_quest(game, txt_soldier, SOLDIER);
		*status += 1;
	}
	if (game->quest.kill_drag == 1) {
		*status += 1;
		my_putstr("Bravo vous avez sauvé le royaume de Casteldragon!!!\
			\n\nCrédits:\n\tGuillaume Loiseleux\n\tThomas Lihoreau\
			\n\tCyril Mammar\n");
		return (1);
	}
	return (0);
}

int quest(game_t *game)
{
	static int status = 0;

	if (status == 0 && is_near_pnj(game, SISTER) == 1) {
		init_text_quest(game, txt_sister, SISTER);
		status++;
	}
	if (status == 1 && is_near_pnj(game, CHIEF) == 1) {
		game->rand_monster = 130;
		init_text_quest(game, txt_chief, CHIEF);
		add_item(game->inventory.tab_items, 0, 20);
		add_item(game->inventory.tab_items, 1, 24);
		add_item(game->inventory.tab_items, 7, 29);
		status++;
	}
	if (status == 2 && is_near_pnj(game, CHIEF) == 1 &&
	game->obj[HERO].stat.nb_kill >= 3) {
		game->rand_monster = 300;
		init_text_quest(game, txt_chief2, CHIEF);
		status++;
	}
	return (quest2(game, &status));
}
