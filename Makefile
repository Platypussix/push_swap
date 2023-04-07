# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             #
#   Updated: 2021/07/09 18:33:23 by shovsepy         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC = $(wildcard */*.c *.c)
OBJ = $(SRC:%.c=%.o)

all = $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re