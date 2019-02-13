/*
** EPITECH PROJECT, 2017
** get_shape_random
** File description:
** get_shape_random
*/

#include <stdbool.h>
#include <time.h>
#include "header_play.h"
#include "header_tetris.h"

linked_list_t	*get_n_node(linked_list_t *list, int n)
{
	int i = 1;

	while (i != n && list != NULL) {
		i++;
		list = list->next;
	}
	return (list);
}
tetrimino_t	*get_shape_random(game_t *game)
{
	int var;
	tetrimino_t *tetri = NULL;
	linked_list_t *tmp = NULL;

	srand((unsigned int)time(0));
	while (tetri == NULL) {
		var = rand() % (game->nb_tetriminos + 1);
		while ((tmp = get_n_node(game->shape, var)) == NULL) {
			var = rand() % game->nb_tetriminos;
		}
		tetri = (tetrimino_t *)tmp->data;
		if (tetri->good == false)
			tetri = NULL;
	}
	return (tetri);
}
