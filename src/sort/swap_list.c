/*
** EPITECH PROJECT, 2017
** swap_list
** File description:
** swap_list
*/

#include "my.h"

void	swap_list(linked_list_t *one, linked_list_t *two)
{
	void *sw = one->data;

	one->data = two->data;
	two->data = sw;
}
