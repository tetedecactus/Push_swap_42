/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:36:11 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/21 13:04:31 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void array_indexing(t_stack *stack)
{
    int i;
    int j;
    int index;
    
    i = 0;
    index = 1;
    copie_stack_a(stack);
    quick_sort_array(stack->t->arr, 0, stack->t->size -1);
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

void create_array(char *argv[], t_arr *stack)
{
    int i;
    int j;
    int temp;
    
    i = stack->size - 1;
    j = 0;
    while (i >= 0 )
    {
        stack->arr[i] = ft_atoi(argv[j]);
        j++;
        i--;
    }
}  

void delete_array(int *arr_b, int stack_size)
{
    int i;

    i = 0;
    while (i < stack_size)
    {
        arr_b[i] = -1;
        i++;
    }
}

void print_array(int *arr, int stack_size)
{
    int i;

    i = 0;
    while(i < stack_size)
    {
        ft_putnbr(arr[i]);
        ft_putchar(',');
        i++;
    }
    ft_putchar('\n');
} 

void find_mid_value(t_arr *value)
{
   value->mid = value->arr[(value->size + 1 / value->size) - 1];
}

void find_max_value(t_arr *value)
{
    int i;
    
    i = 0;
    value->max = 0;
    while (i < value->size)
    {
        if (value->arr[i] > value->max)
            value->max = value->arr[i];
        i++;
    }
}

void find_min_value(t_arr *value)
{
    int i;
    
    i = 0;
    value->min = value->max;
    while (i < value->size)
    {
        if (value->arr[i] < value->min)
            value->min = value->arr[i];
        i++;
    }
}