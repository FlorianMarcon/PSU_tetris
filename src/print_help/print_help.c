/*
** EPITECH PROJECT, 2017
** print_help
** File description:
** print_help
*/

#include "header_tetris.h"
#include "my.h"
#include "help.h"

void	print_help(char *name)
{
	int i = 1;

	my_printf("Usage:  %s [options]\n", name);
	while (message_help[i] != NULL)
		my_printf("%s\0", message_help[i++]);
}
