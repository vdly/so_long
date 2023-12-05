/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:18:19 by johii             #+#    #+#             */
/*   Updated: 2023/12/04 15:26:48 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_database	db;

	if (argc != 2)
	{
		ft_printf("  ∩     ∩\n");
		ft_printf(" ( •̀ - •́ )\n");
		ft_printf("૮         ა use format below!!\n");
		ft_printf("<./so_long> <map>\n");
	}
	else
	{
		db.mlx = mlx_init();
		initialize_database(&db, argv[1]);
		map_size(&db);
		read_map(&db, &db.map);
		read_map(&db, &db.check_map);
		check_map(&db);
		check_map_path(&db);
		db.window = mlx_new_window(db.mlx, db.x_len * db.img_width,
				db.y_len * db.img_height, "silly little game");
		mlx_hook(db.window, 17, 0, exit_game, &db);
	}
}

void	xpm_to_imgs(t_database *db)
{
	db->imgs = malloc(sizeof(t_imgs));
	db->imgs->player = mlx_xpm_file_to_image (db->mlx,
			"xpm/player7.xpm", db->img_width, db->img_height);
	db->imgs->coin = mlx_xpm_file_to_image (db->mlx,
			"xpm/coin5.xpm", db->img_width, db->img_height);
	db->imgs->wall = mlx_xpm_file_to_image (db->mlx,
			"xpm/wall.xpm", db->img_width, db->img_height);
	db->imgs->floor = mlx_xpm_file_to_image (db->mlx,
			"xpm/floor.xpm", db->img_width, db->img_height);
	db->imgs->exit = mlx_xpm_file_to_image (db->mlx,
			"xpm/exit.xpm", db->img_width, db->img_height);
}


void	initialize_database(t_database *db, char *map)
{
	db->player_x = 0;
	db->player_y = 0;
	db->x_len = 0;
	db->y_len = 0;
	db->player_count = 0;
	db->coin_count = 0;
	db->exit_count = 0;
	db->mov_count = 0;
	db->exit_flag = 0;
	db->img_width = 32;
	db->img_height = 32;
	db->map_name = map;
}

void	exit_game(t_database *db)
{
	(void) *db;
	exit(EXIT_SUCCESS);
}
