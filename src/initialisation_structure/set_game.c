/*
** EPITECH PROJECT, 2017
** set_game
** File description:
** set_game
*/

#include "header_tetris.h"
#include "option.h"

int	set_level(char *arg, game_t *game)
{
	if (arg == NULL || my_str_isnum(arg) == 0)
		return (0);
	game->level = my_getnbr(arg);
	return (1);
}
int	choice_option(int opt, game_t *game)
{
	int ret = 1;

	for (unsigned int i = 0; funct_set[i].label != '\0'; i++) {
		if (funct_set[i].label == opt) {
			ret = funct_set[i].ptr(optarg, game);
			return (ret);
		}
	}
	switch (opt) {
		case 'w': game->next = false;
			break;
		case 'D': game->debug_mode = true;
			break;
		case 'h': game->help = true;
			break;
		case '?': return (0);
		default : return (0);
	}
	return (ret);
}

int	set_game(int ac, char **av, game_t *game)
{
	int opt;

	if (game == NULL)
		return (0);
	while ((opt = getopt_long(ac, av, optstring, setting, NULL)) != -1) {
		if (choice_option(opt, game) == 0)
			return (0);
	}
	return (1);
}
