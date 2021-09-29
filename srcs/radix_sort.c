/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:43:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/29 11:53:08 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_nb_byte(t_arr *stack)
{
	int		i;

	i = 0;
	while (stack->size >> i != 0)
		i++;
	return (i);
}

void	radix_sort(t_arr *stack_a, t_arr *stack_b)
{
	int		i;
	int		j;
	int		k;
	int		len;
	int		nb_bit;

	i = -1;
	len = stack_a->size;
	nb_bit = find_nb_byte(stack_a);
	while (++i < nb_bit)
	{
		j = -1;
		while (++j < len)
		{
			k = stack_a->arr[0];
			if (((k >> i) & 1) == 1)
				rotate(stack_a);
			else
				push_b(stack_a, stack_b);
		}
		while (stack_b->arr[0] != 0)
			push_a(stack_b, stack_a);
	}
}
