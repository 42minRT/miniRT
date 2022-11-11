# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 13:22:44 by jimin             #+#    #+#              #
#    Updated: 2022/11/11 13:24:15 by jimin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g3

LIBFT = libft
LIBFT_LIB = libft.a

MLX = mlx
MLX_A = libmlx.a

SL_SRCS = $(wildcard src/*.c) $(wildcard src/**/*.c) $(wildcard src/**/**/*.c)
SL_OBJS = ${SL_SRCS:.c=.o}

OBJS = $(SL_OBJS)

detected_OS := $(shell uname)

ifeq ($(detected_OS), Linux)
MLX_LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else ifeq ($(detected_OS), Darwin)
MLX_LIB = -lm -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

all : $(NAME)

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

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

debug:
	make bonus -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) ./
	make -C $(MLX)
	cp $(MLX)/$(MLX_A) ./	
	$(CC) $(wildcard src/*.c) $(wildcard src/**/*.c) $(wildcard src/**/**/*.c) $(LIBFT_LIB) $(MLX_LIB) $(DFLAGS) -o debug.out

.PHONY : all clean fclean
