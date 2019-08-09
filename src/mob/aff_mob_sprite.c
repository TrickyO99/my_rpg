/*
** EPITECH PROJECT, 2018
** aff mob sprite
** File description:
** aff_mob_sprite
*/

#include "../../include/struct.h"

void	move_mob_up_down(int d, sfSprite *sprite)
{
	sfVector2f pos = sfSprite_getPosition(sprite);

	if (d == D_MOB_UP)
	{
		pos.y = pos.y + VITESSE_MAP1 + 2;
	}
	else if (d == D_MOB_DOWN)
	{
		pos.y = pos.y - VITESSE_MAP1 - 2;
	}
	sfSprite_setPosition(sprite, pos);
}

void	move_mob_left_right(int d, sfSprite *sprite)
{
	sfVector2f pos = sfSprite_getPosition(sprite);

	if (d == D_MOB_LEFT)
	{
		pos.x = pos.x + VITESSE_MAP1 + 2;
	}
	else if (d == D_MOB_RIGHT)
	{
		pos.x = pos.x - VITESSE_MAP1 - 2;
	}
	sfSprite_setPosition(sprite, pos);
}

void	aff_mob_sprite(t_mob *mob, t_game *game)
{
	move_mob_up_down(game->d_y, mob->sprite);
	move_mob_left_right(game->d_x, mob->sprite);
}

void	aff_all_mob_sprite(t_game *game)
{
	int x = 0;

	while (x < NB_MOB)
	{
		aff_mob_sprite(GMB[x], game);
		x = x + 1;
	}
}