/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:26:31 by johii             #+#    #+#             */
/*   Updated: 2023/12/01 20:57:55 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_xpm(t_database *db)
{
	db->sprites->player1 = mlx_xpm_file_to_image (db->mlx,
			"xpm/player1.xpm", db->img_width, db->img_height);
	db->sprites->player2 = mlx_xpm_file_to_image (db->mlx,
			"xpm/player2.xpm", db->img_width, db->img_height);
	db->sprites->player3 = mlx_xpm_file_to_image (db->mlx,
			"xpm/player3.xpm", db->img_width, db->img_height);
	db->sprites->player4 = mlx_xpm_file_to_image (db->mlx,
			"xpm/player4.xpm", db->img_width, db->img_height);
	db->sprites->player5 = mlx_xpm_file_to_image (db->mlx,
			"xpm/player5.xpm", db->img_width, db->img_height);
	db->sprites->player6 = mlx_xpm_file_to_image (db->mlx,
			"xpm/player6.xpm", db->img_width, db->img_height);
	db->sprites->player7 = mlx_xpm_file_to_image (db->mlx,
			"xpm/player7.xpm", db->img_width, db->img_height);
}

// void	player_sprite(t_database *db)
// {
// 	static int	frame;

// 	get_chic_pos(vars);
// 	chick_img(vars);
// 	vars->s = 64;
// 	frame++;
// 	if (frame <= 12)
// 	{
// 		mlx_put_image_to_window(db->mlx, db->window, db->animation.chic0.img,
// 			db->yatgao.chic[1] * 64, db->yatgao.chic[0] * 64);
// 	}
// 	else if (frame <= 24)
// 	{
// 		mlx_destroy_image(vars->mlx, vars->animation.chic0.img);
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->animation.chic1.img,
// 			vars->yatgao.chic[1] * 64, vars->yatgao.chic[0] * 64);
// 	}
// 	else
// 	{
// 		mlx_destroy_image(vars->mlx, vars->animation.chic1.img);
// 		frame = 0;
// 	}
// 	mlx_do_sync(vars->mlx);
// }
