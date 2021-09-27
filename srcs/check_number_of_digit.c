/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:33:10 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/27 10:00:03 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	if_is_sorted(t_arr *stack)
{
	int		i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] < stack->arr[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

void	stack_of_three(t_arr *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[0] < stack->arr[2])
		swap(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2])
	{
		swap(stack);
		r_rotate(stack);
	}
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2])
		rotate(stack);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2])
	{
		if (stack->arr[0] > stack->arr[2])
			r_rotate(stack);
		else if (stack->arr[0] < stack->arr[2])
		{
			swap(stack);
			rotate(stack);
		}
	}
}

void	stack_of_five(t_stack *stack)
{
	int		i;
	int		len;

	i = 0;
	len = stack->a->size;
	while (stack->a->size != 3)
	{
		if (stack->a->arr[i] < stack->a->mid)
			push_b(stack->a, stack->b);
		else
			rotate(stack->a);
	}
	stack_of_three(stack->a);
	less_than_three_in_b(stack->b);
	while (stack->a->size != len)
		push_a(stack->b, stack->a);
}

void	check_number(t_stack *stack)
{
	if (if_is_sorted(stack->a) == 0)
		return ;
	if (stack->a->size < 3)
		less_than_three_in_a(stack->a);
	if (stack->a->size == 3)
		stack_of_three(stack->a);
	if (stack->a->size == 4 || stack->a->size == 5)
		stack_of_five(stack);
	if (stack->a->size > 5)
		radix_sort(stack->a, stack->b);
}
