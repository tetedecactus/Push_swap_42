# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 12:29:07 by olabrecq          #+#    #+#              #
#    Updated: 2021/09/22 14:08:15 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	./srcs/create_array.c \
		./srcs/check_number_of_digit.c \
		./srcs/error_message.c ./srcs/free_arg.c ./srcs/move.c ./srcs/outils.c \
		./srcs/push_swap.c ./srcs/stack_analizer.c ./srcs/ft_split.c \
		./srcs/quick_sort.c ./srcs/get_stack.c ./srcs/radix_sort.c

OBJS = ${SRCS:.c=.o}
CC = gcc 
FLAGS = -g -Wall -Wextra -Werror
all: ${NAME}

${NAME}:${OBJS}
		@${CC} ${OBJS} ${FLAGS} -o ${NAME}

clean: 
		rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
re: fclean all

.PHONY: clean fclean re all

run: 
		./push_swap 212 75 45 34 23