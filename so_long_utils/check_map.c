/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:26:07 by johii             #+#    #+#             */
/*   Updated: 2023/12/08 18:13:10 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	required_char(t_database *db)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (db->map[y])
	{
		x = 0;
		while (db->map[y][x])
		{
			if (db->map[y][x] == 'P')
				db->player_count++;
			if (db->map[y][x] == 'C')
				db->coin_count++;
			if (db->map[y][x] == 'E')
				db->exit_count++;
			x++;
		}
		y++;
	}
	char_check(db);
}

void	char_check(t_database *db)
{
	if (db->player_count != 1 || db->coin_count < 1 || db->exit_count < 1)
	{
		ft_printf("doesnt have required char(s) :O (1P 1C 1E)\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map(t_database *db)
{
	check_walls(db);
	invalid_char(db);
	required_char(db);
}
