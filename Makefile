NAME		=	miniRT
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT		=	libft
LIBFT_LIB	=	./libft/libft.a
MLX			=	mlx
MLX_LIB		=	./mlx/libmlx.a

HEADER		=	./include/
SRC_DIR		=	./src/
SRC_LIST	=	main.c \
				parse/is_valid/is_rt_file.c parse/is_valid/is_valid_elements_light.c \
				parse/is_valid/is_valid_elements_object.c parse/is_valid/is_valid_elements_utils_base.c \
				parse/is_valid/is_valid_elements_utils.c parse/is_valid/parse_elements.c \
				parse/get_next_line.c parse/get_next_line_utils.c parse/parse_file.c parse/rt_info_list.c \
				print/print_error.c \
				scene/canvas.c scene/get_new_object_in_list.c scene/object_create.c \
				scene/scene_init.c scene/scene_utils.c scene/scene.c \
				set_color/set_basic_color.c set_color/set_color.c \
				trace/hit/hit.c trace/hit/normal.c trace/hit/hit_sphere.c \
				trace/hit/hit_plane.c trace/hit/hit_cylinder.c \
				trace/ray/ray.c trace/ray/phong_lighting.c \
				utils/free_return.c utils/ft_atod.c utils/object_utils.c utils/parse_elements.c \
				utils/split_count_utils.c utils/vector_mount_utils.c utils/vector_mult_divide_utils.c \
				utils/vector_plus_minus_utils.c utils/vector_unit_utils.c utils/vector_utils.c \
				window/draw_pixel.c window/handle_key.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJS		=	${SRCS:.c=.o}

detected_OS	:=	$(shell uname)

ifeq ($(detected_OS), Linux)
MLX_LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else ifeq ($(detected_OS), Darwin)
MLX_LIB = -lm -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

all : $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

clean :
	$(RM) $(OBJS)
	make clean -C $(MLX)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME) $(LIBFT_LIB) $(MLX_LIB)

re: fclean all

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

.PHONY : all clean fclean re
