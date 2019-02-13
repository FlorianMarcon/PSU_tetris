/*
** EPITECH PROJECT, 2017
** fill_tetrimino
** File description:
** fill_tetrimino
*/

#include <stdlib.h>
#include "my.h"
#include "header_tetris.h"

void	fill_settings(int fd, tetrimino_t *tetri)
{
	char *str = get_next_line(fd);
	char **tab;

	if (str == NULL || (tab = parsing_str(str, ' ' | '\t')) == NULL) {
		tetri->good = false;
		return;
	} else if (len_tab(tab) != 3)
		tetri->good = false;
	else {
		if (my_str_isnum(tab[0]) && my_str_isnum(tab[1]) &&
							my_str_isnum(tab[2])) {
			tetri->size_x = my_getnbr(tab[0]);
			tetri->size_y = my_getnbr(tab[1]);
			tetri->color = my_getnbr(tab[2]);
			tetri->good = true;
		} else
			tetri->good = false;
	}
}

void	verifictation_size_tetrimino(tetrimino_t *tetri)
{
	bool verify = false;
	char *str = NULL;

	for (unsigned int i = 0; tetri->shape[i] != NULL; i++) {
		str = tetri->shape[i];
		if (my_strlen(str) > tetri->size_x) {
			tetri->good = false;
			return;
		}
		if (my_strlen(str) == tetri->size_x)
			verify = true;
	}
	if (verify == false)
		tetri->good = false;
}
void	fill_shape(int fd, tetrimino_t *tetri)
{
	char *str;

	if ((tetri->shape = malloc(sizeof(char *) *
						(tetri->size_y + 1))) == NULL) {
		tetri->good = false;
		return;
	}
	for (int i = 0; i != tetri->size_y; i++) {
		if ((str = get_next_line(fd)) == NULL) {
			tetri->good = false;
			return;
		} if ((tetri->shape[i] = my_strdup(str)) == NULL) {
			tetri->good = false;
			return;
		}
		delete_end_char(tetri->shape[i], ' ');
		free(str);
	}
	tetri->shape[tetri->size_y] = NULL;
	verifictation_size_tetrimino(tetri);
}

void	fill_tetrimino(int fd, tetrimino_t *tetri)
{
	fill_settings(fd, tetri);
	if (tetri->good == true)
		fill_shape(fd, tetri);
}
