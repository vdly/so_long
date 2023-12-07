/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:31:15 by johii             #+#    #+#             */
/*   Updated: 2023/12/07 22:31:09 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_to_imgs(t_database *db)
{
	int	img_height;
	int	img_width;

	db->imgs = malloc(sizeof(t_imgs));
	db->imgs->wall = mlx_xpm_file_to_image (db->mlx,
			"xpm/wall.xpm", &img_width, &img_height);
	db->imgs->floor = mlx_xpm_file_to_image (db->mlx,
			"xpm/floor.xpm", &img_width, &img_height);
	db->imgs->exit = mlx_xpm_file_to_image (db->mlx,
			"xpm/exit.xpm", &img_width, &img_height);
}

void	print_map(t_database *db)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (db->map[height])
	{
		while (db->map[height][width])
		{
			if (db->map[height][width] == '0')
				print_floor(db, &width, &height);
			else if (db->map[height][width] == '1')
				print_wall(db, &width, &height);
			else if (db->map[height][width] == 'E')
				print_exit(db, &width, &height);
			else if (db->map[height][width] == 'P')
				print_player(db, &width, &height);
			else if (db->map[height][width] == 'C')
				print_coin(db, &width, &height);
			width++;
		}
		height++;
		width = 0;
	}
}
