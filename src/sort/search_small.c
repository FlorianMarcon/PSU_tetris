/*
** EPITECH PROJECT, 2017
** search_small
** File description:
** search_small
*/

#include "header_tetris.h"
#include "my.h"

linked_list_t	*search_small(linked_list_t *list)
{
	linked_list_t *small = list;
	tetrimino_t *one = (tetrimino_t *)small->data;
	tetrimino_t *two;

	list = list->next;
	while (list != NULL) {
		two = (tetrimino_t *)list->data;
		if (my_strcmp(one->name, two->name) > 0) {
			small = list;
			one = (tetrimino_t *)small->data;
		}
		list = list->next;
	}
	return (small);
}
