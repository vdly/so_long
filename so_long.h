/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:17:55 by johii             #+#    #+#             */
/*   Updated: 2023/12/08 19:04:24 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include "misc_utils/libft/libft.h"
# include "misc_utils/libft/ft_printf/ft_printf.h"
# include "misc_utils/get_next_line/get_next_line.h"

//bonus
typedef struct s_coin
{
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
}	t_coins;

typedef struct s_player
{
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*player5;
	void	*player6;
	void	*player7;
}	t_player;
//bonus

typedef struct s_imgs
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*player;
	void	*coin;
}	t_imgs;

typedef struct t_database
{
	int			player_x;
	int			player_y;
	int			x_len;
	int			y_len;
	int			mov_count;
	int			exit_flag;
	int			player_count;
	int			coin_count;
	int			exit_count;
	int			img_width;
	int			img_height;
	char		*map_name;
	char		**map;
	char		**check_map;
	char		**recursion_map;
	void		*mlx;
	void		*window;
	t_imgs		*imgs;
	t_player	*player_sprites;
	t_coins		*coin_sprites;
}	t_database;

void	xpm_to_imgs(t_database *db);
void	initialize_database(t_database *db, char *map);

void	check_walls(t_database *db);
void	invalid_char(t_database *db);
void	required_char(t_database *db);
void	char_check(t_database *db);
void	check_map(t_database *db);

void	player_pos(t_database *db);
void	valid_path_to_exit(int *flag, int x, int y, t_database *db);
void	check_map_path(t_database *db);

void	map_size(t_database *db);

void	print_wall(t_database *db, int *width, int *height);
void	print_floor(t_database *db, int *width, int *height);
void	print_player(t_database *db, int *width, int *height);
void	print_exit(t_database *db, int *width, int *height);
void	print_coin(t_database *db, int *width, int *height);

void	xpm_to_imgs(t_database *db);
void	print_map(t_database *db);

void	read_map(t_database *db, char ***map);

void	move_w(t_database *db);
void	move_a(t_database *db);
void	move_s(t_database *db);
void	move_d(t_database *db);
void	if_exit(t_database *db);
int		set_keys(int keycode, t_database *db);
int		exit_game(t_database *db);

void	player_xpm(t_database *db);
void	player_sprite(t_database *db);

void	coin_xpm(t_database *db);
void	coin_sprite(t_database *db);

#endif

// # define WALL "./02-ASSETS/wall.xpm"
// # define FLOOR "./02-ASSETS/floor.xpm"
// # define PLAYER "./02-ASSETS/player.xpm"
// # define EXIT "./02-ASSETS/exit.xpm"
// # define COLLECT "./02-ASSETS/collect.xpm"