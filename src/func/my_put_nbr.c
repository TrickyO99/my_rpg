/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** 
*/

#include "../../include/struct.h"

void	my_put_positif(int nb)
{
	char str[30];
	int i = 0;

	while (nb > 0)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i = i + 1;
	}
	str[i] = '\0';
	my_revstr(str);
	my_putstr(str);
}

int	my_put_nbr(int nb)
{
	if (nb == 0)
	{
		my_putchar(48);
	}
	else if (nb > 0)
	{
		my_put_positif(nb);
	}
	else if (nb < 0)
	{
		my_putchar('-');
		my_put_positif(ABS(nb));
	}
	return (nb);
}
