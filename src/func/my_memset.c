/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** my_memset
*/

void	*my_memset(char *str, int c, int size)
{
	int i = 0;

	while (str && i < size)
	{
		str[i] = c;
		i = i + 1;
	}
	str[i] = '\0';
	return (str);
}