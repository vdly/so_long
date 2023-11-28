/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:27:58 by johii             #+#    #+#             */
/*   Updated: 2023/11/28 21:30:30 by johii            ###   ########.fr       */
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

void	read_map(t_database *db, char ***map)
{
	int		fd;
	int		i;
	char	*line;
	char	*temp_basket;

	fd = open(db->map_name, O_RDONLY);
	line = get_next_line(fd);
	temp_basket = ft_strtrim(line, '\n');
	free(line);
	*map = (char **)malloc(sizeof(char *) * (db->y_len + 1));
	while (temp_basket)
	{
		(*map)[i] = temp_basket;
		line = get_next_line(fd);
		temp_basket = ft_strtrim(line, '\n');
		free(line);
		i++;
	}
	(*map)[i] = NULL;
	free (line);
	line = NULL;
	close(fd);
}
