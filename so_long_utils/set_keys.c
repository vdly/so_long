/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:05:55 by johii             #+#    #+#             */
/*   Updated: 2023/12/02 19:01:44 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_database *db)
{
	if (db->map[db->player_y - 1][db->player_x] != '1')
	{
		if (db->map[db->player_y - 1][db->player_x] == 'C')
		{
			db->map[db->player_y - 1][db->player_x] == 'P';
			db->mov_count++;
			db->coin_count--;
			db->player_y--;
		}
		if (db->map[db->player_y - 1][db->player_x] == '0')
		{
			db->map[db->player_y - 1][db->player_x] == 'P';
			db->mov_count++;
			db->player_y--;
		}
		else if (db->map[db->player_y - 1][db->player_x] == 'E')
		{
			db->mov_count++;
			db->exit_flag = 1;
		}
	}
	ft_printf("eyeball moved %d times \n", db->mov_count);
}

void	move_a(t_database *db)
{
	if (db->map[db->player_y][db->player_x - 1] != '1')
	{
		if (db->map[db->player_y][db->player_x - 1] == 'C')
		{
			db->map[db->player_y][db->player_x - 1] == 'P';
			db->mov_count++;
			db->coin_count--;
			db->player_x--;
		}
		if (db->map[db->player_y][db->player_x - 1] == '0')
		{
			db->map[db->player_y][db->player_x - 1] == 'P';
			db->mov_count++;
			db->player_x--;
		}
		else if (db->map[db->player_y][db->player_x - 1] == 'E')
		{
			db->mov_count++;
			db->exit_flag = 1;
		}
	}
	ft_printf("eyeball moved %d times \n", db->mov_count);
}

void	move_s(t_database *db)
{
	if (db->map[db->player_y + 1][db->player_x] != '1')
	{
		if (db->map[db->player_y + 1][db->player_x] == 'C')
		{
			db->map[db->player_y + 1][db->player_x] == 'P';
			db->mov_count++;
			db->coin_count--;
			db->player_y++;
		}
		if (db->map[db->player_y + 1][db->player_x] == '0')
		{
			db->map[db->player_y + 1][db->player_x] == 'P';
			db->mov_count++;
			db->player_y++;
		}
		else if (db->map[db->player_y + 1][db->player_x] == 'E')
		{
			db->mov_count++;
			db->exit_flag = 1;
		}
	}
	ft_printf("eyeball moved %d times \n", db->mov_count);
}

void	move_d(t_database *db)
{
	if (db->map[db->player_y][db->player_x + 1] != '1')
	{
		if (db->map[db->player_y][db->player_x + 1] == 'C')
		{
			db->map[db->player_y][db->player_x + 1] == 'P';
			db->mov_count++;
			db->coin_count--;
			db->player_x++;
		}
		if (db->map[db->player_y][db->player_x + 1] == '0')
		{
			db->map[db->player_y][db->player_x + 1] == 'P';
			db->mov_count++;
			db->player_x++;
		}
		else if (db->map[db->player_y][db->player_x + 1] == 'E')
		{
			db->mov_count++;
			db->exit_flag = 1;
		}
	}
	ft_printf("eyeball moved %d times \n", db->mov_count);
}

void	key_set(int keycode, t_database *db)
{
	if (keycode == 13)
		move_w(&db);
	if (keycode == 0)
		move_a(&db);
	if (keycode == 1)
		move_s(&db);
	if (keycode == 2)
		move_d(&db);
}
