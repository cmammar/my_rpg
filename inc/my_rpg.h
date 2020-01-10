/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** header file for the my_rpg project
*/

#ifndef MY_RPG_
#define MY_RPG

#include <CSFML/Graphics.h>

/* MACROS */
#define WINDOW_X	1202
#define WINDOW_Y	828
#define BATTLE_X	544
#define BATTLE_Y	416
#define GAME_NAME	"~ THE LEGEND OF MAMMAR ~"
#define TILESET_X	31
#define TILE_WIDTH	40
#define NB_OBJ		17

/* ENUM */
typedef enum obj {
	HERO, BTL_BKGD, ENEMY, LB_HERO, HP_HERO, LB_ENEMY, HP_ENEMY, SMASH, LVL_UP, FLAKES, INV_SHEET, EXP_BAR, SISTER, CHIEF, SOLDIER, PARCHEMIN, DRAGON
} list_t;

typedef enum state {
	GAME, BATTLE
} state_t;

/* STRUCTURES */
typedef struct s_battle {
	sfBool		state;
	list_t		turn;
	sfClock		*clock;
	int		atk;
	int		def;
	int		dmg;
	sfText		*live_atk;
	sfText		*live_def;
	sfText		*result;
	sfVector2f	hero_pos;
	sfRectangleShape	*blur;
} battle_t;

typedef struct s_stat {
	int	lvl;
	int	exp_now;
	int	exp_max;
	int	hp_now;
	int	hp_max;
	int	atk_min;
	int	atk_max;
	int	def_min;
	int	def_max;
	int nb_kill;
	int dragon_kill;
} stat_t;

typedef struct s_view {
	sfView		*win_view;
	sfVector2f	center;
	sfVector2f	size;
} view_t;

typedef struct s_obj {
	sfTexture	*texture;
	sfSprite	*sprite;
	sfIntRect	rectangle;
	sfVector2f	position;
	sfClock		*clock;
	stat_t		stat;
} obj_t;

//inventory && quest
typedef struct text_t {
	sfText *obj_text;
	char *text;
} text_t;

typedef struct quest_t {
	sfFont *font;
	sfText *obj_text;
	char *text;
	int pnj_name;
	int vs_drag;
	int kill_drag;
} quest_t;

typedef struct item_inv_t {
	int id;
	int type;
	int is_equip;
	sfConvexShape *block;
} item_inv_t;

typedef struct text_inv_t {
	text_t attack;
	text_t defense;
	text_t life;
	text_t attack_min;
	text_t defense_min;
	text_t tiret1;
	text_t tiret2;
	text_t exp;
} text_inv_t;

typedef struct invent_t {
	item_inv_t *tab_items;
	obj_t inventory;
	int display;
	text_inv_t text;
} invent_t;

typedef struct player_t {
	char *name;
	int life_max;
	int life;
	int attack;
	int defense;
	int attack_min;
	int defense_min;
	int exp;
	int nb_kill;
} player_t;

//============================

typedef struct s_map_size {
	int x;
	int y;
} map_size_t;

typedef struct s_map {
	sfConvexShape *block;
	int id;
} map_t;

typedef struct s_shape_datas {
	sfVector2f l_top;
	sfVector2f r_top;
	sfVector2f l_down;
	sfVector2f r_down;
	sfVector2f posi;
	sfIntRect rect;
	sfVector2i sheet;
} shape_datas_t;

typedef struct s_game {
	sfRenderWindow	*window;
	view_t		view;
	obj_t		*obj;
	sfEvent		event;
	sfConvexShape	***tab_shape;
	map_size_t	map_size;
	map_t		**map;
	shape_datas_t	shape_d;
	state_t		scene;
	battle_t	battle;
	invent_t inventory;
	player_t player_infos;
	quest_t quest;
	int rand_monster;
} game_t;

/* FUNCTIONS */
int	init_game(game_t *game);
void	draw_objects(game_t *game);
void	destroyer(game_t *game);
void	poll_event(game_t *game);
obj_t	create_object(const char *path, sfVector2f pos, sfIntRect rect, float factor);
void	anim_sprite(obj_t *obj, int rect, sfVector2f pos);

int get_size_map(game_t *game);
int open_map(game_t *game);
void	create_shape(game_t *game);

int	save_map_file(game_t *);
int	is_num(char);
void	my_putstr_err(char const *str);
int is_accessible(int id);
int check_around(map_t **map, obj_t hero, int add_x, int add_y);
int	check_spawn(map_t **map, obj_t hero);

/* map creation */

/* combat system */
void	battle(game_t *game, battle_t *battle);
void	init_battle(game_t *game, obj_t *obj);
stat_t	set_stat(int hp, sfVector2u atk, sfVector2u def);

/* lib */
int	my_cat(char *path);
int	my_getnbr(char *str, int *n);
char	*my_itoa(int nb);
void	my_putstr(char *str);
int	my_rand(int min, int max);
char	*my_strcat(char const *first, char const *last);
int	my_strcmp(char const *s1, char const *s2);
int	my_strlen(char const *str);


//=============================

int	init_inventory(invent_t *inv);
void	init_txt(text_t *item, char *text, sfFont *font);
void	init_text_inventory(text_inv_t *text);

void	create_shape_inventory(game_t *game);
void	init_player_infos(player_t *player);
void	remove_item(game_t *game);
void	use_item(game_t *game);

void	equip_item(item_inv_t *tab_items, int posi);
void	unequip_item_type(item_inv_t *tab_items, int type);
void	remove_item(game_t *game);
void	add_item(item_inv_t *tab_items, int posi, int id);
void	equip_item(item_inv_t *tab_items, int posi);
void	unequip_item(item_inv_t *tab_items, int posi);

void	move_inventory_back(invent_t *inv, sfSprite *hero);
void	move_inventory_text(text_inv_t *text, sfSprite *hero);

void	maj_stats(stat_t *player, item_inv_t *tab_items);
void	maj_text_inv(stat_t player, text_inv_t *text);

void	print_inventory(game_t *game);
void	print_items(sfRenderWindow *window, invent_t inventory);
void	print_text_inventory(sfRenderWindow *window, text_inv_t text);
void	print_inventory(game_t *game);

int get_item_type(int id);
int get_obj_select(game_t *game);

void init_pnj(obj_t *obj);
void init_quest(quest_t *quest);
int is_near_pnj(game_t *game, int pnj_name);
void draw_pnj(sfRenderWindow *win, obj_t *obj);

int quest(game_t *game);
void init_text_quest(game_t *game, char *text, int pnj_name);
void draw_text_quest(game_t *game);

char	*itch(int nb);
void	check_lvl(game_t *game, obj_t *hero);
obj_t	*init_obj(void);

#endif /* !MY_RPG_H_ */
