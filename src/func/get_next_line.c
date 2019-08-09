/*
** EPITECH PROJECT, 2018
** toto
** File description:
** toto
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../../include/struct.h"

char	*my_strcat_gnl(char *str, char *buff, int size, int opt)
{
	static int nb = 1;
	char *zip = malloc(sizeof(char) * (READ_SIZE * nb) + 2);
	int i = 0;
	int x = 0;

	if (opt == 0)
		nb = 0;
	my_memset(zip, 32, ((READ_SIZE + nb)));
	nb = nb + 1;
	while (str != NULL && str[i] != '\0') {
		zip[i] = str[i];
		i = i + 1;
	}
	while (x < size) {
		zip[i] = buff[x];
		x = x + 1;
		i = i + 1;
	}
	zip[i] = '\0';
	return (zip);
}

int	check_line(char *str)
{
	int x = 0;
	int i = 0;

	while (str != NULL && str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			x = x + 1;
		}
		i = i + 1;
	}
	return (x);
}

int	find_malloc_line(char *str, int nb)
{
	int i = 0;

	while (str[nb] != '\n' && str[nb] != '\0')
	{
		i = i + 1;
		nb = nb + 1;
	}
	return (i);
}

char	*find_str(char *str, int *nb)
{
	int mal = find_malloc_line(str, *nb);
	char *zip = malloc(sizeof(char) * mal + 1);
	int i = 0;

	my_memset(zip, 32, mal);
	while (str[*nb] != '\n' && str[*nb] != '\0')
	{
		zip[i] = str[*nb];
		i = i + 1;
		*nb = *nb + 1;
	}
	if (str[*nb] != '\0')
	{
		*nb = *nb + 1;
	}
	zip[i] = '\0';
	return (zip);
}

char	*get_next_line(int fd)
{
	static char *str = NULL;
	static int nb = 0;
	static int size = READ_SIZE;
	char buff[READ_SIZE];
	int x = 0;

	if (fd == 0) {
		nb = 0;
		str = NULL;
		size = READ_SIZE;
	}
	while (size == READ_SIZE || str[nb] != '\0') {
		x = check_line(&str[nb]);
		if (size == READ_SIZE && x == 0) {
			size = read(fd, buff, READ_SIZE);
			str = my_strcat_gnl(str, buff, size, fd);
		}
		else {
			return (find_str(str, &nb));
		}
	}
	return (NULL);
}
