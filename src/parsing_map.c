/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parsing_map
*/

#include "../include/struct.h"

void	aff_map(int **map)
{
	int x = 0;
	int y = 0;

	while (map[x] != NULL)
	{
		while (map[x][y] != 0)
		{
			my_put_nbr(map[x][y]);
			my_putchar(',');
			y = y + 1;
		}
		my_putchar('\n');
		y = 0;
		x = x + 1;
	}
}

int	*arr_to_int_arr(char **arr)
{
	int x = 0;
	int *nb = NULL;

	while (arr[x] != NULL)
	{
		nb = my_int_realloc(nb, x, 1);
		nb[x] = my_getnbr(arr[x]);
		free(arr[x]);
		x = x + 1;
	}
	nb[x] = 0;
	return (nb);
}

int	nb_malloc_file(char *path)
{
	int fd = open(path, O_RDONLY);
	char buff[2];
	int size = 1;
	int nb = 0;

	if (fd == -1)
	{
		return (-1);
	}
	while (size != 0)
	{
		size = read(fd, buff, 1);
		if (buff[0] == '\n')
		{
			nb = nb + 1;
		}
	}
	close(fd);
	return (nb);
}

int	**parsing_map(char *path)
{
	int i = 0;
	char *str = NULL;
	char **arr = NULL;
	int **map = malloc(sizeof(int*) * (nb_malloc_file(path) + 1));
	int fd = open(path, O_RDONLY);

	while ((str = get_next_line(fd)) != NULL)
	{
		arr = my_str_to_word_array(str, ',');
		map[i] = arr_to_int_arr(arr);
		i = i + 1;
	}
	map[i] = NULL;
	close(fd);
	free(str);
	return (map);
}
