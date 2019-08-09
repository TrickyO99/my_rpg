/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** 
*/

#include <unistd.h>
#include "../../include/struct.h"

int	find_first_nbr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] > 47 && str[i] < 58)
		{
			return (i);
		}
		i = i + 1;
	}
	return (-1);
}

int	find_last_nbr(char *str, int i)
{
	while (str[i] > 47 && str[i] < 58)
	{
		i = i + 1;
	}
	return (i - 1);
}

int	find_nb(char *str, int i, int x)
{
	int nb = 0;
	int n = 1;

	while (x >= i)
	{
		nb = ((str[x] - 48) * n) + nb;
		n = n * 10;
		x = x - 1;
	}
	if (str[i - 1] == '-' && i > 0)
	{
		nb = nb * -1;
	}
	return (nb);
}

int	my_getnbr(char *str)
{
	int i = find_first_nbr(str);
	int x = find_last_nbr(str, i);

	if (i == -1 || (x - i) > 11)
	{
		return (0);
	}
	else
	{
		return (find_nb(str, i, x));
	}
}