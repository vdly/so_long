/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:18:19 by johii             #+#    #+#             */
/*   Updated: 2023/12/08 18:12:43 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_database(t_database *db, char *map)
{
	db->x_len = 0;
	db->y_len = 0;
	db->player_count = 0;
	db->coin_count = 0;
	db->exit_count = 0;
	db->mov_count = 0;
	db->exit_flag = 0;
	db->map_name = map;
	db->img_height = 32;
	db->img_width = 32;
	xpm_to_imgs(db);
	player_xpm(db);
	coin_xpm(db);
}

int	exit_game(t_database *db)
{
	(void) *db;
	ft_printf("successful exit!");
	exit(EXIT_SUCCESS);
}

int	game_win(t_database *db)
{
	if (db->exit_flag)
		exit_game(db);
	player_sprite(db);
	coin_sprite(db);
	mlx_clear_window(db->mlx, db->window);
	print_map(db);
	return (0);
}

int	main(int argc, char **argv)
{
	t_database	db;

	if (argc != 2)
	{
		ft_printf(" ( •̀ - •́ ) use format below!!\n");
		ft_printf("<./so_long> <map>\n");
	}
	else
	{
		db.mlx = mlx_init();
		initialize_database(&db, argv[1]);
		map_size(&db);
		read_map(&db, &(db.map));
		read_map(&db, &(db.check_map));
		check_map(&db);
		player_pos(&db);
		check_map_path(&db);
		db.window = mlx_new_window(db.mlx, db.x_len * db.img_width,
				db.y_len * db.img_height, "silly little game");
		mlx_hook(db.window, 17, (1L << 0), exit_game, &db);
		mlx_hook(db.window, 02, (1L << 0), set_keys, &db);
		mlx_loop_hook(db.mlx, game_win, &db);
		mlx_loop(db.mlx);
	}
}
