/*
** EPITECH PROJECT, 2017
** struct
** File description:
** 
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "macro.h"

typedef struct	s_window
{
	sfRenderWindow *window;
	sfVideoMode video;
	sfEvent event;
} t_window;

typedef struct s_player
{
	sfSprite *sprite;
	sfIntRect rect_up;
	sfIntRect rect_down;
	sfIntRect rect_left;
	sfIntRect rect_right;
	int phs;
	int hold_dir;
	sfClock *time;
	int lag;
	int pos_x;
	int pos_y;
	int col;
} t_player;

typedef struct s_input
{
	int up;
	int down;
	int left;
	int right;
	int space;
	int entrer;
	int escape;
	int click;
} t_input;

typedef struct s_map
{
	sfSprite *map;
	sfSprite *decor;
	sfIntRect rect;
	int **tiled_map;
} t_map;

typedef struct s_mob
{
	sfSprite *sprite;
	sfIntRect up[2];
	sfIntRect down[2];
	sfIntRect left[2];
	sfIntRect right[2];
	sfSprite *pkm;
	int opt;
	int app;
	char *txt;
} t_mob;

typedef	struct	s_text
{
	char		*str;
	sfText		*txt;
	sfSprite	*bull;
	sfClock		*clock;
	int ett;
} t_text;

typedef struct s_comb 
{
	int		end;
	int		click;
	int		attaque;
	int		magie;
	sfSprite	*back;
	sfSprite	*b_attaque;
	sfSprite	*b_magie;
	sfSprite	*b_fuite;
	sfSprite	*s_attaque;
	sfSprite	*s_magie;
	sfIntRect	r_attaque;
	sfIntRect	r_magie;
	sfClock		*clock;
} t_comb;

typedef struct s_menu
{
	int		reprendre;
	int		quitter;
	int		click;
	sfSprite	*back;
	sfSprite	*s_reprendre_off;
	sfSprite	*s_reprendre_on;
	sfSprite	*s_quitter_off;
	sfSprite	*s_quitter_on;
} t_menu;

typedef struct s_game
{
	t_window *window;
	t_player *player;
	t_input *input;
	t_map *map[3];
	t_mob *mob[NB_MOB];
	t_text *text;
	t_comb *comb;
	t_menu *menu;
	int map_nb;
	int d_x;
	int d_y;
} t_game;

typedef struct s_load
{
	sfSprite *load_e;
	sfSprite *load_f;
	sfSprite *back;
	sfIntRect r_load;
	sfClock *clock;
} t_load;

typedef struct s_start
{
	int jouer;
	int quitter;
	int click;
	sfSprite *back;
	sfSprite *s_jouer_off;
	sfSprite *s_jouer_on;
	sfSprite *s_quitter_off;
	sfSprite *s_quitter_on;
} t_start;

typedef struct s_music
{
	sfMusic	*aquali;
	sfMusic	*noadkoko;
	sfMusic	*ronflex;
	sfMusic	*attack;
	sfMusic	*magic;
	sfMusic	*run;
	sfMusic	*damage_taken;
	sfMusic	*start_battle;
	sfMusic	*change_map;
	sfMusic	*main_theme;
} t_music;

t_game	*game_set(void);
sfText	*create_texte(char *text, char *path_font, int size, sfColor colr);
sfSprite	*create_sprite(char *str);
sfVector2i	get_mouse_pos(sfRenderWindow *window);
sfVector2i	get_sprite_pos(sfSprite *sprite);
sfSprite	*hoover2sprite(sfSprite *sp1, sfSprite *sp2, t_window *window);
sfVector2f	convert_sfvector2i_to_sfvector2f(sfVector2i vec2i);
void	display_and_cursor(t_window *window);
int	mouse_on_the_sprite(sfSprite *sprite, sfRenderWindow *window);
void	set_pos_sprite(sfSprite *sprite, float x, float y);
void	aff_good_rect(sfSprite *sp, sfIntRect rb, sfIntRect rh, sfRenderWindow *window, int b);
void	set_size_sprite(sfSprite *sprite, int size);
char	*int_to_string(int nb);
int	compare_str(char *zip, char *src);
char	*float_to_str(float nb);
sfIntRect	*create_int_rect(int top, int left, int width, int height);
t_input	*input_set(void);
void	player_input(t_input *input, t_window *window, int stop);
void	list_input_key(int *pntrfunc[], t_input *input);
void	aff_player(t_input *input, t_player *player);
t_input	*input_init(t_input *input);
void	set_map(t_game *game);
void	move_map(t_input *input, t_map *map, t_game *game);
sfIntRect	copy_rect(sfIntRect rect);
int	move_direction_player(int key, t_player *player);
sfSprite	*set_origin_to_center(sfSprite *sprite);
int	**parsing_map(char *path);
char	**my_str_to_word_array(char const *str, char separator);
void	*my_memset(char *str, int c, int size);
int	*my_int_realloc(int *i, int lenght, int nb);
void	player_and_map1(t_map *map, t_player *player);
int	player_colision(t_game *game);
void	mob_set(t_game *game);
void	aff_mob_sprite(t_mob *mob, t_game *game);
sfSprite	*set_origin_to_coo(sfSprite *sprite, int x, int y);
int	pos_on_the_sprite(sfSprite *sprite, int x, int y);
int	player_colision_mob(t_game *game, int key, int ekt);
void	aff_sprite_mob(t_game *game, sfRenderWindow *window);
void	aff_all_mob_sprite(t_game *game);
int	my_draw_text(t_text *txt);
t_text	*text_set(void);
void	set_pos_text(float x, float y, t_text *txt);
sfSprite	*set_scale(float x, float y, sfSprite *sprite);
void	aff_text_or_combat(t_game *game);
int	my_fight(sfSprite *sprite, t_game *game, t_mob *mob);
void	display_fight(t_window *win, t_comb *comb, sfSprite *sprite);
void	anim_attaque(t_comb *comb, t_window *win, sfSprite *sprite);
void	anim_magie(t_comb *comb, t_window *win, sfSprite *sprite);
t_comb	*init_comb(void);
int	check_time(sfClock *clock, float time_to_wait);
void	my_menu(t_window *win, t_menu *menu, t_input *input);
t_menu	*init_menu(void);
int	check_time(sfClock *clock, float time_to_wait);
void my_loading(t_window *win);
t_music	*init_music(void);
int start(t_window *win);

#endif