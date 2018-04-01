/*
** EPITECH PROJECT, 2017
** print_list_shape
** File description:
** print_list_shape
*/

#include "header_tetris.h"

void	print_shape(tetrimino_t *tetri)
{
	char **shape = tetri->shape;

	my_printf("Tetriminos :  Name %s :  \0", tetri->name);
	if (tetri->good == false) {
		my_printf("Error\n");
		return;
	}
	my_printf("Size %i*%i :  \0", tetri->size_x, tetri->size_y);
	my_printf("Color %i :\n", tetri->color);
	for (unsigned int i = 0; shape[i] != NULL; i++)
		my_printf("%s\n", shape[i]);
}

void	print_list_shape(linked_list_t *list)
{
	tetrimino_t *tetri;

	while (list != NULL) {
		tetri = (tetrimino_t *)list->data;
		if (tetri != NULL)
			print_shape(tetri);
		list = list->next;
	}
}
