/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"
#include "header_play.h"

Test (end_round, test1)
{
	char **tab = malloc(sizeof(*tab) * 3);

	tab[0] = my_strdup("* * *  o\0");
	tab[1] = my_strdup("oooooooo\0");
	tab[2] = NULL;

	end_round(tab);
	cr_assert_str_eq(tab[0], "o o o  o\0");
	cr_assert_str_eq(tab[1], "oooooooo\0");
	cr_assert_eq(tab[2], NULL);
}

Test(shape_right_translation, test1)
{
	char **tab = malloc(sizeof(*tab) * 3);
	win_t win = {.width = 8, .height = 2, .grid = tab};

	tab[0] = my_strdup("* * *  o\0");
	tab[1] = my_strdup("oooooooo\0");
	tab[2] = NULL;
	my_printf("START\n");
	shape_right_translation(&win);
	my_printf("END\n");
	cr_assert_str_eq(tab[0], " * * * o\0");
	cr_assert_str_eq(tab[1], "oooooooo\0");
	cr_assert_eq(tab[2], NULL);
}

Test(shape_left_translation, test1)
{
	char **tab = malloc(sizeof(*tab) * 3);
	win_t win = {.width = 8, .height = 2, .grid = tab};

	tab[0] = my_strdup(" ** *  o\0");
	tab[1] = my_strdup("oooooooo\0");
	tab[2] = NULL;
	shape_left_translation(&win);
	cr_assert_str_eq(tab[0], "** *   o\0");
	cr_assert_str_eq(tab[1], "oooooooo\0");
	cr_assert_eq(tab[2], NULL);
}
Test(can_move_right, test1)
{
	char **tab = malloc(sizeof(*tab) * 3);
	win_t win = {.width = 8, .height = 2, .grid = tab};

	tab[0] = my_strdup(" ** *  o\0");
	tab[1] = my_strdup("oooooooo\0");
	tab[2] = NULL;
	cr_assert_eq(can_move_right(&win), 1);
	tab[0][7] = '*';
	cr_assert_eq(can_move_right(&win), 0);
}

Test(can_move_left, test1)
{
	char **tab = malloc(sizeof(*tab) * 3);
	win_t win = {.width = 8, .height = 2, .grid = tab};

	tab[0] = my_strdup(" ** *  o\0");
	tab[1] = my_strdup("oooooooo\0");
	tab[2] = NULL;
	cr_assert_eq(can_move_left(&win), 1);
	tab[0][0] = '*';
	cr_assert_eq(can_move_left(&win), 0);
}
