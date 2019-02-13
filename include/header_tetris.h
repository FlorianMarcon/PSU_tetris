/*
** EPITECH PROJECT, 2017
** header_tetris
** File description:
** header_tetris
*/

#include "my.h"
#include <stdbool.h>
#include <termios.h>
#include <getopt.h>
#include <ncurses.h>

#ifndef TETRIS_
#define TETRIS_

#define PATH_TETRIMINO "tetriminos/"

typedef struct tetrimino {
	char *name;
	int size_x;
	int size_y;
	int color;
	char **shape;
	bool good;
}tetrimino_t;

typedef struct game {
	// key
	char *key_left; //int key_left;
	char *key_right;//    int key_right;
	char *key_turn;//    int key_turn;
	char *key_drop;//    int key_drop;
	char *key_quit;//    int key_quit;
	char *key_pause;//    int key_pause;

	// map
	char **map;

	// other
	int level;
	int size_x;
	int size_y;
	bool next;
	bool debug_mode;
	bool help;
	int score;

	int mode;

	// tetriminos
	int nb_tetriminos;
	linked_list_t *shape;

	// game

	tetrimino_t *next_shape;
	bool write_next;
	bool in_game;
	long int clock;
	// read

	struct termios old;
}game_t;

// initialisation_structure

game_t	*initialisation_game(void);

// set

int	set_game(int ac, char **av, game_t *game);

int	set_key_left(char *arg, game_t *game);

int	set_key_right(char *arg, game_t *game);

int	set_key_drop(char *arg, game_t *game);

int	set_key_turn(char *arg, game_t *game);

int	set_key_quit(char *arg, game_t *game);

int	set_key_pause(char *arg, game_t *game);

int	set_size(char *arg, game_t *game);

int	set_level(char *arg, game_t *game);

// print_debug_mode

void	print_key_move(game_t *game);

void	print_key_other(game_t *game);

void	print_other(game_t *game);

void	print_debug_mode(game_t *game);

void	print_arrow(int arrow);

void	print_shape(tetrimino_t *tetri);

void	print_list_shape(linked_list_t *list);

// save_tetrimino

int	is_good_extension(char *name);

linked_list_t	*save_tetrimino(char *path_folder);

tetrimino_t	*create_tetrimino(char *path);

char	*recuperate_name(char *str);

void	fill_settings(int fd, tetrimino_t *tetri);

void	fill_shape(int fd, tetrimino_t *tetri);

void	verifictation_size_tetrimino(tetrimino_t *tetri);

void	fill_tetrimino(int fd, tetrimino_t *tetri);

// utilitaries

void	delete_end_char(char *str, char c);

void	print_help(char *name);

char	**generate_map(int width, int height);

linked_list_t	*get_n_node(linked_list_t *list, int n);

tetrimino_t	*get_shape_random(game_t *game);

void	read_no_blocked(game_t *base);

void	read_blocked(game_t *base);

// sort

void	swap_list(linked_list_t *one, linked_list_t *two);

linked_list_t	*search_small(linked_list_t *list);

void	sort_list(linked_list_t *list);

// game

int	main_loop(game_t *base);

#endif
