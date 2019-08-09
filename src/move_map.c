/*
** EPITECH PROJECT, 2018
** move map
** File description:
** move_map
*/

#include "../include/struct.h"

int	move_direction_game(t_game *game, int dir, int *rect, int key)
{
	int ekt = 10;

	*rect = *rect + (ekt * dir);
	if (player_colision(game) == 0 || player_colision_mob(game, key, ekt) == 0)
	{
		*rect = *rect - (ekt * dir);
		return (0);
	}
	else
	{
		*rect = *rect - (ekt * dir) + (VITESSE_MAP1 * dir);
		return (1);
	}
}

int	move_left_right(int right, int left, t_game *game)
{
	if (right == 1 && GMP[game->map_nb]->rect.left < MAP1_XMAX)
	{
		if (move_direction_game(game, 1, &GMP[game->map_nb]->rect.left, KEY_RIGHT) == 1)
		{
			return (D_MOB_RIGHT);
		}
	}
	else if (left == 1 && GMP[game->map_nb]->rect.left > 0)
	{
		if (move_direction_game(game, -1, &GMP[game->map_nb]->rect.left, KEY_LEFT) == 1)
		{
			return (D_MOB_LEFT);
		}
	}
	return (0);
}

int	move_up_down(int up, int down, t_game *game)
{
	if (up == 1 && GMP[game->map_nb]->rect.top > 0)
	{
		if (move_direction_game(game, -1, &GMP[game->map_nb]->rect.top, KEY_UP) == 1)
		{
			return (D_MOB_UP);
		}	
	}
	else if (down == 1 && GMP[game->map_nb]->rect.top < MAP1_YMAX)
	{
		if (move_direction_game(game, 1, &GMP[game->map_nb]->rect.top, KEY_DOWN) == 1)
		{
			return (D_MOB_DOWN);
		}	
	}
	return (0);
}

void	move_map(t_input *input, t_map *map, t_game *game)
{
	game->d_y = move_up_down(input->up, input->down, game);
	game->d_x = move_left_right(input->right, input->left, game);
	sfSprite_setTextureRect(map->map, map->rect);
	sfSprite_setTextureRect(map->decor, map->rect);
}