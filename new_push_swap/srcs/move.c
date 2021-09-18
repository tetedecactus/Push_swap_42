/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:40:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/18 15:28:21 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(int *arr)
{
    int temp;

    temp  = arr[0];
    arr[0] =  arr[1];
    arr[1] = temp;
}
	
void rotate(int *arr, int stack_size)
{
    int i;
    int first;

    first = arr[0];
    i = 0;
    while (i < stack_size)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    arr[stack_size - 1] = first;
}

void r_rotate(int *arr, int stack_size)
{
    int i;
    int last;

    last = arr[stack_size - 1];
    i = stack_size - 1;
    while (i > 0)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[0] = last;
}
void push(int *arr_a, int *arr_b)
{
    
}
