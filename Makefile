# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:52:03 by mel-meka          #+#    #+#              #
#    Updated: 2023/10/04 08:56:14 by mel-meka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rc
RM = rm -f

INCLUDES = includes

MY_SOURCES = srcs/main.c \
			 srcs/map.c \
			 srcs/utils.c \
			 srcs/map_utils.c \
			 srcs/map_print.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

NAME = bsq

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(MY_OBJECTS)

.c.o:
	$(CC) $(FLAGS) $< -c -o $@ -I $(INCLUDES)

clean:
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
