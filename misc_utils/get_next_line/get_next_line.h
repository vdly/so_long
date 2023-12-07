/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johii <johii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:39:17 by johii             #+#    #+#             */
/*   Updated: 2023/12/06 22:02:24 by johii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*read_basket(int fd, char *basket);
char	*extract_apples(char *basket);
char	*after_newline(char *basket, int i, int j);
char	*ft_strchr(const char *s, int c);
char	*gnlft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);

#endif