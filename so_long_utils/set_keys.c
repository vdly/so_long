/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:05:55 by johii             #+#    #+#             */
/*   Updated: 2023/12/08 19:06:03 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_database *db)
{
	if (db->map[db->player_y - 1][db->player_x] != '1')
	{
		if (db->map[db->player_y - 1][db->player_x] == 'C')
		{
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y - 1][db->player_x] = 'P';
			db->mov_count++;
			db->coin_count--;
			db->player_y--;
			ft_printf("eyeball moved %d times \n", db->mov_count);
		}
		else if (db->map[db->player_y - 1][db->player_x] == '0')
		{
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y - 1][db->player_x] = 'P';
			db->mov_count++;
			db->player_y--;
			ft_printf("eyeball moved %d times \n", db->mov_count);
		}
		else if (db->map[db->player_y - 1][db->player_x] == 'E' &&
		db->coin_count == 0)
			if_exit(db);
	}
}

void	move_a(t_database *db)
{
	if (db->map[db->player_y][db->player_x - 1] != '1')
	{
		if (db->map[db->player_y][db->player_x - 1] == 'C')
		{
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y][db->player_x - 1] = 'P';
			db->mov_count++;
			db->coin_count--;
			db->player_x--;
			ft_printf("eyeball moved %d times \n", db->mov_count);
		}
		else if (db->map[db->player_y][db->player_x - 1] == '0')
		{
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y][db->player_x - 1] = 'P';
			db->mov_count++;
			db->player_x--;
			ft_printf("eyeball moved %d times \n", db->mov_count);
		}
		else if (db->map[db->player_y][db->player_x - 1] == 'E' &&
		db->coin_count == 0)
			if_exit(db);
	}
}

void	move_s(t_database *db)
{
	if (db->map[db->player_y + 1][db->player_x] != '1')
	{
		if (db->map[db->player_y + 1][db->player_x] == 'C')
		{
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y + 1][db->player_x] = 'P';
			db->mov_count++;
			db->coin_count--;
			db->player_y++;
			ft_printf("eyeball moved %d times \n", db->mov_count);
		}
		else if (db->map[db->player_y + 1][db->player_x] == '0')
		{
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y + 1][db->player_x] = 'P';
			db->mov_count++;
			db->player_y++;
			ft_printf("eyeball moved %d times \n", db->mov_count);
		}
		else if (db->map[db->player_y + 1][db->player_x] == 'E' &&
		db->coin_count == 0)
			if_exit(db);
	}
}

void	move_d(t_database *db)
{
	if (db->map[db->player_y][db->player_x + 1] != '1')
	{
		if (db->map[db->player_y][db->player_x + 1] == 'C')
		{
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y][db->player_x + 1] = 'P';
			db->mov_count++;
			db->coin_count--;
			db->player_x++;
			ft_printf("eyeball moved %d times \n", db->mov_count);
		}
		else if (db->map[db->player_y][db->player_x + 1] == '0')
		{
			db->map[db->player_y][db->player_x] = '0';
			db->map[db->player_y][db->player_x + 1] = 'P';
			db->mov_count++;
			db->player_x++;
			ft_printf("eyeball moved %d times \n", db->mov_count);
		}
		else if (db->map[db->player_y][db->player_x + 1] == 'E' &&
		db->coin_count == 0)
			if_exit(db);
	}
}
