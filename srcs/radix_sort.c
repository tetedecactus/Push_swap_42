/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:49:04 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/16 13:44:47 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int power(int exposant, int data)
{
    int ret;

    ret = 1;
    while (exposant-- > 0)
    {
        ret *= data;
    }
    return (ret);
}

// static radix_sort_array(int stack_size, int arr[])
// {

// }

void radix_sort(int stack_size, t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int bit;
    
    i = 0;
    bit = 0;
    while (bit < 8)
    {
        while (i++ <= stack_size)
        {
            printf("inside\n");
            if ((stack_a->head->data ^ power(bit, 2)) <= stack_a->head->data)
                rotate(stack_a);
            else
                push(stack_a, stack_b);
        }
        while (stack_b->head != NULL)
            push(stack_b, stack_a);
        i = 0;
        bit++;
    }
}