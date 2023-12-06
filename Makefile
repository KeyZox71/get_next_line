# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 17:10:39 by adjoly            #+#    #+#              #
#    Updated: 2023/12/04 17:04:21 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  get_next_line.a

CC = clang

SRCS = get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra

HEADER = get_next_line.h

$(NAME): $(OBJS)
	$(CC) -o $@ $(SRCS) -g

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADER) $< -c -o $@ -g

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
