# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 01:44:28 by ibrahim           #+#    #+#              #
#    Updated: 2021/06/30 02:35:42 by ibrahim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=			philo_one

HEADER		=			philo.h

GCC			=			gcc

OBJS        =			$(SRCS:.c=.o)

RM			=			rm -f

FLAGS		=			-Wall -Wextra -Werror

INCLUDE		=			-lpthread

SRCS		=			death.c init.c main.c\
						utils.c error.c time.c\
						philo.c print.c sleep.c\
						

all:	$(NAME)

%.o: %.c $(HEADER)
	$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(GCC) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: re clean fclean