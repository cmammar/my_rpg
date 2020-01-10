##
## Projet my_rpg
##

CC	:=	gcc
CPPFLAGS =	-I./inc/
CFLAGS	+=	-Wall -Wextra #-Werror
LDFLAGS	=	-lc_graph_prog

MAKE	:=	make
RM	:=	rm -rf

NAME	=	my_rpg

SRC	=	src/main.c		\
		src/init_game.c		\
		src/event.c		\
		src/cdd.c		\
		src/destroyer.c		\
		src/create_object.c	\
		src/animations.c	\
		src/open_map.c		\
		src/set_textures.c	\
		src/check_next_case.c	\
		src/combat/combat.c	\
		src/combat/init_battle.c	\
		lib/my_cat.c		\
		lib/my_putstr.c		\
		lib/my_strcmp.c		\
		lib/my_strlen.c		\
		lib/my_getnbr.c		\
		lib/my_itoa.c		\
		lib/my_rand.c		\
		lib/my_strcat.c		\
		src/inventory/init_inventory.c	\
		src/inventory/inventory.c	\
		src/inventory/set_textures_inventory.c	\
		src/inventory/itch.c	\
		src/inventory/move_inventory_elements.c	\
		src/inventory/print_inventory.c	\
		src/inventory/item_operations.c	\
		src/inventory/maj_inv_elements.c	\
		src/pnj/pnj.c	\
		src/quest/quest.c	\
		src/lvl_exp.c	\
		src/init_obj.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -lcsfml -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean re
