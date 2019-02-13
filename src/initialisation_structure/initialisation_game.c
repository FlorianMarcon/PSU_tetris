/*
** EPITECH PROJECT, 2017
** initialisation_game
** File description:
** initialisation_game
*/

#include <stdbool.h>
#include <ncurses.h>
#include <stdlib.h>
#include "header_tetris.h"

void	initialisation_key(game_t *game)
{
	game->key_left = my_strdup("^EOD");
	game->key_right = my_strdup("^EOC");
	game->key_turn = my_strdup("^EOA");
	game->key_drop = my_strdup("^EOB");
	game->key_quit = my_strdup("q");
	game->key_pause = my_strdup(" ");
}
void	initialisation_tetri_for_game(game_t *game)
{
	game->shape = save_tetrimino("./tetriminos/");
	game->nb_tetriminos = len_list(game->shape);
	if (game->shape != NULL) {
		game->next_shape = get_shape_random(game);
		game->write_next = true;
		sort_list(game->shape);
	} else
		game->in_game = false;
}
game_t	*initialisation_game(void)
{
	game_t *game = malloc(sizeof(*game));

	if (game == NULL)
		return (NULL);
	initialisation_key(game);
	game->level = 1;
	game->size_y = 20;
	game->size_x = 10;
	game->next = true;
	game->debug_mode = false;
	game->help = false;
	game->in_game = true;
	game->clock = 0;
	initialisation_tetri_for_game(game);
	return (game);
}
