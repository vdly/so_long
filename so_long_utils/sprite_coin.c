/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:45:45 by johii             #+#    #+#             */
/*   Updated: 2023/12/07 22:27:41 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coin_xpm(t_database *db)
{
	int		img_height;
	int		img_width;

	db->coin_sprites = malloc(sizeof(t_coins));
	db->coin_sprites->coin1 = mlx_xpm_file_to_image (db->mlx,
			"sprites/coin.xpm/coin1.xpm", &img_width, &img_height);
	db->coin_sprites->coin2 = mlx_xpm_file_to_image (db->mlx,
			"sprites/coin.xpm/coin2.xpm", &img_width, &img_height);
	db->coin_sprites->coin3 = mlx_xpm_file_to_image (db->mlx,
			"sprites/coin.xpm/coin3.xpm", &img_width, &img_height);
	db->coin_sprites->coin4 = mlx_xpm_file_to_image (db->mlx,
			"sprites/coin.xpm/coin4.xpm", &img_width, &img_height);
	db->coin_sprites->coin5 = mlx_xpm_file_to_image (db->mlx,
			"sprites/coin.xpm/coin5.xpm", &img_width, &img_height);
}

void	coin_sprite(t_database *db)
{
	static int	frame;

	if (frame <= 10)
		db->imgs->coin = db->coin_sprites->coin1;
	else if (frame <= 20)
		db->imgs->coin = db->coin_sprites->coin2;
	else if (frame <= 30)
		db->imgs->coin = db->coin_sprites->coin3;
	else if (frame <= 40)
		db->imgs->coin = db->coin_sprites->coin4;
	else if (frame <= 50)
		db->imgs->coin = db->coin_sprites->coin5;
	else if (frame <= 70)
	{
		db->imgs->coin = db->coin_sprites->coin5;
		frame = 0;
	}
	frame++;
}
