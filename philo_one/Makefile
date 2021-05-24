# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 01:44:28 by ibrahim           #+#    #+#              #
#    Updated: 2021/05/24 21:46:26 by ibrahim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER		=			philo.h
	
OBJS        =			${SRCS:.c=.o}

NAME		=			philo_one

RM			=			rm -f

FLAGS		=			-g3 -Wall -Wextra -Werror -lpthread

SRCS		=			init.c main.c utils.c\

all:	$(NAME)

%.o: %.c 	$(HEADER)
		gcc $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
		gcc $(OBJS) $(FLAGS) -o $(NAME) -lm

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: re clean fclean