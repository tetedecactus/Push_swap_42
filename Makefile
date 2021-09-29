# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 12:29:07 by olabrecq          #+#    #+#              #
#    Updated: 2021/09/29 11:21:03 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	./srcs/create_array.c \
		./srcs/check_number_of_digit.c \
		./srcs/error_message.c ./srcs/free_arg.c ./srcs/move.c ./srcs/outils.c \
		./srcs/push_swap.c ./srcs/stack_analizer.c ./srcs/ft_split.c \
		./srcs/quick_sort.c ./srcs/get_stack.c ./srcs/radix_sort.c ./srcs/outils_2.c \
		./srcs/check_number_of_digit_2.c

OBJS = ${SRCS:.c=.o}
HEADER	= ../includes/push_swap.h
CC = gcc 
FLAGS = -g -Wall -Wextra -Werror

.c.o:
			${CC} ${FLAGS} -I ${HEADER} -c $< -o ${<:.c=.o} 
all: ${NAME}

${NAME}:${OBJS}
		@${CC} ${OBJS} ${FLAGS} -o ${NAME}

clean: 
		rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
re: fclean all

.PHONY: clean fclean re all
