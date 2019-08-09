/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** menu
*/

#include "../include/struct.h"

void	display_menu(t_window *win, t_menu *menu)
{
	sfRenderWindow_drawSprite(win->window, menu->back, NULL);
	if (menu->reprendre == 1)
		sfRenderWindow_drawSprite(win->window, menu->s_reprendre_on, NULL);
	else
		sfRenderWindow_drawSprite(win->window, menu->s_reprendre_off, NULL);
	if (menu->quitter == 1)
		sfRenderWindow_drawSprite(win->window, menu->s_quitter_on, NULL);
	else
		sfRenderWindow_drawSprite(win->window, menu->s_quitter_off, NULL);
	sfRenderWindow_display(win->window);

}

void	menu_intput(t_window *win, t_menu *menu)
{
	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
	if ((win->event).type == sfEvtClosed)
		sfRenderWindow_close(win->window);
	if ((win->event).type == sfEvtMouseButtonPressed)
		menu->click = 1;
	else
		menu->click = 0;
	}
}

void	check_action_menu(t_window *win, t_menu *menu)
{
	if (mouse_on_the_sprite(menu->s_reprendre_off, win->window) == 1)
		menu->reprendre = 1;
	else
		menu->reprendre = 0;
	if (mouse_on_the_sprite(menu->s_quitter_off, win->window) == 1)
		menu->quitter = 1;
	else
		menu->quitter = 0;
}

int	my_menu2(t_window *win, t_menu *menu)
{
	int opt = -1;

	sfRenderWindow_setMouseCursorVisible(win->window, sfTrue);
	while (sfRenderWindow_isOpen(win->window) && opt == -1) {
		menu_intput(win, menu);
		check_action_menu(win, menu);
		if (menu->click == 1 && menu->reprendre == 1)
			opt = 1;
		else if (menu->click == 1 && menu->quitter == 1)
			opt = 0;
		display_menu(win, menu);
	}
	menu->click = 0;
	menu->reprendre = 0;
	return (opt);
}

void	my_menu(t_window *win, t_menu *menu, t_input *input)
{
	int opt = 1;

	if (input->escape == 1)
	{
		opt = my_menu2(win, menu);
		input_init(input);
	}
	if (opt == 0)
	{
		sfRenderWindow_close(win->window);
	}
}