/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"
#include "header_tetris.h"

Test(sort_list, test1)
{
	linked_list_t *list = save_tetrimino("../tetriminos/");
	tetrimino_t *tetri;

	cr_assert_neq(list, NULL);
	sort_list(list);
	tetri = (tetrimino_t *)list->data;
	cr_assert_str_eq(tetri->name, "4");
	list = get_lastnode(list);
	tetri = (tetrimino_t *)list->data;
	cr_assert_str_eq(tetri->name, "square");
}
