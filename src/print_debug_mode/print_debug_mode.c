/*
** EPITECH PROJECT, 2017
** print_debug_mode
** File description:
** print_debug_mode
*/

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <ncurses.h>
#include "header_tetris.h"
#include "my.h"

void	print_key_other(game_t *game)
{
	if (game->key_quit[0] != ' ')
		my_printf("Key Quit :  %s\n", game->key_quit);
	else
		my_printf("Key Quit :  (space)\n");
	if (game->key_pause[0] != ' ')
		my_printf("Key Pause :  %s\n", game->key_pause);
	else
		my_printf("Key Pause :  (space)\n");

}
void	print_key_move(game_t *game)
{
	if (game->key_left[0] != ' ')
		my_printf("Key Left :  %s\n", game->key_left);
	else
		my_printf("Key Left :  (space)\n");
	if (game->key_right[0] != ' ')
		my_printf("Key Right :  %s\n", game->key_right);
	else
		my_printf("Key Right :  (space)\n");
	if (game->key_turn[0] != ' ')
		my_printf("Key Turn :  %s\n", game->key_turn);
	else
		my_printf("Key Turn :  (space)\n");
	if (game->key_drop[0] != ' ')
		my_printf("Key Drop :  %s\n", game->key_drop);
	else
		my_printf("Key Drop :  (space)\n");
}
void	print_other(game_t *game)
{
	if (game->next == true)
		my_printf("Next :  Yes\n");
	else
		my_printf("Next :  No\n");
	my_printf("Level :  %i\n", game->level);
	my_printf("Size :  %i*%i\n", game->size_y, game->size_x);
	my_printf("Tetriminos :  %i\n", game->nb_tetriminos);
}

void	print_debug_mode(game_t *game)
{
	char *str = malloc(sizeof(*str) * 2);

	struct termios old;
	struct termios new;

	my_printf("*** DEBUG MODE ***\n");
	print_key_move(game);
	print_key_other(game);
	print_other(game);
	print_list_shape(game->shape);
	my_printf("Press any key to start Tetris\n");
	tcgetattr(0, &old);
	new.c_lflag = old.c_lflag;
	new.c_lflag &= ~ (ICANON);
	new.c_cc[VMIN] = 0;
	new.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &new);
	while (read(0, str, 2) <= 0);
	tcsetattr(0, TCSADRAIN, &old);
	free(str);
}
