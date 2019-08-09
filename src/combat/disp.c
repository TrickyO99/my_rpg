/*
** EPITECH PROJECT, 2018
** disp.c
** File description:
** disp
*/

#include "../../include/struct.h"

void	disp_attaque(t_window *win, t_comb *comb, sfSprite *sprite)
{
	sfVector2f	origin = sfSprite_getOrigin(sprite);

	sfSprite_setOrigin(comb->s_attaque, origin);
	set_pos_sprite(comb->s_attaque, 920, 420);
	sfRenderWindow_drawSprite(win->window, comb->s_attaque, NULL);
}

void	disp_magie(t_window *win, t_comb *comb, sfSprite *sprite)
{
	sfVector2f	origin = sfSprite_getOrigin(sprite);

	sfSprite_setOrigin(comb->s_magie, origin);
	set_pos_sprite(comb->s_magie, 920, 420);
	sfRenderWindow_drawSprite(win->window, comb->s_magie, NULL);
}

void	display_fight(t_window *win, t_comb *comb, sfSprite *sprite)
{
	set_pos_sprite(sprite, 960, 460);
	set_pos_sprite(comb->back, (1920 / 2), (1080 / 2));
	set_pos_sprite(comb->b_attaque, 500, 680);
	set_pos_sprite(comb->b_magie, 800, 680);
	set_pos_sprite(comb->b_fuite, 1100, 680);
	sfRenderWindow_drawSprite(win->window, comb->back, NULL);
	sfRenderWindow_drawSprite(win->window, comb->b_attaque, NULL);
	sfRenderWindow_drawSprite(win->window, comb->b_magie, NULL);
	sfRenderWindow_drawSprite(win->window, comb->b_fuite, NULL);
	sfRenderWindow_drawSprite(win->window, sprite, NULL);
	if (comb->attaque == 1)
		disp_attaque(win, comb, sprite);
	else if (comb->magie == 1)
		disp_magie(win, comb, sprite);
	sfRenderWindow_display(win->window);
}