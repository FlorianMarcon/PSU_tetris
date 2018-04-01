/*
** EPITECH PROJECT, 2017
** window_tools
** File description:
** window_tools
*/

#include <ncurses.h>
#include "header_tetris.h"
#include "header_play.h"

void	set_win(win_t *win)
{
	win->win = newwin(win->height + 2, win->width + 2, win->start_y,
								win->start_x);
	if (win->win != NULL) {
		wborder(win->win, win->border, win->border, win->top,
					win->bottom, win->angle,
					win->angle, win->angle, win->angle);
		win->grid = generate_map(win->width, win->height);
	}
}

void	refresh_all_window(win_t *game, win_t *score, win_t *next)
{
	wrefresh(game->win);
	wrefresh(score->win);
	wrefresh(next->win);
}

void	set_all_window(win_t *game, win_t *score, win_t *next)
{
	set_win(game);
	set_win(score);
	set_win(next);
}

void	delete_all_window(win_t *game, win_t *score, win_t *next)
{
	delwin(game->win);
	delwin(score->win);
	delwin(next->win);
}

void	print_grid_window(win_t *win)
{
	int i = 0;

	if (win->grid == NULL)
		return;
	while (win->grid[i] != NULL) {
		mvwprintw(win->win, i + 1, 1, win->grid[i]);
		i++;
	}
}
