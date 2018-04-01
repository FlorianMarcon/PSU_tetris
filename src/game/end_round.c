/*
** EPITECH PROJECT, 2017
** end_round
** File description:
** end_round
*/

#include "header_play.h"
#include "header_tetris.h"

void	end_round(char **grid)
{
	for (int y = 0; grid[y] != NULL; y++) {
		for (int x = 0; grid[y][x] != '\0'; x++) {
			if (grid[y][x] == '*')
				grid[y][x] = 'o';
		}
	}
}
