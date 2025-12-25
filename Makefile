NAME = push_swap.o

SRCS = ft_split.c	check_error.c	main.c	helpers.c	small_sort.c	push.c	swap.c	rotate.c	\
reverse_rotate.c	
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