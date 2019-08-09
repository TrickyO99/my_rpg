/*
** EPITECH PROJECT, 2018
** set2
** File description:
** set2
*/

#include "../../include/struct.h"

t_comb	*init_comb(void)
{
	t_comb	*comb = malloc(sizeof(*comb));

	comb->b_attaque = create_sprite("assets/combat/b_attaque.png");
	comb->b_magie = create_sprite("assets/combat/b_magie.png");
	comb->b_fuite = create_sprite("assets/combat/b_fuite.png");
	comb->back = create_sprite("assets/combat/back.png");
	comb->s_attaque = create_sprite("assets/combat/attaque.png");
	comb->s_magie = create_sprite("assets/combat/magie.png");
	comb->back = set_origin_to_center(comb->back);
	comb->clock = sfClock_create();
	comb->attaque = 0;
	comb->magie = 0;
	comb->end = 0;
	comb->click = 0;
	return (comb);
}

t_menu	*init_menu(void)
{
	t_menu *menu = malloc(sizeof(*menu));

	menu->s_quitter_on = create_sprite("assets/menu/quitter-h.png");
	menu->s_quitter_off = create_sprite("assets/menu/quitter.png");
	menu->s_reprendre_on = create_sprite("assets/menu/reprendre-h.png");
	menu->s_reprendre_off = create_sprite("assets/menu/reprendre.png");
	menu->back = create_sprite("assets/menu/back_menu_escape.png");
	set_size_sprite(menu->s_quitter_off, 50);
	set_size_sprite(menu->s_quitter_on, 50);
	set_size_sprite(menu->s_reprendre_off, 50);
	set_size_sprite(menu->s_reprendre_on, 50);
	set_pos_sprite(menu->s_reprendre_off, 920, 360);
	set_pos_sprite(menu->s_quitter_off, 920, 730);
	set_pos_sprite(menu->s_reprendre_on, 920, 360);
	set_pos_sprite(menu->s_quitter_on, 920, 730);
	menu->reprendre = 0;
	menu->quitter = 0;
	menu->click = 0;
	return (menu);
}

t_music	*init_music(void)
{
	t_music	*music = malloc(sizeof(*music));

	music->aquali = sfMusic_createFromFile("assets/music/aquali_sfx.ogg");
	music->noadkoko = sfMusic_createFromFile("assets/music/noadkoko_sfx.ogg");
	music->ronflex = sfMusic_createFromFile("assets/music/ronflex_sfx.ogg");
	music->attack = sfMusic_createFromFile("assets/music/sword_sfx.ogg");
	music->magic = sfMusic_createFromFile("assets/music/magic_sfx.ogg");
	music->run = sfMusic_createFromFile("assets/music/run_sfx.ogg");
	music->damage_taken = sfMusic_createFromFile("assets/music/damage_taken.ogg");
	music->start_battle = sfMusic_createFromFile("assets/music/battle_starts.ogg");
	music->change_map = sfMusic_createFromFile("assets/music/map_change.ogg");
	music->main_theme = sfMusic_createFromFile("assets/music/main_music.ogg");
	return (music);
}