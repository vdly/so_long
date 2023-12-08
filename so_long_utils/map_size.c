/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:50:26 by johii             #+#    #+#             */
/*   Updated: 2023/12/08 18:13:27 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_countline(char *line);

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
		if (ft_countline(line) != db->x_len)
		{
			ft_printf("map has inconsistent length :O\n");
			exit(EXIT_FAILURE);
		}
		db->y_len++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close (fd);
}

int	ft_countline(char *line)
{
	int	i;

	i = 0;
	while (*line && *line != '\n')
	{
		i++;
		line++;
	}
	return (i);
}
