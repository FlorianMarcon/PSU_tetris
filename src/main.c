/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"
#include "header_tetris.h"
#include <ncurses.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdbool.h>

int	main(int ac, char **av)
{
	game_t *game = initialisation_game();

	if (set_game(ac, av, game) == 0 || game->in_game == false) {
		my_printf("retry with --help\n");
		return (0);
	} else if (game->debug_mode == true && game->in_game == true) {
		print_debug_mode(game);
		main_loop(game);
	} else if (game->help == true) {
		print_help(av[0]);
		return (84);
	} else
		main_loop(game);
	free(game);
	return (0);
}
