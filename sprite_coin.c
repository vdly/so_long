/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:45:45 by johii             #+#    #+#             */
/*   Updated: 2023/12/02 15:53:25 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_xpm(t_database *db)
{
	db->sprites->coin1 = mlx_xpm_file_to_image (db->mlx,
			"xpm/coin1.xpm", db->img_width, db->img_height);
	db->sprites->coin2 = mlx_xpm_file_to_image (db->mlx,
			"xpm/coin2.xpm", db->img_width, db->img_height);
	db->sprites->coin3 = mlx_xpm_file_to_image (db->mlx,
			"xpm/coin3.xpm", db->img_width, db->img_height);
	db->sprites->coin4 = mlx_xpm_file_to_image (db->mlx,
			"xpm/coin4.xpm", db->img_width, db->img_height);
	db->sprites->coin5 = mlx_xpm_file_to_image (db->mlx,
			"xpm/coin5.xpm", db->img_width, db->img_height);
}
