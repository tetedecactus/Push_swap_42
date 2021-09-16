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
        swap(stack->head); ft_putstr_fd("sa\n", 1);
    // 2ieme cas   
    if (stack->head->data > stack->head->next->data && stack->head->next->data > stack->head->next->next->data)
    {
        swap(stack->head); ft_putstr_fd("sa\n", 1);
        r_rotate(stack); ft_putstr_fd("ra\n", 1);
    }
    // 3ieme cas
    if (stack->head->data > stack->head->next->data && stack->head->next->data < stack->head->next->next->data)
        rotate(stack); ft_putstr_fd("ra\n", 1);
    // 4ieme &  5ieme cas
    if (stack->head->data < stack->head->next->data && stack->head->next->data > stack->head->next->next->data)
    {
        if (stack->head->data < stack->head->next->next->data)
        {
            swap(stack->head); ft_putstr_fd("sa\n", 1);
            rotate(stack); ft_putstr_fd("ra\n", 1);
        }
        else
        r_rotate(stack); ft_putstr_fd("rra\n", 1);
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