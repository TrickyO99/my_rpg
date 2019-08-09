/*
** EPITECH PROJECT, 2018
** set map
** File description:
** set_map
*/

#include "../../include/struct.h"

t_map	*set_map_1(void)
{
	t_map *map = malloc(sizeof(*map));

	map->map = create_sprite("assets/map/map1/map1.png");
	map->decor = create_sprite("assets/map/map1/map2.png");
	set_size_sprite(map->map, 200);
	set_size_sprite(map->decor, 200);
	map->rect = *create_int_rect(1200, 900, 1920, 1080);
	sfSprite_setTextureRect(map->decor, map->rect);
	sfSprite_setTextureRect(map->map, map->rect);
	map->tiled_map = parsing_map("assets/map/map1/map.csv");
	return (map);
}

t_map	*set_map_2(void)
{
	t_map *map = malloc(sizeof(*map));

	map->map = create_sprite("assets/map/map2/map.png");
	map->decor = create_sprite("assets/map/no_decor.png");
	set_size_sprite(map->map, 200);
	set_size_sprite(map->decor, 200);
	map->rect = *create_int_rect(1700, 1200, 1920, 1080);
	sfSprite_setTextureRect(map->decor, map->rect);
	sfSprite_setTextureRect(map->map, map->rect);
	map->tiled_map = parsing_map("assets/map/map2/map.csv");
	return (map);
}

t_map	*set_map_3(void)
{
	t_map *map = malloc(sizeof(*map));

	map->map = create_sprite("assets/map/map3/map.png");
	map->decor = create_sprite("assets/map/no_decor.png");
	set_size_sprite(map->map, 200);
	set_size_sprite(map->decor, 200);
	map->rect = *create_int_rect(1400, 1000, 1920, 1080);
	sfSprite_setTextureRect(map->decor, map->rect);
	sfSprite_setTextureRect(map->map, map->rect);
	map->tiled_map = parsing_map("assets/map/map3/map.csv");
	return (map);
}

void	set_map(t_game *game)
{
	GMP[0] = set_map_1();
	GMP[1] = set_map_2();
	GMP[2] = set_map_3();
}