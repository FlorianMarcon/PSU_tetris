/*
** EPITECH PROJECT, 2017
** delete_end_char
** File description:
** delete_end_char
*/

#include "header_tetris.h"
#include "my.h"

void	delete_end_char(char *str, char c)
{
	int i;

	if (str == NULL)
		return;
	i = my_strlen(str) - 1;
	while (i != 0 && str[i] == c)
		i--;
	str[i + 1] = '\0';
}
