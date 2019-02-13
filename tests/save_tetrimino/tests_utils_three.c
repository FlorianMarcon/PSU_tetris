/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include "header_tetris.h"

Test(fill_tetrimino, test1)
{
	int fd = open("tetriminos/bar.tetrimino", O_RDONLY);
	tetrimino_t tetri = {.good = true};

	if (fd == -1)
		return;
	fill_tetrimino(fd, &tetri);
	cr_assert_eq(tetri.good, true);
	cr_assert_eq(tetri.size_x, 1);
	cr_assert_eq(tetri.size_y, 4);
	close(fd);
}
Test(fill_tetrimino, test2)
{
	int fd = open("tetriminos/4.tetrimino", O_RDONLY);
	tetrimino_t tetri = {.good = true};

	if (fd == -1)
		return;
	fill_tetrimino(fd, &tetri);
	cr_assert_eq(tetri.good, false);
	close(fd);
}

Test(save_tetrimino, test1)
{
	linked_list_t *list = save_tetrimino("data/");

	cr_assert_neq(list, NULL);
	cr_assert(len_list(list) == 6);
}
