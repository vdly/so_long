/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:50:26 by johii             #+#    #+#             */
/*   Updated: 2023/11/30 19:50:41 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_database *db)
{
	int		fd;
	char	*line;

	fd = open(db->map_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_printf("file is corrupted??\n");
	while (line[db->x_len] != '\0' && line[db->x_len] != '\n')
		db->x_len++;
	while (line)
	{
		if (ft_strlen(line) != db->x_len + 1)
		{
			ft_printf("map has inconsistent length :O\n");
			error(EXIT_FAILURE);
		}
		db->y_len++;
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
}
