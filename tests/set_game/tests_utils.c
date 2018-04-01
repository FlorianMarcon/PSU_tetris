/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_tetris.h"

Test(set_key_left, test1)
{
	game_t game = {.key_left = my_strdup("something")};

	cr_assert_eq(set_key_left(NULL, &game), 0);
	cr_assert_eq(set_key_left("\0sa", &game), 0);
	cr_assert_eq(set_key_left("a", NULL), 0);
	cr_assert_eq(set_key_left("a", &game), 1);
	cr_assert_str_eq(game.key_left, "a");
	cr_assert_eq(set_key_left("ab", &game), 1);
	cr_assert_str_eq(game.key_left, "ab");
}
Test(set_key_right, test1)
{
	game_t game = {.key_right = my_strdup("something")};

	cr_assert_eq(set_key_right(NULL, &game), 0);
	cr_assert_eq(set_key_right("\0sa", &game), 0);
	cr_assert_eq(set_key_right("a", NULL), 0);
	cr_assert_eq(set_key_right("a", &game), 1);
	cr_assert_str_eq(game.key_right, "a");
	cr_assert_eq(set_key_right("ab", &game), 1);
	cr_assert_str_eq(game.key_right, "ab");
}
Test(set_key_drop, test1)
{
	game_t game = {.key_drop = my_strdup("something")};

	cr_assert_eq(set_key_drop(NULL, &game), 0);
	cr_assert_eq(set_key_drop("\0sa", &game), 0);
	cr_assert_eq(set_key_drop("a", NULL), 0);
	cr_assert_eq(set_key_drop("a", &game), 1);
	cr_assert_str_eq(game.key_drop, "a");
	cr_assert_eq(set_key_drop("ab", &game), 1);
	cr_assert_str_eq(game.key_drop, "ab");
}
Test(set_key_turn, test1)
{
	game_t game = {.key_turn = my_strdup("something")};

	cr_assert_eq(set_key_turn(NULL, &game), 0);
	cr_assert_eq(set_key_turn("\0sa", &game), 0);
	cr_assert_eq(set_key_turn("a", NULL), 0);
	cr_assert_eq(set_key_turn("a", &game), 1);
	cr_assert_str_eq(game.key_turn, "a");
	cr_assert_eq(set_key_turn("ab", &game), 1);
	cr_assert_str_eq(game.key_turn, "ab");
}
Test(set_key_quit, test1)
{
	game_t game = {.key_quit = my_strdup("something")};

	cr_assert_eq(set_key_quit(NULL, &game), 0);
	cr_assert_eq(set_key_quit("\0sa", &game), 0);
	cr_assert_eq(set_key_quit("a", NULL), 0);
	cr_assert_eq(set_key_quit("a", &game), 1);
	cr_assert_str_eq(game.key_quit, "a");
	cr_assert_eq(set_key_quit("ab", &game), 1);
	cr_assert_str_eq(game.key_quit, "ab");
}
