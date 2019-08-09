/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/struct.h"

int	word_len(char const *str , char sep)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**my_str_to_word_array(char const *str , char sep)
{
	char **tab = malloc(sizeof(char *) * (word_len(str, sep) + 1));
	int char_tab = 0;
	int idx_str = 0;
	int idx_tab = 0;

	while (str[idx_str] != '\0') {
		tab[idx_tab] = malloc(sizeof(char) * (my_strlen(str) + 1));
		while (str[idx_str] == sep) {
			idx_str++;
		}
		while (str[idx_str] != sep && str[idx_str] != '\0') {
			tab[idx_tab][char_tab] = str[idx_str];
			idx_str++;
			char_tab++;
		}
		tab[idx_tab][char_tab] = '\0';
		idx_tab++;
		char_tab = 0;
	}
	tab[idx_tab] = NULL;
	return (tab);
}
