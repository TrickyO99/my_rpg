/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

#include <stdio.h>

int	my_strlen(char *str)
{
	int nb = 0;

	while (str != NULL && str[nb] != '\0')
	{
		nb = nb + 1;
	}
	return (nb);
}