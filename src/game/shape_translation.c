/*
** EPITECH PROJECT, 2017
** shape_translation
** File description:
** shape_translation
*/

#include "header_play.h"

int	can_move_right(win_t *win)
{
	char **grid = win->grid;

	for (int x = win->width - 1; x != -1; x--) {
		for (int y = 0; grid[y] != NULL; y++) {
			if (grid[y][x] == '*' && (x == win->width - 1||
						grid[y][x + 1] == 'o')) {
				return (0);
			}
		}
	}
	return (1);
}
void	shape_right_translation(win_t *win)
{
	char **grid = win->grid;

	if (can_move_right(win) == 0)
		return;
	for (int x = win->width - 1; x != -1; x--) {
		for (int y = 0; grid[y] != NULL; y++) {
			if (grid[y][x] == '*') {
				grid[y][x] = ' ';
				grid[y][x + 1] = '*';
			}
		}
	}
}

int	can_move_left(win_t *win)
{
	char **grid = win->grid;

	for (int x = win->width - 1; x != -1; x--) {
		for (int y = 0; grid[y] != NULL; y++) {
			if (grid[y][x] == '*'&& (x == 0||
						grid[y][x - 1] == 'o')) {
				return (0);
			}
		}
	}
	return (1);
}
void	shape_left_translation(win_t *win)
{
	char **grid = win->grid;

	if (can_move_left(win) == 0)
		return;
	for (int x = 0; x != win->width - 1; x++) {
		for (int y = 0; grid[y] != NULL; y++) {
			if (grid[y][x] == '*') {
				grid[y][x] = ' ';
				grid[y][x - 1] = '*';
			}
		}
	}
}
