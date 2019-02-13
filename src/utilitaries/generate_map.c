/*
** EPITECH PROJECT, 2017
** generate_map
** File description:
** generate_map
*/

#include <stdlib.h>
#include <unistd.h>

char	**generate_map(int width, int height)
{
	char **tab = malloc(sizeof(*tab) * (height + 1));
	int i = 0;

	if (tab == NULL)
		return (NULL);
	while (i != height) {
		tab[i] = malloc(sizeof(*tab[i]) * (width + 1));
		if (tab[i] == NULL) {
			free(tab);
			return (NULL);
		}
		for (int j = 0; j != width; j++)
			tab[i][j] = ' ';
		tab[i][width] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
