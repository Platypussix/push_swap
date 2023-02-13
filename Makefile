CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap.a

SRC = main.c index.c parsing.c simple_sort.c utils.c utils_free.c

RM = rm -f
OBJ = $(SRC:%.c=%.o)
all = $(NAME)

$(NAME): $(OBJ)
		@make -C ./libft
		$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

clean:
		@make -C ./libft fclean
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re