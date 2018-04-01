/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ncurses.h>
#include "header_tetris.h"

Test(print_arrow, test1)
{
	cr_redirect_stdout();
	print_arrow(KEY_UP);
	cr_assert_stdout_eq_str("^EOA\n\0");
}
Test(print_arrow, test2)
{
	cr_redirect_stdout();
	print_arrow(KEY_DOWN);
	cr_assert_stdout_eq_str("^EOB\n\0");
}
Test(print_arrow, test3)
{
	cr_redirect_stdout();
	print_arrow(KEY_RIGHT);
	cr_assert_stdout_eq_str("^EOC\n\0");
}
Test(print_arrow, test4)
{
	cr_redirect_stdout();
	print_arrow(KEY_LEFT);
	cr_assert_stdout_eq_str("^EOD\n\0");
}
