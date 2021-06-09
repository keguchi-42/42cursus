# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 18:39:13 by keguchi           #+#    #+#              #
#    Updated: 2021/05/08 00:36:21 by keguchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
OS				= $(shell uname)
SRCS			= $(shell find ./srcs_mac -type f -name "*.c")
GNLSRCS			= $(shell find ./gnl -type f -name "*.c")

SRCS_PATH		= ./srcs_mac
INCLUDES		= libmlx.dylib -framework OpenGL -framework AppKit
MLX_PATH		= mlx_mac

ifeq ($(OS), Linux)
	SRCS		= $(shell find ./srcs_linux -type f -name "*.c")
	SRC_PATH	= ./srcs_linux
	INCLUDES	= -Lmlx_linux -lmlx -lXext -lX11 -lm
	MLX_PATH	= mlx_linux
endif

OBJS			= $(SRCS:.c=.o)
GNLOBJS			= $(GNLSRCS:.c=.o)
MLX_MAKE		= $(MAKE) -C $(MLX_PATH)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(GNLOBJS)
	$(MLX_MAKE)
	$(CC) $(CFLAGS) $(OBJS) $(GNLOBJS) $(INCLUDES) -o $(NAME)

clean:
	$(MLX_MAKE) clean
	$(RM) $(OBJS) $(GNLOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) ./maps/example.cub

.PHONY: all clean fclean re run

