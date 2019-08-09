/*
** EPITECH PROJECT, 2018
** loading.c
** File description:
** loading
*/

#include "../include/struct.h"

t_load	*init_load(void)
{
	t_load	*load = malloc(sizeof(*load));

	load->load_e = create_sprite("assets/menu/loading_empty.png");
	load->load_f = create_sprite("assets/menu/loading_full.png");
	load->back = create_sprite("assets/menu/back_menu_escape.png");
	set_pos_sprite(load->load_e, 300, 500);
	set_pos_sprite(load->load_f, 300, 500);
	load->clock = sfClock_create();
	return (load);
}

void	load_display(t_window *win, t_load *load)
{
	sfRenderWindow_drawSprite(win->window, load->back, NULL);
	sfRenderWindow_drawSprite(win->window, load->load_e, NULL);
	sfRenderWindow_drawSprite(win->window, load->load_f, NULL);
	sfRenderWindow_display(win->window);
}

void	my_loading(t_window *win)
{
	t_load	*load = init_load();
	int	i = 0;

	while (i < 1103) {
		if (check_time(load->clock, 0.01) == 1) {
			i += 10;
		}
		load->r_load = *create_int_rect(0, 0, i, 37);
		sfSprite_setTextureRect(load->load_f, load->r_load);
		load_display(win, load);
	}
}