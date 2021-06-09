NAME		:= unit-tests
SRCS		:=	main.c \
				ft_atoi/00_ft_atoi_launcher.c \
				ft_atoi/01_ft_atoi_basic_test.c \
				ft_atoi/02_ft_atoi_basic_test.c \
				ft_atoi/03_ft_atoi_hard_test.c \
				ft_atoi/04_ft_atoi_hard_test.c \
				ft_itoa/00_ft_itoa_launcher.c \
				ft_itoa/01_ft_itoa_basic_test.c \
				ft_itoa/02_ft_itoa_basic_test.c \
				ft_itoa/03_ft_itoa_hard_test.c \
				ft_itoa/04_ft_itoa_hard_test.c \
				ft_itoa/00_ft_itoa_launcher.c \
				ft_memset/01_ft_memset_basic_test.c \
				ft_memset/02_ft_memset_basic_test.c \
				ft_memset/03_ft_memset_hard_test.c \
				ft_memset/04_ft_memset_hard_test.c \
				ft_memset/00_ft_memset_launcher.c \
				ft_strlen/01_ft_strlen_basic_test.c \
				ft_strlen/02_ft_strlen_basic_test.c \
				ft_strlen/03_ft_strlen_hard_test.c \
				ft_strlen/04_ft_strlen_hard_test.c \

OBJS		:= $(SRCS:.c=.o)
INCLUDE		:= -I includes -I ../framework -I ../libft
libunit		:= ../framework/libunit
LIBS		:= -L../framework -lunit -L../libft -lft

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror $(INCLUDE) $(LIBS)
ARFLAGS		:= rc


all		: $(NAME)

$(NAME): $(OBJS)
	make -C ../framework
	make -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

test	:
	@ make -s
	-@ ./$(NAME)

clean	:
	make clean -C ../framework
	# make clean -C ../libft
	$(RM) $(OBJS)


fclean	: clean
	make fclean -C ../framework
	# make fclean -C ../libft
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re test
