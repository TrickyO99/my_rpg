/*
** EPITECH PROJECT, 2018
** player_input
** File description:
** player_input
*/

#include "../include/struct.h"

void	list_input_key(int *pntrfunc[], t_input *input)
{
	pntrfunc[0] = &input->right;
	pntrfunc[1] = &input->left;
	pntrfunc[2] = &input->down;
	pntrfunc[3] = &input->up;
	pntrfunc[4] = &input->escape;
	pntrfunc[5] = &input->entrer;
	pntrfunc[6] = &input->space;
	pntrfunc[7] = &input->click;
}

void	player_input2(t_input *input, sfKeyCode key_c, int nb)
{
	int *pntrfunc[8];
	sfKeyCode key[8] = {sfKeyRight, sfKeyLeft, sfKeyDown, sfKeyUp,
	sfKeyEscape, sfKeyReturn, sfKeySpace, sfMouseLeft};
	int x = 0;

	list_input_key(pntrfunc, input);
	while (x < 8)
	{
		if (key_c == key[x])
		{
			*pntrfunc[x] = nb;
			
		}
		x = x + 1;
	}
}

void	player_input(t_input *input, t_window *window, int stop)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event))
	{
		if ((window->event).type == sfEvtClosed)
		{
			sfRenderWindow_close(window->window);
		}
		if (((window->event).type == sfEvtKeyPressed ||
		(window->event).type == sfEvtMouseButtonPressed) &&
		stop != 1)
		{
			player_input2(input, window->event.key.code, 1);
		}
		if ((window->event).type == sfEvtKeyReleased || 
		(window->event).type == sfEvtMouseButtonReleased)
		{
			player_input2(input, window->event.key.code, 0);
		}
	}
}