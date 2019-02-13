/*
** EPITECH PROJECT, 2017
** create_tetrimino
** File description:
** create_tetrimino
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_tetris.h"

char	*recuperate_name(char *str)
{
	char *new = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;

	if (new == NULL)
		return (NULL);
	for (unsigned int a = 0; str[a] != '\0'; a++) {
		if (str[a] == '/')
			i = a + 1;
	}
	str = &str[i];
	i = 0;
	for (; str[i] != '.' && str[i] != '\0'; i++) {
		new[i] = str[i];
	}
	new[i] = '\0';
	return (new);
}

tetrimino_t	*create_tetrimino(char *path)
{
	int fd;
	tetrimino_t *tetri = malloc(sizeof(*tetri));

	if ((tetri = malloc(sizeof(*tetri))) == NULL)
		return (NULL);
	tetri->name = recuperate_name(path);
	if (tetri->name == NULL || (fd = open(path, O_RDONLY)) == -1) {
		free(tetri);
		return (NULL);
	}
	fill_tetrimino(fd, tetri);
	close(fd);
	return (tetri);
}
