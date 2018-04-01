/*
** EPITECH PROJECT, 2017
** move_shape
** File description:
** move_shape
*/

#include "header_play.h"
#include "header_tetris.h"

int	can_move(win_t *win)
{
	char **grid = win->grid;

	for (int y = 0; y != win->height; y++) {
		for (int x = 0; x != win->width; x++) {
			if (grid[y][x] == '*' && (y == win->height - 1 ||
							grid[y + 1][x] == 'o'))
				return (0);
		}
	}
	return (1);
}
int	move_shape(win_t *win)
{
	char **grid = win->grid;

	if (can_move(win) == 0)
		return (0);
	for (int y = win->height - 1; y != -1; y--) {
		for (int x = 0; x != win->width; x++) {
			if (grid[y][x] == '*') {
				grid[y + 1][x] = '*';
				grid[y][x] = ' ';
			}
		}
	}
	return (1);
}
