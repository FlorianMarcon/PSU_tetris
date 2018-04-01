/*
** EPITECH PROJECT, 2018
** Tetris
** File description:
** header_play.h
*/

#include "header_tetris.h"

#ifndef PLAY_
#define PLAY_

typedef struct win_s {
	WINDOW *win;

	char **grid;

	int height;
	int width;

	char top;
	char bottom;
	char angle;
	char border;

	int start_y;
	int start_x;
} win_t;

// window_tools

void	set_win(win_t *win);

void	refresh_all_window(win_t *game, win_t *score, win_t *next);

void	set_all_window(win_t *game, win_t *score, win_t *next);

void	delete_all_window(win_t *game, win_t *score, win_t *next);

void	print_grid_window(win_t *win);

// game

void	write_shape_in_window(win_t *win, tetrimino_t *tetri);

int	move_shape(win_t *win);

void	end_round(char **grid);

void	shape_right_translation(win_t *win);

void	shape_left_translation(win_t *win);

int	can_move_right(win_t *win);

int	can_move_left(win_t *win);

// event

void	event_key(game_t *base, win_t *game);

void	event(game_t *base, win_t *game);

#endif /*PLAY_*/
