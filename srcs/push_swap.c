/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:45:18 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/24 13:30:51 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int			free_me;
	t_stack		stack;
	int			stack_size;

	free_me = 0;
	argv++;
	if (argc < 2)
		error_message();
	if (argc == 2)
	{
		argv = ft_split(*argv, ' ');
		free_me++;
	}
	stack_size = stack_size_calculator(argc, argv);
	init_stack(&stack, stack_size);
	if_valid_args(argv, stack.a->size);
	create_array(argv, stack.a);
	array_indexing(&stack);
	find_mid_value(stack.a);
	check_number(&stack);
	if (free_me)
		free_argv(argv);
	free_stack(&stack);
}
