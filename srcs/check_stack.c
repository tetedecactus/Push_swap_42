/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:18:46 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/16 09:58:38 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void less_than_three(t_stack *stack)
{
    if (stack->head->data > stack->head->next->data)
        swap(stack->head); ft_putstr_fd("sa\n", 1);
}

void stack_of_three(t_stack *stack)
{
    if (stack->head->data > stack->head->next->data && stack->head->data < stack->head->next->next->data)
    {
        swap(stack->head); ft_putstr_fd("sa\n", 1);
    }    
    else if (stack->head->data > stack->head->next->data && stack->head->next->data > stack->head->next->next->data)
    {
        swap(stack->head); ft_putstr_fd("sa\n", 1);
        r_rotate(stack); ft_putstr_fd("ra\n", 1);
    }
    else if (stack->head->data > stack->head->next->data && stack->head->next->data < stack->head->next->next->data)
    {
        rotate(stack); ft_putstr_fd("ra\n", 1);
    }    
    else if (stack->head->data < stack->head->next->data && stack->head->next->data > stack->head->next->next->data)
    {
        if (stack->head->data > stack->head->next->next->data)
        {
            r_rotate(stack); ft_putstr_fd("rra\n", 1);
        }
        else if (stack->head->data < stack->head->next->next->data)
        {
            swap(stack->head); ft_putstr_fd("sa\n", 1);
            rotate(stack); ft_putstr_fd("ra\n", 1);
        }
    }
}

t_stack *stack_of_five(t_stack *stack_a, t_stack *stack_b, int stack_size, t_stack_node *mid_stack)
{
    while (stack_a->head != NULL)
    {
        if (stack_a->head->data <= mid_stack->data)
        {
            push(stack_a, stack_b); ft_putstr_fd("pb\n", 1);
        }
        else   
            stack_a->head = stack_a->head->next;
    }
    while (stack_a->head != NULL)
        stack_a->head = stack_a->head->prev;
    stack_of_three(stack_a);
    less_than_three(stack_b);
    push(stack_b, stack_a);
    push(stack_b, stack_a);
}

// t_stack *stack_more_than_five(t_stack *stack, int stack_size)
// {
    
// }

void  check_stack(t_stack *stack_a, t_stack *stack_b, int stack_size, t_stack_node *mid)
{
    if (stack_a->size < 3)
    {
        less_than_three(stack_a);
    }
    if (stack_a->size == 3)
    {
        stack_of_three(stack_a);
    }
    // if (stack_a->size == 5)
    // {
    //     stack_of_five(stack_a, stack_b, stack_a->size, mid);
    // }
}