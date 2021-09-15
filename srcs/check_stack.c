/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:18:46 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/15 19:36:25 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *stack_of_three(t_stack *stack)
{
    // 1ier cas
    if (stack->head->data > stack->head->next->data && stack->head->data < stack->head->next->next->data)
        swap(stack->head);
    // 2ieme cas   
    if (stack->head->data > stack->head->next->data && stack->head->next->data > stack->head->next->next->data)
    {
        swap(stack->head);
        r_rotate(stack);
    }
    // 3ieme cas
    if (stack->head->data > stack->head->next->data && stack->head->next->data < stack->head->next->next->data)
        rotate(stack);
    // 4ieme &  5ieme cas
    if (stack->head->data < stack->head->next->data && stack->head->next->data > stack->head->next->next->data)
    {
        if (stack->head->data < stack->head->next->next->data)
        {
            swap(stack->head);
            rotate(stack);
        }
        else
        r_rotate(stack);
    }
    return (stack);
}

// t_stack *stack_of_five(t_stack *stack, int stack_size)
// {
    
// }

// t_stack *stack_more_than_five(t_stack *stack, int stack_size)
// {
    
// }

t_stack *check_stack(t_stack *stack, int stack_size)
{
    // if (stack->size > 5)
    // {
        
    // }
    if (stack->size == 3)
    {
        stack = stack_of_three(stack);
    }
    // if (stack->size == 5)
    // {
        
    // }
    return (stack);
}