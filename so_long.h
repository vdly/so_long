/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:17:55 by johii             #+#    #+#             */
/*   Updated: 2023/12/02 18:33:14 by johii            ###   ########.fr       */
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

typedef struct s_imgs
{
	void	*wall;
	void	*floor;
	void	*exit;
}	t_imgs;

typedef struct s_sprite
{
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*player5;
	void	*player6;
	void	*player7;
}	t_sprite;

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
	t_sprite	*sprites;
}	t_database;

void	read_map(t_database *db, char ***map);
void	map_size(t_database *db);
void	check_walls(t_database *db);
void	invalid_char(t_database *db);
void	required_char(t_database *db);
void	char_check(t_database *db);
void	check_all(t_database *db);
void	player_pos(t_database *db);
int		valid_path_to_exit(int *flag, int x, int y, t_database *db);
void	check_path(t_database *db);
void	exit(t_database *db);

#endif

// # define WALL "./02-ASSETS/wall.xpm"
// # define FLOOR "./02-ASSETS/floor.xpm"
// # define PLAYER "./02-ASSETS/player.xpm"
// # define EXIT "./02-ASSETS/exit.xpm"
// # define COLLECT "./02-ASSETS/collect.xpm"