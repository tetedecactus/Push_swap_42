/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:40:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/21 14:00:02 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_arr *stack)
{
    int temp;

    temp  = stack->arr[0];
    stack->arr[0] =  stack->arr[1];
    stack->arr[1] = temp;
}
	
void rotate(t_arr *stack)
{
    int i;
    int first;

    first = stack->arr[0];
    i = 0;
    while (i < stack->size)
    {
        stack->arr[i] = stack->arr[i + 1];
        i++;
    }
    stack->arr[stack->size - 1] = first;
}

void r_rotate(t_arr *stack)
{
    int i;
    int last;

    last = stack->arr[stack->size - 1];
    i = stack->size - 1;
    while (i > 0)
    {
        stack->arr[i] = stack->arr[i - 1];
        i--;
    }
    stack->arr[0] = last;
}

void push_b(t_arr *stack_a, t_arr *stack_b)
{
    int i;
    int temp;

    i = 0;
    temp = stack_a->arr[0];
    while (i < stack_a->size - 1)
    {
        stack_a->arr[i] = stack_a->arr[i + 1];
        i++;
    }
    stack_a->size--;
    i = stack_b->size;
    while (i > 0)
    {
        stack_b->arr[i] = stack_b->arr[i - 1];
        i--;
    }
    stack_b->arr[0] = temp;
    stack_b->size++;
}

void push_a(t_arr *stack_b, t_arr *stack_a)
{
    int i;
    int temp;

    i = 0;
    temp = stack_b->arr[0];
    while (i < stack_b->size - 1)
    {
        stack_b->arr[i] = stack_b->arr[i + 1];
        i++;
    }
    stack_b->size--;
    i = stack_a->size;
    while (i > 0)
    {
        stack_a->arr[i] = stack_a->arr[i - 1];
        i--;
    }
    stack_a->arr[0] = temp;
    stack_a->size++;
}
