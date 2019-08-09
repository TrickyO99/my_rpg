/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strat.
*/

#include "../include/my.h"
#include <stdlib.h>

char	*realloc_str_strcat(char *str, int x)
{
	char *zip = malloc(sizeof(char) * x);

	my_strcpy(zip, str);
	return (zip);
}

int	my_strlen_strcat(char *str)
{
	int i = 0;

	if (str == NULL || str[0] == '\0') {
		return (0);
	} else {
		while (str[i] != '\0') {
			i = i + 1;
		}
		return (i);
	}
}

char	*my_strcat(char *dest, char *str)
{
	int l_dest = my_strlen_strcat(dest);
	int i = 0;

	dest = realloc_str_strcat(dest, (l_dest + my_strlen_strcat(str)));
	while (str[i] != '\0') {
		dest[l_dest] = str[i];
		i = i + 1;
		l_dest = l_dest + 1;
	}
	dest[l_dest] = '\0';
	return (dest);
}