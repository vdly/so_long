# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johii <johii@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 19:12:22 by johii             #+#    #+#              #
#    Updated: 2023/11/25 15:17:40 by johii            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		=	libft/*.c
PRINTF		=	libft/ft_printf/*.c
GNL			=	get_next_line/*.c

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit 
RM			=	rm -rf

clean		:
				$(RM) libft/*.o
				$(RM) libft/ft_printf/*.o
				$(RM) get_next_line/*.c
            
fclean		:	clean
				$(RM)
            
re			:	fclean all

.PHONY		:	all bonus clean fclean re