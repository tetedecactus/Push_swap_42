/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:36:11 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/24 12:54:52 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	array_indexing(t_stack *stack)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	index = 1;
	copie_stack_a(stack);
	quick_sort_array(stack->t->arr, 0, stack->t->size - 1);
	while (i < stack->t->size)
	{
		j = 0;
		while (j < stack->t->size)
		{
			if (stack->a->arr[i] > stack->t->arr[j])
				index++;
			j++;
		}
		stack->a->arr[i] = index;
		index = 1;
		i++;
	}
}

void	create_array(char *argv[], t_arr *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		stack->arr[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	print_array(int *arr, int stack_size)
{
	int		i;

	i = 0;
	while (i < stack_size)
	{
		ft_putnbr(arr[i]);
		ft_putchar(',');
		i++;
	}
	ft_putchar('\n');
}

void	find_mid_value(t_arr *value)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (i < value->size)
		result += value->arr[i++];
	value->mid = result / value->size;
}
