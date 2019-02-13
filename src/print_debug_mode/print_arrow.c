/*
** EPITECH PROJECT, 2017
** print_arrow
** File description:
** print_arrow
*/

#include <ncurses.h>
#include "my.h"

void	print_arrow(int arrow)
{
	switch (arrow) {
		case KEY_UP: my_printf("^EOA\n\0");
			break;
		case KEY_DOWN: my_printf("^EOB\n\0");
			break;
		case KEY_RIGHT: my_printf("^EOC\n\0");
			break;
		case KEY_LEFT: my_printf("^EOD\n\0");
			break;
		case ' ': my_printf("(space)\n\0");
			break;
		default: break;
	}
}
