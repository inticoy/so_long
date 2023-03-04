/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:40:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/04 22:24:54 by gyoon            ###   ########.fr       */
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

# define PX_X 32
# define PX_Y 32

typedef struct s_point	t_point;
typedef struct s_point	t_size;
typedef struct s_point	t_velocity;
typedef struct s_point	t_acceleration;

struct s_point
{
	int		x;
	int		y;
};

typedef struct s_image
{
	void		*img;
	t_size		size;
}	t_image;

typedef struct s_assets
{
	t_image	block[14];
	t_image	mario[12];
	t_image	coin[4];
	t_image	goomba[3];
}	t_assets;

typedef struct s_map
{
	char	**map;
	t_size	size;
}	t_map;


typedef struct s_player
{
	t_bool			is_left;
	int				remaining;
	t_point			pos;
	t_velocity		v;
	t_acceleration	a;
}	t_player;

typedef struct s_enemy
{
	t_bool		is_dead;
	t_point		pos;
	t_velocity	v;
}	t_enemy;

typedef struct s_collectible
{
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
	t_list				*collectibles;
	t_list				*enemies;
}	t_game;

void		close_game(t_game *g);

void		draw_game(t_game g);
void		draw_map(t_game g);
void		draw_player(t_game g);

int			hook_key_release(int keycode, t_game *game);
int			hook_key_press(int keycode, t_game *game);
int			hook_loop(t_game *game);

t_game		init_game(char *map_path);
t_key		init_key(void);
t_map		init_map(void);
t_player	init_player(t_map m);
t_point		init_point(int x, int y);

void		raise_error(char *msg);

t_assets	read_assets(void *mlx);
t_image		read_image(void *mlx, char *path);
t_map		read_map(char *path);

int			set_map(t_game *g, char *map_path);
int			set_player(t_game *g);

#endif