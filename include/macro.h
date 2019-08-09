/*
** EPITECH PROJECT, 2018
** machr
** File description:
** macro
*/

#ifndef MACRO_H_
#define MACRO_H_

// macro
#define GW (game->window)
#define GP (game->player)
#define GI (game->input)
#define GMP (game->map)
#define GMB (game->mob)
#define GT (game->text)
#define GC (game->comb)
#define GM (game->menu)

// INPUT KEY
#define KEY_RIGHT (0)
#define KEY_LEFT (1)
#define KEY_DOWN (2)
#define KEY_UP (3)
#define KEY_ESCAPE (4)
#define KEY_ENTRER (5)
#define KEY_ESPACE (6)

// PLAYER
#define MAX_RECT (5);
#define WIDTH_RECT_PLAYER (32);
#define VITESSE_MAP1 (2)

//limit map
//map 1
#define MAP1_XMAX (2240)
#define MAP1_YMAX (3200)

//GNL
#define READ_SIZE (4)

//MOB
#define NB_MOB (5)
#define D_MOB_UP (1)
#define D_MOB_DOWN (2)
#define D_MOB_RIGHT (3)
#define D_MOB_LEFT (4)

//OPT MOB
#define COMBAT (1)
#define TEXT (2)

//TEXT MOB
#define T_RONFLEX ("Zzzzzzzzzzzzzzzzzzzzzzzzzzz (Snorlax is sleeping, I need to find the pokeflute)")
#define T_NO_PASS ("You can't cross the bridge because the game is still in developpement")

//MOB ASSET COO
#define X_RONFLEX (900)
#define Y_RONFLEX (1800)
#define X_COCO (1400)
#define Y_COCO (1200)
#define X_AQUA (0)
#define Y_AQUA (1800)
#define X_MATCH (900)
#define Y_MATCH (800)
#define X_GAL (800)
#define Y_GAL (1400)

//MOB POS
#define X_BOSS_MAP1 (690)
#define Y_BOSS_MAP1 (-310)
#define X_MOB_MAP1_1 (450)
#define Y_MOB_MAP1_1 (-600)
#define X_MOB_MAP1_2 (-50)
#define Y_MOB_MAP1_2 (300)
#define X_MOB_MAP1_3 (1800)
#define Y_MOB_MAP1_3 (-680)
#define X_MOB_MAP1_4 (1800)
#define Y_MOB_MAP1_4 (-750)

//SPR_PKM
#define SPR_COCO ("assets/combat/pkm/coco.png")
#define SPR_AQUA ("assets/combat/pkm/aqua.png")

#endif /* !MACRO_H_ */
