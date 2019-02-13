/*
** EPITECH PROJECT, 2017
** read_blocked
** File description:
** read_no_blocked
*/

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include "header_tetris.h"
#include "my.h"
#include "header_play.h"

void	read_no_blocked(game_t *base)
{
	struct termios new;

	tcgetattr(0, &(base->old));
	new.c_lflag = base->old.c_lflag;
	new.c_lflag &= ~ (ICANON);
	new.c_cc[VMIN] = 0;
	new.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &new);
}

void	read_blocked(game_t *base)
{
	tcsetattr(0, TCSADRAIN, &(base->old));
}
