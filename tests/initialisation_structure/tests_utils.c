/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdbool.h>
#include <ncurses.h>
#include <criterion/criterion.h>
#include "header_tetris.h"

Test(initialisation_game, test1)
{
	game_t *game = initialisation_game();

	cr_assert_neq(game, NULL);
	cr_assert_str_eq(game->key_left, "^EOD");
	cr_assert_str_eq(game->key_right, "^EOC");
	cr_assert_str_eq(game->key_turn, "^EOA");
	cr_assert_str_eq(game->key_drop, "^EOB");
	cr_assert_str_eq(game->key_quit, "q");
	cr_assert_str_eq(game->key_pause, " ");
	cr_assert_eq(game->level, 1);
	cr_assert_eq(game->size_y, 20);
	cr_assert_eq(game->size_x, 10);
	cr_assert_eq(game->next, true);
}
Test(initialisation_game, test2)
{
	game_t *game = initialisation_game();

	cr_assert_neq(game, NULL);
	cr_assert_eq(game->debug_mode, false);
	cr_assert_eq(game->nb_tetriminos, 0);
	cr_assert_eq(game->shape, NULL);
}

Test(set_game, test1)
{
	char *av[] = {
		"./tetris"
		"-l", "A",
		"-q", "D",
		"-D", NULL
	};
	game_t *game = initialisation_game();

	cr_assert_eq(set_game(5, av, game), 1);
}
