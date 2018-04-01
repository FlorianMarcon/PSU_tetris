/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_tetris.h"
#include "my.h"

Test(search_small, test1)
{
	linked_list_t *list = save_tetrimino("../tetriminos/");
	linked_list_t *small;

	cr_assert_neq(list, NULL);
	cr_assert(len_list(list) > 4);
	small = search_small(list);
	cr_assert_str_eq(((tetrimino_t *)small->data)->name, "4");
}
