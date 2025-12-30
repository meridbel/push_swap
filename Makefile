NAME = push_swap

SRCS = ft_split.c	check_error.c	main.c	helpers.c	push.c	swap.c	rotate.c	\
reverse_rotate.c	sort.c	four_five_numbers.c	three_numbers.c	big_algo.c		big_algo2.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re