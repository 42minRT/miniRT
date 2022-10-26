CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a
DFLAGS = -g

SL_SRCS_DIR = src/
SL_SRCS = src/**/*.c
SL_PATHS = $(addprefix $(SL_SRCS_DIR), $(SL_SRCS))
SL_OBJS = ${SL_PATHS:.c=.o}

GNL_DIR = get_next_line/
GNL_SRCS = get_next_line/*.c
GNL_PATHS = $(addprefix $(GNL_DIR), $(GNL_SRCS))
GNL_OBJS = ${GNL_PATHS:.c=.o}

detected_OS := $(shell uname)
OBJS = $(SL_OBJS) $(GNL_OBJS)

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
	$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

clean :
	rm -rf $(OBJS) $(LIBFT_LIB)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_LIB)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	make bonus -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) ./
	$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)
	$(DEBUGGER) ./solong

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

.PHONY : all clean fclean
