/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_digit_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:58:03 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/27 10:53:12 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
