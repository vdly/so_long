/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:17:55 by johii             #+#    #+#             */
/*   Updated: 2023/11/28 21:30:12 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_imgs
{
	void	*wall;
	void	*floor;
	void	*coin;
	void	*player;
	void	*exit;
}	t_imgs;

typedef struct t_database
{
	int		player_x;
	int		player_y;
	int		x_len;
	int		y_len;
	int		mov_count;
	char	*map_name;
	char	**map;
	char	**check_map;
	char	**recursion_map;
	void	*mlx;
	void	*window;
	t_imgs	*imgs;
}	t_database;

void	read_map(t_database *db, char ***map);
void	map_size(t_database *db);

#endif

// # define WALL "./02-ASSETS/wall.xpm"
// # define FLOOR "./02-ASSETS/floor.xpm"
// # define PLAYER "./02-ASSETS/player.xpm"
// # define EXIT "./02-ASSETS/exit.xpm"
// # define COLLECT "./02-ASSETS/collect.xpm"