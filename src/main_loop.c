/*
** EPITECH PROJECT, 2018
** Tetris
** File description:
** main_loop
*/

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include "header_tetris.h"
#include "my.h"
#include "header_play.h"

int	main_loop(game_t *base)
{
	win_t game = {NULL, NULL, base->size_y , base->size_x * 2, '-', '-',
		'+', '|', 31 - (game.height / 2), 102 - (game.width / 2)};
	win_t score = {NULL, NULL, 10, 30, '-', '-', '+', '|', 0, 0};
	win_t next = {NULL, NULL, 5, 10, '-', '-', '+', '|', 0, 200 -
								(next.width)};

	initscr();
	curs_set(0);
	set_all_window(&game, &score, &next);
	read_no_blocked(base);
	while (base->in_game == true) {
		clear();
		print_grid_window(&game);
		refresh_all_window(&game, &score, &next);
		event(base, &game);
	}
	read_blocked(base);
	delete_all_window(&game, &score, &next);
	endwin();
	return (0);
}
