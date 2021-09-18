/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_print_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:06:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/18 14:40:23 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *init_stack(int argc, char *argv[])
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = stack_size_calculator(argc, argv);
    return (stack);
}

t_stack *create_stack(int stack_size, char **argv, t_stack *stack)
{
    int i;
    
    i = 0;
    while (i < stack_size)
    {
        insert_end(&stack->head, new_node_init(ft_atoi(argv[i])));
        i++;
    }
    stack->tail = stack->head;
    while (stack->tail->next != NULL)
    {
        stack->tail = stack->tail->next;
    }
    return (stack);
}

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

t_stack_node *find_mid_stack(int *arr, t_stack *stack, int stack_size)
{
    t_stack_node *mid_data;

    mid_data->data = find_mid_value(arr, stack_size);
    while (stack->head->data != mid_data->data)
        stack->head = stack->head->next;
    return (mid_data);
}