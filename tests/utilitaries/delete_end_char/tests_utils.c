/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_tetris.h"

Test(delete_end_char, test1)
{
	char str[5] = "sa  \0";

	delete_end_char(str, ' ');
	cr_assert_str_eq(str, "sa");
}
