/*
** EPITECH PROJECT, 2017
** write_shape_in_window
** File description:
** write_shape_in_window
*/

#include "header_play.h"
#include "my.h"

void	write_shape_in_window(win_t *win, tetrimino_t *tetri)
{
	int y = 0;
	int x = 0;
	int decalage = (win->width / 2) - (tetri->size_x / 2);

	while (y != win->height && tetri->shape[y] != NULL) {
		x = 0;
		while (x != win->width && tetri->shape[y][x] != '\0') {
			win->grid[y][x + decalage] = tetri->shape[y][x];
			x++;
		}
		y++;
	}
}
