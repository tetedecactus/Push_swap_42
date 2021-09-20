/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:33:10 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/20 10:13:23 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void less_than_three(int *arr, int stack_size)
{
    if (arr[0] > arr[1])
        swap(arr); ft_putstr_fd("sa\n", 1);
}

void stack_of_three(int *arr, int stack_size)
{
	if (arr[0] > arr[1] && arr[0] < arr[2])
    {
		swap(arr); 
        ft_putstr_fd("sa\n", 1);
    }
    else if (arr[0] > arr[1] && arr[1] > arr[2])
    {
        swap(arr); ft_putstr_fd("sa\n", 1);
        r_rotate(arr, stack_size); ft_putstr_fd("rra\n", 1);
    }
    else if (arr[0] > arr[1] && arr[1] < arr[2])
    {
        rotate(arr, stack_size); ft_putstr_fd("ra\n", 1);
    }    
    else if (arr[0] < arr[1] && arr[1] > arr[2])
    {
        if (arr[0] > arr[2])
        {
            r_rotate(arr, stack_size); ft_putstr_fd("ra\n", 1);
        }
        else if (arr[0] < arr[2])
        {
            swap(arr); ft_putstr_fd("sa\n", 1);
            rotate(arr, stack_size); ft_putstr_fd("ra\n", 1);
        }
    }
}

int *check_number(int *arr, int stack_size)
{
    if (stack_size < 3)
        less_than_three(arr, stack_size);
    if (stack_size == 3)
        stack_of_three(arr, stack_size);
    return (arr);
}