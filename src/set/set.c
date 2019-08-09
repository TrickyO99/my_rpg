/*
** EPITECH PROJECT, 2018
** set
** File description:
** set
*/

#include "../../include/struct.h"

t_window	*window_set(void)
{
	t_window *window = malloc(sizeof(*window));

	window->video.width = 1920;
	window->video.height = 1080;
	window->video.bitsPerPixel = 32;
	window->window = sfRenderWindow_create(window->video,
	"my_rpg", sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window->window, 120);
	sfRenderWindow_setVerticalSyncEnabled(window->window, sfTrue);
	return (window);
}

t_player	*player_set(void)
{
	t_player *player = malloc(sizeof(*player));

	player->sprite = create_sprite("assets/player/player.png");
	player->rect_down = *create_int_rect(0, 0, 31, 62);
	player->rect_left = *create_int_rect(64, 0, 32, 64);
	player->rect_up = *create_int_rect(128, 0, 32, 64);
	player->rect_right = *create_int_rect(192, 0, 32, 64);
	sfSprite_setTextureRect(player->sprite, player->rect_down);
	set_origin_to_center(player->sprite);
	set_size_sprite(player->sprite, 200);
	set_pos_sprite(player->sprite, (1920 / 2), (1080 / 2));
	player->phs = 2;
	player->hold_dir = KEY_DOWN;
	player->time = sfClock_create();
	player->lag = 1;
	player->col = -1;
	return (player);
}

t_input	*input_set(void)
{
	t_input *input = malloc(sizeof(*input));

	input->up = 0;
	input->left = 0;
	input->down = 0;
	input->right = 0;
	input->entrer = 0;
	input->escape = 0;
	input->space = 0;
	input->click = 0;
	return (input);
}

t_text	*text_set(void)
{
	t_text	*txt = malloc(sizeof(*txt));

	txt->bull = create_sprite("assets/text/bull.png");
	txt->bull = set_scale(5.8, 2, txt->bull);
	set_pos_sprite(txt->bull, 0, 860);
	txt->txt = create_texte("", "assets/text/font.ttf", 50, sfWhite);
	set_pos_text(70, 900, txt);
	txt->str = NULL;
	txt->clock = sfClock_create();
	txt->ett = 0;
	return (txt);
}

t_game	*game_set(void)
{
	t_game *game = malloc(sizeof(*game));

	game->map_nb = 0;
	GW = window_set();
	GP = player_set();
	GI = input_set();
	GT = text_set();
	GC = init_comb();
	GM = init_menu();
	mob_set(game);
	set_map(game);
	return (game);
}