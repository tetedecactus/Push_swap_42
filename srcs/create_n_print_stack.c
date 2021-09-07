/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_print_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:06:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/07 15:47:13 by olabrecq         ###   ########.fr       */
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

t_stack *create_stack(int stack_size, char *argv[])
{
    int i;
    t_stack *stack_a;
    
    stack_a = init_stack();
    i = 0;
    while (i < stack_size)
    {
        insert_end(&stack_a->head, new_node_init(ft_atoi(argv[i])));
        i++;
    }
    stack_a->tail = stack_a->head;
    while (stack_a->tail->next != NULL)
    {
        stack_a->tail = stack_a->tail->next;
    }
    return (stack_a);
}

/* t_stack         *create_stack_b(int stack_size, char *argv[])
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
    stack_b->tail = stack_b->head;
    while (stack_b->tail->next != NULL)
    {
        stack_b->tail = stack_b->tail->next;
    }
    return (stack_b);
} */

void    print_stack(t_stack *stack)
{
    t_stack_node *temp;
    temp = stack->head;
    ft_putstr_fd("stack = ", 1);
    while (temp->next != NULL)
    {
        ft_putnbr((long )temp->data);
        ft_putchar(',');
        temp = temp->next;
    }
    ft_putnbr((long )temp->data);
    ft_putchar(',');
    ft_putchar('\n');
 
} 