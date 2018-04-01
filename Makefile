##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c		\
		$(WAY)/main_loop.c	\
		$(WAY)/initialisation_structure/initialisation_game.c	\
		$(WAY)/initialisation_structure/set_game.c		\
		$(WAY)/initialisation_structure/set_key.c		\
		$(WAY)/initialisation_structure/set_other.c		\
		$(WAY)/print_debug_mode/print_debug_mode.c		\
		$(WAY)/print_debug_mode/print_arrow.c	\
		$(WAY)/print_debug_mode/print_list_shape.c	\
		$(WAY)/save_tetrimino/save_tetrimino.c		\
		$(WAY)/save_tetrimino/create_tetrimino.c		\
		$(WAY)/save_tetrimino/fill_tetrimino.c		\
		$(WAY)/utilitaries/delete_end_char.c		\
		$(WAY)/utilitaries/generate_map.c		\
		$(WAY)/utilitaries/window_tools.c		\
		$(WAY)/utilitaries/write_shape_in_window.c	\
		$(WAY)/utilitaries/get_shape_random.c		\
		$(WAY)/utilitaries/block_read.c			\
		$(WAY)/sort/swap_list.c				\
		$(WAY)/sort/search_small.c			\
		$(WAY)/sort/sort_list.c				\
		$(WAY)/print_help/print_help.c			\
		$(WAY)/game/move_shape.c			\
		$(WAY)/game/event.c				\
		$(WAY)/game/end_round.c				\
		$(WAY)/game/shape_translation.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I./include

LDFLAGS	=	-lncurses

WAY_LIB	=	./lib/my

WAY_TST	=	./tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	tetris

all:	$(NAME)

$(NAME): $(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

clean:
	make clean -C./$(WAY_TST)
	make clean -C./$(WAY_LIB)
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C./$(WAY_TST)
	make fclean -C./$(WAY_LIB)
	$(RM) $(NAME)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
