/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"

Test(parsing_str, test1)
{
	char **tab = parsing_str("2 3 6", ' ' | '\t');

	cr_assert_neq(tab, NULL);
	cr_assert_eq(len_tab(tab), 3);
	cr_assert_str_eq(tab[0], "2");
	cr_assert_str_eq(tab[1], "3");
	cr_assert_str_eq(tab[2], "6");
}

Test(parsing_str, test2)
{
	char **tab = parsing_str("2 3  \t 6", ' ' | '\t');

	cr_assert_neq(tab, NULL);
	cr_assert_eq(len_tab(tab), 3);
	cr_assert_str_eq(tab[0], "2");
	cr_assert_str_eq(tab[1], "3");
	cr_assert_str_eq(tab[2], "6");
	cr_assert_eq(tab[3], NULL);
}
Test(parsing_str, test3)
{
	char **tab = parsing_str("26", ' ' | '\t');

	cr_assert_neq(tab, NULL);
	cr_assert_eq(len_tab(tab), 1);
	cr_assert_str_eq(tab[0], "26");
	cr_assert_eq(tab[1], NULL);
}
