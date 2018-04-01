/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_tetris.h"

Test(fill_settings, test1)
{
	int fd = open("data/bad_argu_one.test", O_RDONLY);
	tetrimino_t tetri;

	if (fd == -1)
		return;
	fill_settings(fd, &tetri);
	cr_assert_eq(tetri.good, false);
	close(fd);
}
Test(fill_settings, test2)
{
	int fd = open("../tetriminos/bar.tetrimino", O_RDONLY);
	tetrimino_t tetri;

	if (fd == -1)
		return;
	fill_settings(fd, &tetri);
	cr_assert_eq(tetri.good, true);
	cr_assert_eq(tetri.size_x, 1);
	cr_assert_eq(tetri.size_y, 4);
	cr_assert_eq(tetri.color, 2);
	close(fd);
}

Test(verifictation_size_tetrimino, test1)
{
	char *shape[] = {"****", "* * *", NULL};
	tetrimino_t tetri = {	.shape = shape,
				.size_x = 5,
				.size_y = 2,
				.good = true};

	verifictation_size_tetrimino(&tetri);
	cr_assert_eq(tetri.good, true);
	tetri.size_x = 6;
	verifictation_size_tetrimino(&tetri);
	cr_assert_eq(tetri.good, false);
	tetri.size_x = 4;
	tetri.good = true;
	verifictation_size_tetrimino(&tetri);
	cr_assert_eq(tetri.good, false);
}

Test(fill_shape, test2)
{
	int fd = open("./data/bad_argu_two.test", O_RDONLY);
	tetrimino_t tetri = {.good = true};

	fill_settings(fd, &tetri);
	fill_shape(fd, &tetri);
	cr_assert_eq(tetri.good, false);
	close(fd);
}

Test(fill_shape, test1)
{
	int fd = open("../tetriminos/bar.tetrimino", O_RDONLY);
	tetrimino_t tetri = {.good = true};

	fill_settings(fd, &tetri);
	fill_shape(fd, &tetri);
	cr_assert_str_eq(tetri.shape[0], "*");
	cr_assert_eq(tetri.good, true);
	close(fd);
}
