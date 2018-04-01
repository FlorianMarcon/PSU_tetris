/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "header_tetris.h"
#include "header_play.h"

int	get_line_full(char **grid)
{
	int y = 0;
	int x = 0;

	while (grid[y] != NULL) {
		x = 0;
		while (1) {
			if (grid[y][x] == ' ')
				break;
			if (grid[y][x] == '\0')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}
void	delete_line(win_t *game)
{
	int y;

	while ((y = get_line_full(game->grid)) != -1) {
		for (int j = y; j != 1; j--) {
			for (int x = 0; game->grid[j][x] != '\0'; x++) {
				game->grid[j][x] = game->grid[j - 1][x];
			}
		}
	}
}
void	event_key(game_t *base, win_t *game)
{
	char *str = malloc(sizeof(*str) * 2);

	if (read(0, str, 2) > 0) {
		if (str[0] == base->key_quit[0])
			base->in_game = false;
		if (str[0] == base->key_right[0])
			shape_right_translation(game);
		if (str[0] == base->key_left[0])
			shape_left_translation(game);
		if (str[0] == base->key_drop[0])
			move_shape(game);
	}
	free(str);
}
void	event(game_t *base, win_t *game)
{
	if (base->write_next == true) {
		write_shape_in_window(game, base->next_shape);
		base->next_shape = get_shape_random(base);
		base->write_next = false;
	}
	if ((float)((clock() / CLOCKS_PER_SEC) - base->clock) > 0.2) {
		base->clock = clock() / CLOCKS_PER_SEC;
		if (move_shape(game) == 0) {
			base->write_next = true;
			end_round(game->grid);
		}
		delete_line(game);
	}
	event_key(base, game);
}
