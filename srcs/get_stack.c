/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:53:15 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/22 10:05:39 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_stack(int argc, char *argv[])
{
    int need_to_free;
    
    need_to_free = 0;
    argv++;
    if (argc < 2)
        error_message();
    if (argc == 2)
    {
        need_to_free++;
        argv = ft_split(*argv, ' ');
    }
    return (need_to_free);
}

t_arr *allocate_stack(int stack_size)
{
    t_arr *stack;
    
    stack = ft_calloc(1, sizeof(t_arr));
    stack->arr = ft_calloc(stack_size, sizeof(int));
    stack->size = stack_size;
    if (stack->arr == NULL || stack == NULL)
        return (NULL);
        
    return (stack);
}

void init_stack(t_stack *stack, int stack_size)
{
    stack->a = allocate_stack(stack_size);
    stack->b = allocate_stack(stack_size);
    stack->t = allocate_stack(stack_size);
    stack->a->a = 1;
}

void copie_stack_a(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->t->size)
    {
        stack->t->arr[i] = stack->a->arr[i];
        i++;
    }
}