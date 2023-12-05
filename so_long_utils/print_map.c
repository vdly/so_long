/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:31:15 by johii             #+#    #+#             */
/*   Updated: 2023/12/03 18:32:33 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_database *db)
{
	int	height;
	int	width;

	width = 0;
	height = 0;
	while (db->map[height])
	{
		while (db->map[height][width])
		{
			if (db->map[height][width] == '0')
				print_img_floor(db, db->img_width, db->img_height);
			else if (db->map[height][width] == '1')
				print_img_wall(db, db->img_width, db->img_height);
			else if (db->map[height][width] == 'E')
				print_img_exit(db, db->img_width, db->img_height);
			else if (db->map[height][width] == 'P')
				print_img_player(db, db->img_width, db->img_height);
			else if (db->map[height][width] == 'C')
				mlx_put_image_to_window(db->mlx, db->window,
					db->imgs->coin, db->img_width * 32, db->img_height * 32);
			db->img_width++;
		}
		db->img_height++;
		db->img_width = 0;
	}
}

void	print_img_wall(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->wall, (*width) * 32, (*height) * 32);
}

void	print_img_floor(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->floor, (*width) * 32, (*height) * 32);
}

void	print_img_player(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->player, (*width) * 32, (*height) * 32);
}

void	print_img_exit(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->exit, (*width) * 32, (*height) * 32);
}

