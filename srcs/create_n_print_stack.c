/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_print_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:06:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/06 15:58:35 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *init_stack(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    stack->head = NULL;
    stack->tail = NULL;
    return (stack);
}

t_stack *create_stack_a(int stack_size, char *argv[])
{
    int i;
    t_stack *stack_a;
    
    stack_a = init_stack();
    i = 0;
    while (i < stack_size)
    {
        insert_end(&stack_a->head, new_node_init((void *)ft_atol(argv[i])));
        i++;
    }
    return (stack_a);
}

t_stack         *create_stack_b(int stack_size, char *argv[])
{
     int i;
    t_stack *stack_b;
    
    stack_b = init_stack();
    i = 0;
    while (i < stack_size)
    {
        insert_end(&stack_b->head, new_node_init(0));
        i++;
    }
    return (stack_b);
}

void    print_stack(t_stack *stack)
{
    ft_putstr_fd("stack = ", 1);
    while (stack->head != NULL)
    {
        ft_putnbr((long )stack->head->data);
        ft_putchar(',');
        stack->head = stack->head->next;
    }   
    ft_putnbr((long )stack->head->prev->prev->data);
    ft_putchar('\n');
} 