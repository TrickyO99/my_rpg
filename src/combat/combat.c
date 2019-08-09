/*
** EPITECH PROJECT, 2018
** combat.c
** File description:
** combat
*/

#include "../../include/struct.h"

void	choose_action(t_window *win, t_comb *comb, sfSprite *sprite, int *app)
{
	if (comb->click == 1 && mouse_on_the_sprite(comb->b_attaque, win->window) == 1)
	{
		anim_attaque(comb, win, sprite);
		*app = 1;
	}
	else if (comb->click == 1 && mouse_on_the_sprite(comb->b_magie, win->window) == 1)
	{
		anim_magie(comb, win, sprite);
		*app = 1;
	}	
	else if (comb->click == 1 && mouse_on_the_sprite(comb->b_fuite, win->window) == 1)
		comb->end = 1;
	else {
		comb->end = 0;
		comb->attaque = 0;
		comb->magie = 0;
	}
}

void	fight_input(t_comb *comb, t_window *win)
{
	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if ((win->event).type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		if ((win->event).type == sfEvtMouseButtonPressed)
			comb->click = 1;
		else
			comb->click = 0;
	}
}

int	my_fight(sfSprite *sprite, t_game *game, t_mob *mob)
{
	int app = 0;
	sfClock *clo = sfClock_create();

	sfRenderWindow_setMouseCursorVisible(GW->window, sfTrue);
	while (sfRenderWindow_isOpen(GW->window) && GC->end == 0 && app == 0) {
		fight_input(GC, GW);
		choose_action(GW, GC, sprite, &app);
		display_fight(GW, GC, sprite);
		
	}
	GC->click = 0;
	if (app == 1)
	{
		mob->app = 0;
		sfClock_restart(clo);
		while (check_time(clo, 1) == 0)
		{
		}
	}
	sfRenderWindow_setMouseCursorVisible(GW->window, sfFalse);
	return (0);
}