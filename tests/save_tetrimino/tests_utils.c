/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include "header_tetris.h"
#include <criterion/criterion.h>
#include <stdbool.h>

Test(is_good_extension, test1)
{
	cr_assert_eq(is_good_extension("salut.tetrimino"), 1);
	cr_assert_eq(is_good_extension("5.tetrimino"), 1);
	cr_assert_eq(is_good_extension("s.tetrimino"), 1);
	cr_assert_eq(is_good_extension("salut.ttrimino"), 0);
	cr_assert_eq(is_good_extension("saluttetrimino"), 0);
	cr_assert_eq(is_good_extension("etrimino"), 0);
}
Test(recuperate_name, test1)
{
	char *new = recuperate_name("hamed.tetrimino");

	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new, "hamed");
	free(new);
	new = recuperate_name("tetri/hamed.tetrimino");
	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new, "hamed");
}

Test(recuperate_name, test2)
{
	char *new = recuperate_name("tettri/hamed.tetrimino");

	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new, "hamed");
	free(new);
	new = recuperate_name("tetri/hamed.tetrimino");
	cr_assert_neq(new, NULL);
	cr_assert_str_eq(new, "hamed");
}
