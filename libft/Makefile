# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 17:32:59 by keguchi           #+#    #+#              #
#    Updated: 2021/06/04 08:29:47 by keguchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_atoi.c					\
				ft_bzero.c					\
				ft_isalnum.c				\
				ft_isalpha.c				\
				ft_isascii.c				\
				ft_isdigit.c				\
				ft_isprint.c				\
				ft_memcpy.c					\
				ft_memset.c					\
				ft_strchr.c					\
				ft_strrchr.c				\
				ft_strlen.c					\
				ft_strncmp.c				\
				ft_strnstr.c				\
				ft_tolower.c				\
				ft_toupper.c				\
				ft_memccpy.c				\
				ft_memmove.c				\
				ft_memchr.c					\
				ft_memcmp.c					\
				ft_calloc.c					\
				ft_strdup.c					\
				ft_strlcpy.c				\
				ft_strlcat.c				\
				ft_substr.c					\
				ft_strjoin.c				\
				ft_strtrim.c				\
				ft_split.c					\
				ft_itoa.c					\
				ft_strmapi.c				\
				ft_putchar_fd.c				\
				ft_putstr_fd.c				\
				ft_putendl_fd.c				\
				ft_putnbr_fd.c				\
				ft_strncpy.c				\

BONUS		=	ft_lstnew.c					\
				ft_lstadd_front.c			\
				ft_lstsize.c				\
				ft_lstlast.c				\
				ft_lstadd_back.c			\
				ft_lstdelone.c				\
				ft_lstclear.c				\
				ft_lstiter.c				\

OBJS		=	$(SRCS:.c=.o)

OBJS_B		=	$(BONUS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

.c.o		:
			@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

clean		:
			@/bin/rm -f $(OBJS) $(OBJS_B)

fclean		:	clean
			@/bin/rm -f $(NAME)

re			:	fclean all

bonus		:	$(OBJS) $(OBJS_B)
			@ar -rcs $(NAME) $(OBJS) $(OBJS_B)

.PHONY		:	all clean fclean re bonus
