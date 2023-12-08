NAME := so_long

SRCS := so_long.c \
		check_map.c	\
		check_path.c	\
		map_size.c	\
		print_img.c	\
		print_map.c	\
		read_map.c	\
		set_keys.c	\
		set_keys2.c \
		sprite_coin.c \
		sprite_player.c \

GNL_SRCS := misc_utils/get_next_line/get_next_line.c \
			misc_utils/get_next_line/get_next_line_utils.c \

OBJS := $(addprefix object_files/, $(SRCS:.c=.o))

CC := cc
CFLAGS := -Wall -Werror -Wextra
MLXFLAGS := -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR := ./misc_utils/libft
PRINTF_DIR := ./misc_utils/libft/ft_printf

RM := rm
RMFLAGS := -rf

LINK_LIBFT := -L$(LIBFT_DIR) -lft
LINK_PRINTF := -L$(PRINTF_DIR) -lftprintf

all: $(NAME)

object_files/%.o: %.c
	$(CC) -c $< -o $@

object_files/%.o: so_long_utils/%.c
	$(CC) -c $< -o $@

$(NAME): $(OBJS) $(GNL_SRCS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(GNL_SRCS) $(LINK_LIBFT) $(LINK_PRINTF) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR) 
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR) 
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

#debugging#

# CFLAGS := -Wall -Werror -Wextra -g

# object_files/%.o: %.c
# 	$(CC) -c $< -o $@ -g

# object_files/%.o: so_long_utils/%.c
# 	$(CC) -c $< -o $@ -g