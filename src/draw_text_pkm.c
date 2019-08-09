/*
** EPITECH PROJECT, 2018
** draw_text_pkm
** File description:
** draw_text_pkm
*/

#include "../include/struct.h"

int	check_time(sfClock *clock, float time_to_wait)
{
	sfTime	time =sfClock_getElapsedTime(clock);
	float	seconde = sfTime_asSeconds(time);

	if (seconde > time_to_wait) {
		sfClock_restart(clock);
		return (1);
	}
	return (0);
}

sfSprite	*set_scale(float x, float y, sfSprite *sprite)
{
	sfVector2f	scale;

	scale.x = x;
	scale.y = y;
	sfSprite_scale(sprite, scale);
	return (sprite);
}


char	*my_strncpy(char *dest, char const *src, int n)
{
	int	i = 0;

	while (src[i] != '\0' && i != n) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	my_draw_text(t_text *txt)
{
	static	int	pos = 0;
	char		*text;

	if (check_time(txt->clock, 0.05) == 1) {
		text = malloc(sizeof(char) * (pos + 1));
		if (pos < 65)
			text = my_strncpy(text, txt->str, pos);
		else {
			txt->str++;
			text = my_strncpy(text, txt->str, 65);
		}
		pos++;
		sfText_setString(txt->txt, text);
		if (my_strlen(text) == 1 && pos > 2) {
			pos = 0;
			return (1);
		}
		free(text);
	}
	return (0);
}