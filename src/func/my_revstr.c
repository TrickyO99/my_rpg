/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** 
*/

char	*my_revstr(char *str)
{
	int i = 0;
	char x;
	int n = 0;

	while (str[i] != '\0')
		i = i + 1;
	i = i - 1;
	while ( n < i) {
		x = str[i];
		str[i] = str[n];
		str[n] = x;
		n = n + 1;
		i = i - 1;
	}
	return (str);
}
