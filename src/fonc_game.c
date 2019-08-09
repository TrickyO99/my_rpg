/*
** EPITECH PROJECT, 2018
** fonc_game
** File description:
** fon_game.
*/

#include "../include/struct.h"

sfText	*create_texte(char *text, char *path_font, int size, sfColor colr)
{
	sfText *txt = sfText_create();
	sfFont *font = sfFont_createFromFile(path_font);

	sfText_setCharacterSize(txt, size);
	sfText_setFont(txt, font);
	sfText_setString(txt, text);
	sfText_setColor(txt, colr);
	return (txt);
}

sfSprite	*create_sprite(char *str)
{
	sfSprite *sprite = sfSprite_create();
	sfTexture *texture = sfTexture_createFromFile(str, NULL);

	sfSprite_setTexture(sprite, texture, sfFalse);
	return (sprite);
}

sfVector2i	get_mouse_pos(sfRenderWindow *window)
{
	sfVector2i pos;

	pos.x = sfMouse_getPositionRenderWindow(window).x;
	pos.y = sfMouse_getPositionRenderWindow(window).y;
	return (pos);
}

sfVector2i	get_sprite_pos(sfSprite *sprite)
{
	sfVector2i pos;

	pos.x = (float) sfSprite_getPosition(sprite).x;
	pos.y = (float) sfSprite_getPosition(sprite).y;
	return (pos);
}

sfSprite	*hoover2sprite(sfSprite *sp1, sfSprite *sp2, t_window *window)
{
	int s_width = sfSprite_getGlobalBounds(sp1).width;
	int s_height = sfSprite_getGlobalBounds(sp1).height;
	sfVector2i m_pos = get_mouse_pos(window->window);
	sfVector2i s_pos = get_sprite_pos(sp1);

	if (m_pos.x > s_pos.x && m_pos.x < (s_pos.x + s_width) &&
	m_pos.y > s_pos.y && m_pos.y < (s_pos.y + s_height)) {
		return (sp2);
	} else {
		return (sp1);
	}
}