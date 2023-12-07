/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:07:35 by johii             #+#    #+#             */
/*   Updated: 2023/12/06 23:50:25 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_wall(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->wall, (*width) * 32, (*height) * 32);
}

void	print_floor(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->floor, (*width) * 32, (*height) * 32);
}

void	print_player(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->player, (*width) * 32, (*height) * 32);
}

void	print_exit(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->exit, (*width) * 32, (*height) * 32);
}

void	print_coin(t_database *db, int *width, int *height)
{
	mlx_put_image_to_window(db->mlx, db->window,
		db->imgs->coin, (*width) * 32, (*height) * 32);
}
