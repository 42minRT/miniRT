NAME = minirt
CC = cc
#CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIBFT_LIB = libft.a
DFLAGS = -g3

MLX = mlx
MLX_A = libmlx.a

SL_SRCS = $(wildcard src/*.c) $(wildcard src/**/*.c) $(wildcard src/**/**/*.c)
SL_OBJS = ${SL_SRCS:.c=.o}

OBJS = $(SL_OBJS)

detected_OS := $(shell uname)

ifeq ($(detected_OS), Linux)
DEBUGGER = gdb
MLX_LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else ifeq ($(detected_OS), Darwin)
DEBUGGER = lldb
MLX_LIB = -lm -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

all : ${NAME}

$(NAME): $(SL_OBJS) $(GNL_OBJS) 
	make bonus -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) ./
	make -C $(MLX)
	cp $(MLX)/$(MLX_A) ./
	$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

clean :
	rm -rf $(OBJS) $(LIBFT_LIB) $(MLX_A)

fclean : clean
	rm -rf $(NAME)
	make clean -C $(MLX)
	make clean -C $(LIBFT)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	make bonus -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) ./
	$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)
	$(DEBUGGER) ./minirt

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

.PHONY : all clean fclean
