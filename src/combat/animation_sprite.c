/*
** EPITECH PROJECT, 2018
** animation_sprite.C
** File description:
** animation_sprite
*/

#include "../../include/struct.h"

sfIntRect	create_rect(int left, int top, int width, int height)
{
	sfIntRect	rect;

	rect.left = left;
	rect.top = top;
	rect.width = width;
	rect.height= height;
	return (rect);
}

void	anim_attaque(t_comb *comb, t_window *win, sfSprite *sprite)
{
	int	i = 0;
	int	j = 0;

	comb->attaque = 1;
	while (comb->attaque == 1) {
		if (j == 5) {
			i++;
			j = 0;
		}
		comb->r_attaque = create_rect((i * 192), (j * 192), 192, 192);
		sfSprite_setTextureRect(comb->s_attaque, comb->r_attaque);
		display_fight(win, comb, sprite);
		if (i == 2 && j == 0)
			comb->attaque = 0;
		else
			while (check_time(comb->clock, 0.1) != 1);
		j++;
	}
}

void	anim_magie(t_comb *comb, t_window *win, sfSprite *sprite)
{
	int	i = 0;
	int	j = 0;

	comb->magie = 1;
	while (comb->magie == 1) {
		if (j == 5) {
			i++;
			j = 0;
		}
		comb->r_magie = create_rect((i * 192), (j * 192), 192, 192);
		sfSprite_setTextureRect(comb->s_magie, comb->r_magie);
		display_fight(win, comb, sprite);
		if (i == 1 && j == 1)
			comb->magie = 0;
		else
			while (check_time(comb->clock, 0.1) != 1);
		j++;
	}
}