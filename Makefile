SRC =	srcs/get_next_line_utils.c \
		srcs/get_next_line.c \
		srcs/init.c \
		srcs/parsing.c \
		srcs/parsing_color_resolution_texture.c  \
		srcs/parsing_map.c  \
		srcs/parsing_utils.c \
		srcs/errors.c \
		srcs/raycasting.c \
		srcs/raycasting_init.c \
		srcs/raycasting_utils.c \
		srcs/raycasting_draw.c \
		srcs/raycasting_render.c \
		srcs/raycasting_map.c \
		srcs/raycasting_key.c \
		srcs/render_utils.c \
		srcs/cast_ray_utils.c \
		srcs/cast_ray_utils_next.c \
		srcs/get_next_line_utils2.c \

SRC_BONUS = srcs/get_next_line_utils.c \
			srcs/get_next_line.c \
			srcs/init.c \
			srcs/parsing.c \
			srcs/parsing_color_resolution_texture.c  \
			srcs/parsing_map.c  \
			srcs/parsing_utils.c \
			srcs/errors.c \
			srcs/raycasting_init.c \
			srcs/raycasting_utils.c \
			srcs/raycasting_draw.c \
			srcs/raycasting_render.c \
			srcs/raycasting_map.c \
			srcs/raycasting_key.c \
			srcs/render_utils.c \
			srcs/cast_ray_utils.c \
			srcs/cast_ray_utils_next.c \
			srcs/get_next_line_utils2.c \
			srcs/glich_bonus.c \
			srcs/glich_bonus2.c \
			srcs/raycasting_bonus.c

OBJS= $(SRC:.c=.o)

OBJS_BONUS= $(SRC_BONUS:.c=.o)

INC = -I inc -I ${MLX_DIR}

NAME = cub3d

MLX_DIR = minilibx-linux

MLX = libmlx.a 

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

.c.o :
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	make -C ${MLX_DIR}
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lm -lX11 -lXext -lmlx

bonus : ${OBJS_BONUS}
	make -C ${MLX_DIR}
	${CC} $(CFLAGS) -o $(NAME) $(OBJS_BONUS) -L $(MLX_DIR) -lm -lX11 -lXext -lmlx
	
clean :    
	make clean -C ${MLX_DIR}
	rm -rf ${OBJS}
	rm -rf ${OBJS_BONUS}

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re