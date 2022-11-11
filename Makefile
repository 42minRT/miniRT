# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 13:22:44 by jimin             #+#    #+#              #
#    Updated: 2022/11/11 21:11:45 by jimin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-g3
RM			=	rm -f

LIBFT		=	libft
LIBFT_LIB	=	./libft/libft.a
MLX			=	mlx
MLX_LIB		=	./mlx/libmlx.a

HEADER_DIR	=	./include/

detected_OS	:=	$(shell uname)

ifeq ($(detected_OS), Linux)
MLX_LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else ifeq ($(detected_OS), Darwin)
MLX_LIB = -lm -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

SRC_DIR		=	./src/
SRC_LIST	=	main.c
MAIN_SRCS	=	$(addprefix $(SRC_DIR), $(SRC_LIST))
MAIN_OBJS	=	$(MAIN_SRCS:.c=.o)

PARSE_DIR	=	$(SRC_DIR)parse/
PARSE_LIST	=	get_next_line.c get_next_line_utils.c parse_file.c rt_info_list.c
PARSE_SRCS	=	$(addprefix $(PARSE_DIR), $(PARSE_LIST))
PARSE_OBJS	=	$(PARSE_SRCS:.c=.o)

VALID_DIR	=	$(SRC_DIR)parse/is_valid/
VALID_LIST	= 	is_rt_file.c is_valid_elements_light.c \
					is_valid_elements_object.c is_valid_elements_utils_base.c \
					is_valid_elements_utils.c parse_elements.c
VALID_SRCS	=	$(addprefix $(VALID_DIR), $(VALID_LIST))
VALID_OBJS	=	$(VALID_SRCS:.c=.o)


SCENE_DIR	=	$(SRC_DIR)scene/
SCENE_LIST	=	canvas.c get_new_object_in_list.c object_create.c \
					scene_init.c scene_utils.c scene.c
SCENE_SRCS	=	$(addprefix $(SCENE_DIR), $(SCENE_LIST))
SCENE_OBJS	=	$(SCENE_SRCS:.c=.o)

UTILS_DIR	=	$(SRC_DIR)utils/
UTILS_LIST	=	free_return.c ft_atod.c object_utils.c parse_elements.c \
					split_count_utils.c vector_mount_utils.c vector_mult_divide_utils.c \
					vector_plus_minus_utils.c vector_unit_utils.c vector_utils.c 
UTILS_SRCS	=	$(addprefix $(UTILS_DIR), $(UTILS_LIST))
UTILS_OBJS	=	$(UTILS_SRCS:.c=.o)

TRACE_DIR	=	$(SRC_DIR)trace/
RAY_DIR		=	$(TRACE_DIR)ray/
RAY_LIST	=	ray.c phong_lighting.c
RAY_SRCS	=	$(addprefix $(RAY_DIR), $(RAY_LIST))
RAY_OBJS	=	$(RAY_SRCS:.c=.o)

HIT_DIR		=	$(TRACE_DIR)hit/
HIT_LIST	=	hit.c normal.c hit_sphere.c hit_plane.c hit_cylinder.c
HIT_SRCS	=	$(addprefix $(HIT_DIR), $(HIT_LIST))
HIT_OBJS	=	$(HIT_SRCS:.c=.o)

WINDOW_DIR	=	$(SRC_DIR)window/
WINDOW_LIST	=	draw_pixel.c handle_key.c
WINDOW_SRCS	=	$(addprefix $(WINDOW_DIR), $(WINDOW_LIST))
WINDOW_OBJS	=	$(WINDOW_SRCS:.c=.o)

PRINT_DIR	=	${SRC_DIR}print/
PRINT_LIST	=	print_error.c
PRINT_SRCS	=	$(addprefix $(PRINT_DIR), $(PRINT_LIST))
PRINT_OBJS	=	${PRINT_SRCS:.c=.o}

SET_COLOR_DIR	=	${SRC_DIR}set_color/
SET_COLOR_LIST	=	set_basic_color.c set_color.c
SET_COLOR_SRCS	=	$(addprefix $(SET_COLOR_DIR), $(SET_COLOR_LIST))
SET_COLOR_OBJS	=	${SET_COLOR_SRCS:.c=.o}

OBJS = $(MAIN_OBJS) $(PARSE_OBJS) $(VALID_OBJS) $(SCENE_OBJS) $(UTILS_OBJS) $(RAY_OBJS) $(HIT_OBJS) $(WINDOW_OBJS) $(PRINT_OBJS) $(SET_COLOR_OBJS)

all : $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

debug: $(OBJS)
	make bonus -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(DFLAGS) -I $(HEADER_DIR) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	make clean -C $(MLX)
	make clean -C $(LIBFT)
	$(RM) $(NAME) $(LIBFT_LIB) $(MLX_LIB)

re: fclean all

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

.PHONY : all clean fclean re
