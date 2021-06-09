NAME		:= libunit.a
SRCS		:= libunit.c \
				exec_tests.c \
				puts.c \
				error.c
OBJS		:= $(SRCS:.c=.o)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
ARFLAGS		:= rc


all		: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
