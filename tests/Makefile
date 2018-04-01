##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/initialisation_structure/initialisation_game.c	\
		$(WAY)/initialisation_structure/set_game.c	\
		$(WAY)/initialisation_structure/set_key.c	\
		$(WAY)/initialisation_structure/set_other.c	\
		$(WAY)/sort/swap_list.c				\
		$(WAY)/sort/search_small.c			\
		$(WAY)/sort/sort_list.c				\
		$(WAY)/utilitaries/get_shape_random.c		\
		$(WAY)/save_tetrimino/save_tetrimino.c		\
		$(WAY)/save_tetrimino/create_tetrimino.c		\
		$(WAY)/save_tetrimino/fill_tetrimino.c		\
		$(WAY)/utilitaries/delete_end_char.c		\
		$(WAY)/print_debug_mode/print_debug_mode.c	\
		$(WAY)/print_debug_mode/print_arrow.c		\
		$(WAY)/print_debug_mode/print_list_shape.c	\
		$(WAY)/utilitaries/generate_map.c		\
		$(WAY)/utilitaries/write_shape_in_window.c	\
		$(WAY)/print_help/print_help.c			\
#		$(WAY)/game/end_round.c				\
		$(WAY)/game/shape_translation.c			\#

SRC_UT	=	initialisation_structure/tests_utils.c			\
		set_game/tests_utils.c					\
		set_game/tests_utils_second.c				\
		print_debug_mode/tests_utils.c				\
		print_debug_mode/tests_utils_second.c			\
		print_debug_mode/tests_utils_three.c			\
		save_tetrimino/tests_utils.c				\
		save_tetrimino/tests_utils_second.c			\
		save_tetrimino/tests_utils_three.c			\
		utilitaries/delete_end_char/tests_utils.c		\
		utilitaries/parsing_str/tests_utils.c			\
		utilitaries/generate_map/tests_utils.c			\
		utilitaries/get_shape_random/tests_utils.c		\
#		utilitaries/write_shape_in_window/tests_utils.c		\
		sort/swap_list/tests_utils.c				\
		sort/search_small/tests_utils.c				\
		sort/sort_list/tests_utils.c				\
		game/tests_utils.c					\#

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 --coverage -I../include

LDFLAGS	=	-lcriterion -lgcov -lncurses

WAY_LIB	=	../lib/my

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	units

all:	$(OBJ) $(OBJ_UT)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UT)
	$(RM) $(OBJ:.o=.gcda)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ_UT:.o=.gcda)
	$(RM) $(OBJ_UT:.o=.gcno)

fclean:	clean
	$(RM) $(NAME)

re:	clean all
