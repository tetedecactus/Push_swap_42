NAME = push_swap

SRCS = 	./srcs/create_n_print_array.c \
		./srcs/create_stack.c ./srcs/double_linked_list_function.c \
		./srcs/error_message.c ./srcs/free_arg.c ./srcs/move.c ./srcs/outils.c \
		./srcs/push_swap.c ./srcs/stack_size_calculator.c ./srcs/ft_split.c 

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