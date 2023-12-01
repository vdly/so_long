/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:32:30 by johii             #+#    #+#             */
/*   Updated: 2023/12/01 20:57:25 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_database *db)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < db->y_len)
	{
		while (x < db->x_len)
		{
			if (db->map[y][x] == 'P')
			{
				db->player_x = x;
				db->player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	valid_path_to_exit(int *flag, int x, int y, t_database *db)
{
	if (db->check_map[y][x] == '1' || db->check_map[y][x] == '2')
		return ;
	if (db->check_map[y][x] == 'E')
		*flag = 1;
	db->check_map[y][x] = '2';
	valid_path_to_exit(flag, x, y + 1, db);
	valid_path_to_exit(flag, x + 1, y, db);
	valid_path_to_exit(flag, x, y - 1, db);
	valid_path_to_exit(flag, x - 1, y, db);
}

void	check_path(t_database *db)
{
	int	x;
	int	y;
	int	flag;

	x = db->player_x;
	y = db->player_y;
	flag = 0;
	valid_path_to_exit(&flag, x, y, db);
	if (flag != 1)
	{
		printf("no valid path to exit!!!\n");
		exit(EXIT_FAILURE);
	}
	else
		return ;
}
