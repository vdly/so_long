/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:26:07 by johii             #+#    #+#             */
/*   Updated: 2023/11/28 21:12:29 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_database *db)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (db->y_len > i)
	{
		if (db->map[i][0] != '1' || db->map[i][db->x_len - 1] != '1')
			error++;
		i++;
	}
	i = 0;
	while (db->x_len > i)
	{
		if (db->map[0][i] != '1' || db->map[db->y_len - 1][i] != '1')
			error++;
		i++;
	}
	if (error != 0)
	{
		ft_printf("map is not surrounded by walls\n");
		exit(EXIT_FAILURE);
	}
}

void	invalid_char(t_database *db)
{
	int	x;
	int	y;

	y = 0;
	while (db->y_len > y)
	{
		x = 0;
		while (db->x_len > x)
		{
			if (db->map[y][x] == 'P')
			{
				db->player_x = x;
				db->player_y = y;
			}
			if (db->map[y][x] == '0' || db->map[y][x] == '1' || db->map
			[y][x] == 'P' || db->map[y][x] == 'C' || db->map[y][x] == 'E')
				x++;
			else
			{
				ft_printf("invalid char in map found!!");
				exit(EXIT_FAILURE);
			}
		}
		y++;
	}
}
