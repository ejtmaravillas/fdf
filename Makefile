NAME = fdf

CC = cc
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -O1
CFLAGS = -Wall -Wextra -Werror

FDF_SRCS = main.c matrix_init.c matrix_fill.c matrix_map.c map_points.c map_rotation.c map_draw.c map_setscreen.c \
			hooks.c color.c map_color_points.c menu.c hooks_a.c hooks_b.c hooks_c.c hooks_d.c \
			map_draw_a.c
FDF_OBJS = $(FDF_SRCS:.c=.o)
VPATH = src:lib:lib/libft

# includes for mlx mac
INCLUDES = -I/opt/X11/include -Imlx
# includes for mlx linux
# INCLUDES = -I/usr/include -Imlx -O3

# mlxflags for mac
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
# mlxflags for linux
# MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

MLX_DIR = ./mlx
# MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_LIB = $(MLX_DIR)/libmlx.a

### LIBFT
LIBFT = libft.a
LIBFT_DIR = ./lib/libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)
LIBR = $(LIBFT_LIB)
### LIBFT

MAKE_LIBR = make --no-print-directory -C

RM = rm -rf

LB = ar rcs

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(NAME): $(FDF_OBJS)
		$(CC) $(CFLAGS) $(FDF_OBJS) $(MLX_FLAGS) $(LIBFT_LIB) -o $(NAME) -lm

$(LIBFT_LIB):
	$(MAKE_LIBR) $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE_LIBR) $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(FDF_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME) $(FDF_OBJS)
	$(MAKE_LIBR) $(LIBFT_DIR) fclean

re: fclean all
	clear