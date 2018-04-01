/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_tetris.h"

Test(generate_map, test1)
{
	char **tab = generate_map(3, 4);

	cr_assert_neq(tab, NULL);
	cr_assert_eq(tab[4], NULL);
	cr_assert_eq(tab[0][0], ' ');
	cr_assert_eq(tab[0][3], '\0');
}
