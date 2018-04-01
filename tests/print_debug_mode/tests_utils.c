/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_tetris.h"

Test(print_key, test1)
{
	game_t *game = initialisation_game();

	cr_assert_neq(game, NULL);
}
