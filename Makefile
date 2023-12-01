# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 17:10:39 by adjoly            #+#    #+#              #
#    Updated: 2023/12/01 17:20:36 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  get_next_line.a

CC = cc

SRCS = get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra

HEADER = get_next_line.h \

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.cc
	$(CC) $(FLAGS) $(HEADER) $< -c -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean