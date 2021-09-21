/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:33:10 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/21 14:05:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void less_than_three(t_arr *stack)
{
    if (stack->arr[0] > stack->arr[1])
        swap(stack); ft_putstr_fd("sa\n", 1);
}

void stack_of_three(t_arr *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[0] < stack->arr[2])
    {
		swap(stack); 
        ft_putstr_fd("sa\n", 1);
    }
    else if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2])
    {
        swap(stack); ft_putstr_fd("sa\n", 1);
        r_rotate(stack); ft_putstr_fd("rra\n", 1);
    }
    else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2])
    {
        rotate(stack); ft_putstr_fd("ra\n", 1);
    }    
    else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2])
    {
        if (stack->arr[0] > stack->arr[2])
        {
            r_rotate(stack); ft_putstr_fd("ra\n", 1);
        }
        else if (stack->arr[0] < stack->arr[2])
        {
            swap(stack); ft_putstr_fd("sa\n", 1);
            rotate(stack); ft_putstr_fd("ra\n", 1);
        }
    }
}

int *check_number(t_arr *stack)
{
    if (stack->size < 3)
        less_than_three(stack);
    if (stack->size == 3)
        stack_of_three(stack);
    return (stack->arr);
}