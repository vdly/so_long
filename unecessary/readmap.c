/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:02:55 by johii             #+#    #+#             */
/*   Updated: 2023/12/08 19:03:47 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_check_map(t_database *db)
{
	int		fd;
	int		i;
	char	*line;
	char	*temp_basket;

	fd = open(db->map_name, O_RDONLY);
	line = get_next_line(fd);
	temp_basket = ft_strtrim(line, "\n");
	free(line);
	db->check_map = malloc(sizeof(char *) * (db->y_len + 1));
	i = 0;
	while (temp_basket)
	{
		(db->check_map)[i] = temp_basket;
		line = get_next_line(fd);
		temp_basket = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	db->check_map[i] = NULL;
	free (line);
	line = NULL;
	close(fd);
}
