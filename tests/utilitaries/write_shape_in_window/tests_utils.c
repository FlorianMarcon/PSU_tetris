/*
** EPITECH PROJECT, 2017
** write_shape_in_window
** File description:
** write_shape_in_window
*/

#include <criterion/criterion.h>
#include "header_play.h"
#include "header_tetris.h"

Test(write_shape_in_window, test1)
{
	char *array[] = {
		my_strdup("          "),
		my_strdup("          "),
		my_strdup("          "),
		my_strdup("          "),
		NULL
	};
	char *shape[5] = {"******", "* * *\0", NULL};
	win_t win = {.grid = array, .width = 10, .height = 4};
	tetrimino_t tetri = {.shape = shape, .size_x = 6, .size_y = 2};

	write_shape_in_window(&win, &tetri);
	cr_assert_str_eq(array[0], "  ******  ");
	cr_assert_str_eq(array[1], "  * * *   ");
}
