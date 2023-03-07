/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:40:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/07 21:41:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

# include "libft.h"

# define TITLE "Super Mario Bros."

enum e_event
{
	E_KEY_PRESS = 2,
	E_KEY_RELEASE = 3
};

enum e_mask
{
	M_KEY_PRESS = 1L,
	M_KEY_RELEASE = 2L
};

enum e_key_code
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_SHIFT = 257
};

enum e_px
{
	PX_X = 32,
	PX_Y = 32
};

typedef struct s_point			t_point;
typedef struct s_point			t_size;
typedef struct s_point			t_velocity;
typedef struct s_point			t_acceleration;

typedef enum e_character_status	t_character_status;
typedef enum e_character_status	t_player_status;
typedef enum e_character_status	t_enemy_status;

typedef struct s_character		t_character;
typedef struct s_character		t_player;
typedef struct s_character		t_enemy;

struct s_point
{
	int		x;
	int		y;
};

enum e_character_status
{
	LEFT = -1,
	DEAD = 0,
	RIGHT = 1,
};

struct s_character
{
	t_character_status	status;
	int					remaining;
	t_point				pos;
	t_velocity			v;
	t_acceleration		a;
};

typedef struct s_image
{
	void		*img;
	t_size		size;
}	t_image;

typedef struct s_assets
{
	t_image	block[14];
	t_image	player[3][6];
	t_image	collectible[5];
	t_image	enemy[3];
	t_image	peach;
}	t_assets;

typedef struct s_map
{
	char	**map;
	t_size	size;
}	t_map;

typedef struct s_collectible
{
	t_point		pos;
	t_bool		is_collected;
	long long	frame_collected;
}	t_collectible;


typedef struct s_key
{
	t_bool	press_w;
	t_bool	press_a;
	t_bool	press_s;
	t_bool	press_d;
	t_bool	press_shift;
	t_bool	press_esc;
}	t_key;

typedef struct s_game
{
	unsigned long long	frame;
	void				*mlx;
	void				*win;
	t_size				size;
	t_map				map;
	t_assets			assets;
	t_key				key;
	t_player			player;	
	t_enemy				enemy;
	t_list				*collectibles;
}	t_game;

void		draw_collectibles(t_game g);
void		set_collectibles(t_game *g);

void		draw_enemy(t_game g);
t_enemy		init_enemy(t_map m);
void		move_enemy(t_game *g);
int			set_enemy(t_game *g);

void		draw_exit(t_game g);

void		close_game(t_game *g);
void		draw_game(t_game g);
int			hook_loop(t_game *game);
t_game		init_game(char *map_path);

int			hook_key_release(int keycode, t_game *game);
int			hook_key_press(int keycode, t_game *game);
t_key		init_key(void);

void		raise_error(char *msg);

void		draw_map(t_game g);
t_map		init_map(void);
t_map		read_map(char *path);
int			set_map(t_game *g, char *map_path);

void		calc_player_a(t_game *g);
void		calc_player_pos(t_game *g);
void		calc_player_v(t_game *g);
void		draw_player(t_game g);
t_player	init_player(t_map m);
void		move_player(t_game *g);
int			set_player(t_game *g);

t_point		init_point(int x, int y);

t_assets	read_assets(void *mlx);
t_image		read_image(void *mlx, char *path);

#endif