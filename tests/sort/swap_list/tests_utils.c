/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "header_tetris.h"
#include "my.h"

Test(swap_list, test1)
{
	linked_list_t *list = malloc(sizeof(*list) * 2);
	char *one = my_strdup("one\0");
	char *two = my_strdup("two\0");

	list->next = &list[1];
	list->data = (void *)one;
	list[1].next = NULL;
	list[1].data = (void *)two;
	swap_list(list, list->next);
	one = (char *)list->data;
	two = (char *)list[1].data;
	cr_assert_str_eq(one, "two");
	cr_assert_str_eq(two, "one");
}
