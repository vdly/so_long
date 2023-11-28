/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:18:19 by johii             #+#    #+#             */
/*   Updated: 2023/11/28 21:49:47 by johii            ###   ########.fr       */
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
		// read_map(&db, &db.check_map);
	}
}

void	xpm_to_imgs(t_database *db)
{
	int	img_height;
	int	img_lenght;

	db->imgs = malloc(sizeof(t_imgs));
	db->imgs = mlx_xpm_file_to_image(db->mlx);
}

void	initialize_database(t_database *db, char *map)
{
	db->player_x = 0;
	db->player_y = 0;
	db->x_len = 0;
	db->y_len = 0;
	db->mov_count = 0;
	db->map_name = map;
}
