/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:26:31 by johii             #+#    #+#             */
/*   Updated: 2023/12/07 22:37:45 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_xpm(t_database *db)
{
	int		img_height;
	int		img_width;

	db->player_sprites = malloc(sizeof(t_player));
	db->player_sprites->player1 = mlx_xpm_file_to_image (db->mlx,
			"sprites/player.xpm/player1.xpm", &img_width, &img_height);
	db->player_sprites->player2 = mlx_xpm_file_to_image (db->mlx,
			"sprites/player.xpm/player2.xpm", &img_width, &img_height);
	db->player_sprites->player3 = mlx_xpm_file_to_image (db->mlx,
			"sprites/player.xpm/player3.xpm", &img_width, &img_height);
	db->player_sprites->player4 = mlx_xpm_file_to_image (db->mlx,
			"sprites/player.xpm/player4.xpm", &img_width, &img_height);
	db->player_sprites->player5 = mlx_xpm_file_to_image (db->mlx,
			"sprites/player.xpm/player5.xpm", &img_width, &img_height);
	db->player_sprites->player6 = mlx_xpm_file_to_image (db->mlx,
			"sprites/player.xpm/player6.xpm", &img_width, &img_height);
	db->player_sprites->player7 = mlx_xpm_file_to_image (db->mlx,
			"sprites/player.xpm/player7.xpm", &img_width, &img_height);
}

void	player_sprite(t_database *db)
{
	static int	frame;

	if (frame <= 9)
		db->imgs->player = db->player_sprites->player1;
	else if (frame <= 18)
		db->imgs->player = db->player_sprites->player2;
	else if (frame <= 27)
		db->imgs->player = db->player_sprites->player3;
	else if (frame <= 36)
		db->imgs->player = db->player_sprites->player4;
	else if (frame <= 45)
		db->imgs->player = db->player_sprites->player5;
	else if (frame <= 54)
		db->imgs->player = db->player_sprites->player6;
	else if (frame <= 63)
	{
		db->imgs->player = db->player_sprites->player7;
		frame = 0;
	}
	frame++;
}
