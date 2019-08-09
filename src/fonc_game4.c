/*
** EPITECH PROJECT, 2018
** fonc_game
** File description:
** fonc_game4
*/

#include "../include/struct.h"

sfIntRect	copy_rect(sfIntRect rect)
{
	sfIntRect rect1;

	rect1.top = rect.top;
	rect1.left = rect.left;
	rect1.width = rect.width;
	rect1.height = rect.height;
	return (rect1);
}

sfSprite	*set_origin_to_center(sfSprite *sprite)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
	sfVector2f mid;

	mid.x = rect.width / 2;
	mid.y = rect.height / 2;
	sfSprite_setOrigin(sprite, mid);
	return (sprite);
}

int	*my_int_realloc(int *i, int lenght, int nb)
{
	int *ii = malloc(sizeof(int) * (lenght + nb + 1));
	int x = 0;

	while (lenght > 0)
	{
		ii[x] = i[x];
		lenght = lenght - 1;
		x = x + 1;
	}
	free(i);
	return (ii);
}

sfSprite	*set_origin_to_coo(sfSprite *sprite, int x, int y)
{
	sfVector2f pos;

	pos.x = x;
	pos.y = y;
	sfSprite_setOrigin(sprite, pos);
	return (sprite);
}

int	pos_on_the_sprite(sfSprite *sprite, int x, int y)
{
	sfFloatRect rec = sfSprite_getGlobalBounds(sprite);
	sfVector2f pos;

	sprite = set_origin_to_coo(sprite, 0, 0);
	pos = sfSprite_getPosition(sprite);
	if ((x > pos.x && x < (pos.x + rec.width)) &&
	y > pos.y && y < (pos.y + rec.height))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	sprite = set_origin_to_center(sprite);
}