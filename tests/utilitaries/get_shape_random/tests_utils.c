/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_play.h"
#include "my.h"
#include "header_tetris.h"

Test(get_n_node, test1)
{
	linked_list_t list[3];
	linked_list_t *res;

	list[0].next = &list[1];
	list[1].next = &list[2];
	list[2].next = NULL;
	res = get_n_node(&list[0], 1);
	cr_assert_neq(res, NULL);
	res = get_n_node(&list[0], 5);
	cr_assert_eq(res, NULL);
}

Test(get_n_node, test2)
{
	linked_list_t *list = save_tetrimino("data/");
	sort_list(list);
	tetrimino_t *tetri;

	cr_assert(len_list(list) > 5);
	list = get_n_node(list, 2);
	cr_assert_neq(list, NULL);
	tetri = (tetrimino_t *)list->data;
	cr_assert_neq(tetri, NULL);
}

Test(get_shape_random, test1)
{
	game_t game = {.shape = save_tetrimino("data/")};
	tetrimino_t *tmp = NULL;

	cr_assert_neq(game.shape, NULL);
	game.nb_tetriminos = len_list(game.shape);
	tmp = get_shape_random(&game);
	cr_assert_neq(tmp, NULL);
}
