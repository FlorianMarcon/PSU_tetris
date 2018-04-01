/*
** EPITECH PROJECT, 2017
** set_key
** File description:
** set_key
*/

#include "header_tetris.h"
#include <ncurses.h>

int	set_key_left(char *arg, game_t *game)
{
	if (arg == NULL || my_strlen(arg) == 0 || game == NULL)
		return (0);
	free(game->key_left);
	game->key_left = my_strdup(arg);
	return (1);
}
int	set_key_right(char *arg, game_t *game)
{
	if (arg == NULL || my_strlen(arg) == 0 || game == NULL)
		return (0);
	free(game->key_right);
	game->key_right = my_strdup(arg);
	return (1);
}
int	set_key_drop(char *arg, game_t *game)
{
	if (arg == NULL || my_strlen(arg) == 0 || game == NULL)
		return (0);
	free(game->key_drop);
	game->key_drop = my_strdup(arg);
	return (1);
}
int	set_key_turn(char *arg, game_t *game)
{
	if (arg == NULL || my_strlen(arg) == 0 || game == NULL)
		return (0);
	free(game->key_turn);
	game->key_turn = my_strdup(arg);
	return (1);
}
int	set_key_quit(char *arg, game_t *game)
{
	if (arg == NULL || my_strlen(arg) == 0 || game == NULL)
		return (0);
	free(game->key_quit);
	game->key_quit = my_strdup(arg);
	return (1);
}
