/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:53:46 by johii             #+#    #+#             */
/*   Updated: 2023/12/08 19:04:54 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	if_exit(t_database *db)
{
	db->mov_count++;
	db->exit_flag = 1;
}

int	set_keys(int keycode, t_database *db)
{
	if (keycode == 13)
		move_w(db);
	if (keycode == 0)
		move_a(db);
	if (keycode == 1)
		move_s(db);
	if (keycode == 2)
		move_d(db);
	if (keycode == 53)
		exit_game(db);
	return (0);
}
