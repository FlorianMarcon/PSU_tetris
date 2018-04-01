/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_tetris.h"

Test(set_key_pause, test1)
{
	game_t game = {.key_pause = my_strdup("something")};

	cr_assert_eq(set_key_pause(NULL, &game), 0);
	cr_assert_eq(set_key_pause("\0sa", &game), 0);
	cr_assert_eq(set_key_pause("a", NULL), 0);
	cr_assert_eq(set_key_pause("a", &game), 1);
	cr_assert_str_eq(game.key_pause, "a");
	cr_assert_eq(set_key_pause("ab", &game), 1);
	cr_assert_str_eq(game.key_pause, "ab");
}

Test(set_size, test1)
{
	game_t game;

	cr_assert_eq(set_size(NULL, &game), 0);
	cr_assert_eq(set_size("\0sa", &game), 0);
	cr_assert_eq(set_size("a", NULL), 0);
	cr_assert_eq(set_size("13,56", &game), 1);
	cr_assert_eq(game.size_x, 56);
	cr_assert_eq(game.size_y, 13);
}
