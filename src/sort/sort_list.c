/*
** EPITECH PROJECT, 2017
** sort_list
** File description:
** sort_list
*/

#include "header_tetris.h"
#include "my.h"

#include "header_tetris.h"
#include "my.h"

void	sort_list(linked_list_t *list)
{
	linked_list_t *swap;

	while (list != NULL) {
		swap = search_small(list);
		swap_list(list, swap);
		list = list->next;
	}
}
