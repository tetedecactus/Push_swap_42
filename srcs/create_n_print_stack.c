/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_print_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:06:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/15 17:42:15 by olabrecq         ###   ########.fr       */
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

t_stack *create_stack(int stack_size, int *arr, t_stack *stack)
{
    int i;
    
    i = 0;
    while (i < stack_size)
    {
        insert_end(&stack->head, new_node_init(arr[i]));
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

// void *stack_indexing(t_stack *stack, int stack_size)
// {
//     t_stack_node *max;
//     t_stack_node *min;
//     t_stack_node *temp;
//     int max_index;
//     int min_index;
    
//     min_index = 1;
//     max_index = stack_size;
//     while (min_index <= max_index)
//     {
//         max = NULL;
//         min = NULL;
//         temp = stack->head;
//         while (temp != NULL)
//         {
//             if (temp->i <= 0 && (min == NULL || temp->data < min->data))
//                 min = temp;
//             if (temp->i <= 0 && (max == NULL || temp->data > max->data))
//                 max = temp;
//             temp = temp->next;
//         }
//         min->i = min_index++;
//         max->i = max_index++;
//     }
// }