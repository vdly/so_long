/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:27:58 by johii             #+#    #+#             */
/*   Updated: 2023/12/08 19:02:43 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(t_database *db, char ***map)
{
	int		fd;
	int		i;
	char	*line;
	char	*temp_basket;

	fd = open(db->map_name, O_RDONLY);
	line = get_next_line(fd);
	temp_basket = ft_strtrim(line, "\n");
	free(line);
	*map = (char **)malloc(sizeof(char *) * (db->y_len + 1));
	i = 0;
	while (temp_basket)
	{
		(*map)[i] = temp_basket;
		line = get_next_line(fd);
		temp_basket = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	(*map)[i] = NULL;
	free (line);
	line = NULL;
	close(fd);
}
