/*
** EPITECH PROJECT, 2017
** set_key
** File description:
** set_key
*/

#include "header_tetris.h"
#include <ncurses.h>

int	set_key_pause(char *arg, game_t *game)
{
	if (arg == NULL || my_strlen(arg) == 0 || game == NULL)
		return (0);
	free(game->key_pause);
	game->key_pause = my_strdup(arg);
	return (1);
}

int	set_size(char *arg, game_t *game)
{
	char **tab = NULL;

	if (arg == NULL || my_strlen(arg) < 3 || game == NULL)
		return (0);
	tab = parsing_str(arg, ',');
	if (tab == NULL || len_tab(tab) != 2)
		return (0);
	else if (my_str_isnum(tab[0]) == 0 || my_str_isnum(tab[1]) == 0)
		return (0);
	else {
		game->size_y = my_getnbr(tab[0]);
		game->size_x = my_getnbr(tab[1]);
		return (1);
	}
}
