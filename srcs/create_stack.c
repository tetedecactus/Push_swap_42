/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:06:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/01 11:42:14 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack     *create_stack(int stack_size, char *argv[]) 
{
    int i;
    t_stack *stack_a;

    stack_a = malloc(sizeof(t_stack_node));
    i = 0;       
    while (i < stack_size)
    {
        stack_a->head->data = ft_atol(argv[i]);
        i++;
        stack_a->head = stack_a->head->next;
    }
    printf("fait");
    return (stack_a);
}

void    print_stack(t_stack *stack)
{
    t_stack *current = stack; 
    printf("stack a = ");
    while (current->head != NULL)
    {
        printf("%d\n", current->head->data);
        current->head = current->head->next;
    }  
} 