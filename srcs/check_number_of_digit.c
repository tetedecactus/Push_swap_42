/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:33:10 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/24 12:39:39 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// orde a l'envers pour renvoyer  a l'endroit dans stack a
void	less_than_three_in_b(t_arr *stack)
{
	if (stack->arr[1] > stack->arr[0])
		swap(stack);
}

void	less_than_three_in_a(t_arr *stack)
{
	if (stack->arr[0] > stack->arr[1])
		swap(stack);
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
		push_b(stack->b, stack->a);
}

void	check_number(t_stack *stack)
{
	if (stack->a->size < 3)
		less_than_three_in_a(stack->a);
	if (stack->a->size == 3)
		stack_of_three(stack->a);
	if (stack->a->size == 4 || stack->a->size == 5)
		stack_of_five(stack);
	if (stack->a->size > 5)
		radix_sort(stack->a, stack->b);
}
