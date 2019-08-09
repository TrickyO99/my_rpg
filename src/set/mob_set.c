/*
** EPITECH PROJECT, 2018
** mob_set
** File description:
** mob_set
*/

#include "../../include/struct.h"

t_mob	*create_mob_struct(int x, int y)
{
	t_mob *mob = malloc(sizeof(*mob) * 2);

	mob->up[0] = *create_int_rect(y, x, 50, 50);
	mob->up[1] = *create_int_rect((y + 50), x, 50, 50);
	mob->down[0] = *create_int_rect((y + 100), x, 50, 50);
	mob->down[1] = *create_int_rect((y + 150), x, 50, 50);
	mob->left[0] = *create_int_rect(y, (x + 50), 50, 50);
	mob->left[1] = *create_int_rect((y + 50), (x + 50), 50, 50);
	mob->right[0] = *create_int_rect((y + 100), (x + 50), 50, 50);
	mob->right[1] = *create_int_rect((y + 150), (x + 50), 50, 50);
	return (mob);
}

void	mob_set(t_game *game)
{
	int i = 0;
	int arr[2][NB_MOB] = {{X_RONFLEX, X_COCO, X_AQUA, X_GAL, X_MATCH}, {Y_RONFLEX, Y_COCO, Y_AQUA, Y_GAL, X_GAL}};
	int pos[2][NB_MOB] = {{X_BOSS_MAP1, X_MOB_MAP1_1, X_MOB_MAP1_2, X_MOB_MAP1_3, X_MOB_MAP1_4}, {Y_BOSS_MAP1, Y_MOB_MAP1_1, Y_MOB_MAP1_2, Y_MOB_MAP1_3, Y_MOB_MAP1_4}};
	int opt[NB_MOB] = {TEXT, COMBAT, COMBAT, TEXT, TEXT};
	char *spr[NB_MOB] = {SPR_COCO, SPR_COCO, SPR_AQUA, SPR_COCO, SPR_COCO};
	char *txt[NB_MOB] = {T_RONFLEX, NULL, NULL, T_NO_PASS, T_NO_PASS};
	sfSprite *sprite = create_sprite("assets/mob/mob.png");

	game->d_x = 0;
	game->d_y = 0;
	while (i < NB_MOB)
	{
		GMB[i] = create_mob_struct(arr[0][i], arr[1][i]);
		GMB[i]->sprite = sfSprite_copy(sprite);
		sfSprite_setTextureRect(GMB[i]->sprite, GMB[i]->down[1]);
		set_origin_to_center(GMB[i]->sprite);
		set_pos_sprite(GMB[i]->sprite, pos[0][i], pos[1][i]);
		set_size_sprite(GMB[i]->sprite, 140);
		GMB[i]->opt = opt[i];
		GMB[i]->txt = txt[i];
		GMB[i]->pkm = create_sprite(spr[i]);
		set_size_sprite(GMB[i]->pkm, 150);
		GMB[i]->app = 1;
		i = i + 1;
	}
}