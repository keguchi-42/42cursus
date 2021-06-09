# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 22:19:40 by keguchi           #+#    #+#              #
#    Updated: 2021/06/10 01:25:54 by keguchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
#SRCS			= $(shell find ./ -type f -name "*.c")
SRCS			= main.c
OBJS			= $(SRCS:.c=.o)
#BONUS_OBJS		= $(SRCS)
LIBFT_PATH		= libft
LIBFT_MAKE		= $(MAKE) -C $(LIBFT_PATH)
INCLUDES		= -L../libft -lft

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIBFT_MAKE)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
	$(LIBFT_MAKE) clean
	$(RM) $(OBJS)

fclean: clean
	$(LIBFT_MAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
