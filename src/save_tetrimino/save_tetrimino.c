/*
** EPITECH PROJECT, 2017
** save_tetrimino
** File description:
** save_tetrimino
*/

#include <sys/types.h>
#include <dirent.h>
#include "header_tetris.h"

int	is_good_extension(char *name)
{
	char ext[] = ".tetrimino";
	int i = 9;
	int a = my_strlen(name);

	if (a < 10)
		return (0);
	a--;
	while (i != -1) {
		if (ext[i--] != name[a--]) {
			return (0);
		}
	}
	return (1);
}
linked_list_t	*save_tetrimino(char *path_folder)
{
	DIR *dir = opendir(path_folder);
	linked_list_t *list = malloc(sizeof(*list));
	struct dirent *file;
	tetrimino_t *tetrimino = NULL;

	if (dir == NULL || list == NULL)
		return (NULL);
	list->next = NULL;
	while ((file = readdir(dir)) != NULL) {
		if (is_good_extension(file->d_name) == 1 &&
				(tetrimino = create_tetrimino(my_strcat
				(path_folder, file->d_name))) != NULL) {
			create_node(list, tetrimino);
		}
	}
	list = list->next;
	closedir(dir);
	return (list);
}
