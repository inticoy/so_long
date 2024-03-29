/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:40:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:39:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"

# define TITLE "Super Mario Bros."
# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

# ifdef SO_LONG_H
#  define BONUS 0
# else
#  ifdef SO_LONG_BONUS_H
#   define BONUS 1
#  endif
# endif

# ifndef ARM
#  define ARM 0
# endif

typedef t_bool					t_pressed;

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
typedef struct s_character		t_exit;

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
	KEY_R = 15,
	KEY_ESC = 53,
	KEY_SHIFT = 257
};

enum e_pixel
{
	UNIT_X = 32,
	UNIT_Y = 32,
	CHAR_X = 28,
	CHAR_Y = 28
};

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
	unsigned long long	movement;
	unsigned long long	frame_dead;
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
	t_image	item[4];
	t_image	enemy[3];
	t_image	exit;
}	t_assets;

typedef struct s_map_data
{
	t_bool				hit;
	unsigned long long	frame_hit;
	t_point				offset;
}	t_map_data;
typedef struct s_map
{
	char		**map;
	t_map_data	**data;
	t_size		size;
}	t_map;

typedef struct s_collectible
{
	t_point		pos;
	t_bool		is_collected;
	long long	frame_collected;
}	t_collectible;

typedef struct s_key
{
	t_pressed	w;
	t_pressed	a;
	t_pressed	s;
	t_pressed	d;
	t_pressed	r;
	t_pressed	shift;
	t_pressed	esc;
}	t_key;

typedef struct s_game
{
	unsigned long long	frame;
	unsigned long long	frame_clear;
	t_bool				clear;
	char				*map_path;
	void				*mlx;
	void				*win;
	t_size				size;
	t_map				map;
	t_assets			assets;
	t_key				key;
	t_player			player;	
	t_enemy				enemy;
	t_exit				exit;
	t_list				*collectibles;
}	t_game;

//			asset
t_assets	read_assets(void *mlx);

//			character
t_bool		is_overlapped(t_point pos1, t_point pos2);

//			collectible
void		draw_collectibles(t_game g);
int			get_remaining_collectibles(t_game *g);
void		set_collectibles(t_game *g);
void		update_collectibles(t_game *g);

//			enemy
void		draw_enemy(t_game g);
t_enemy		init_enemy(t_map m);
void		kill_enemy(t_game *g);
void		move_enemy(t_game *g);
int			set_enemy(t_game *g);
void		update_enemy_a(t_game *g);
void		update_enemy_pos(t_game *g);
void		update_enemy_v(t_game *g);

//			exit
void		draw_exit(t_game g);
t_exit		init_exit(t_map m);
void		move_exit(t_game *g);
int			set_exit(t_game *g);
void		update_exit_a(t_game *g);
void		update_exit_pos(t_game *g);
void		update_exit_v(t_game *g);

//			game
t_bool		check_game_clear(t_game *g);
void		clear_game(t_game *g);
void		close_game(t_game *g);
void		draw_game(t_game g);
t_game		init_game(char *map_path);
void		restart_game(t_game *g);
int			run_game(t_game *game);

//			image
t_image		read_image(void *mlx, char *path);

//			key
int			hook_key_release(int keycode, t_game *game);
int			hook_key_press(int keycode, t_game *game);
t_key		init_key(void);

//			error
void		raise_error(char *msg);

//			map
void		del_map(t_map *map);
void		draw_map(t_game g);
t_map		init_map(void);
void		modify_map(t_map *map);
t_map		read_map(char *map_path);
int			set_map(t_game *g, char *map_path);
t_bool		validate_map_path(char *map_path);
t_bool		validate_map(t_map map);

//			map/data
void		set_map_data(t_map *map);
void		update_map_data(t_game *g);

//			map/validation
t_bool		has_proper_char(t_map map);
t_bool		has_valid_route(t_map map);
t_bool		is_playable(t_map map);
t_bool		is_rectangle(t_map map);
t_bool		is_surrounded(t_map map);

//			player
void		draw_player(t_game g);
t_point		find_player(t_map map);
t_player	init_player(t_map m);
void		kill_player(t_game *g);
void		move_player(t_game *g);
int			set_player(t_game *g);
void		update_player_a(t_game *g);
void		update_player_pos(t_game *g);
void		update_player_v(t_game *g);

//			player/movement
void		display_movement(t_game g, t_bool bonus);
t_bool		has_movement(t_game *g);

//			point
t_point		init_point(int x, int y);

#endif