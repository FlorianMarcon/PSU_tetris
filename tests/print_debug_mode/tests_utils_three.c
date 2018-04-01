/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_tetris.h"

Test(print_shape, test1)
{
	char *shape[] = {"**", "*", "**", NULL};
	tetrimino_t tetri = {"flo", 2, 3, 4, shape, true};
	char str[] = "Tetriminos :  Name flo :  Size 2*3 :  Color 4 :\n\
**\n*\n**\n\0";

	cr_redirect_stdout();
	print_shape(&tetri);
	cr_assert_stdout_eq_str(str);
}
