/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:06:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/05 13:52:20 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* t_stack     *create_stack(int stack_size, char *argv[]) 
{
    int i;
    t_stack *stack_a;

    stack_a = malloc(sizeof(t_stack));
    i = 0;       
    while (i < stack_size)
    {
        stack_a->head->data = ft_atol(argv[i]);
        i++;
        stack_a->head = stack_a->head->next;
    }
    printf("fait");
    stack_a->tail= NULL;
    return (stack_a);
} */

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
        insert_end(&stack_a->head, ft_atol(argv[i]));
        printf("%d,", stack_a->head->data);
        i++;
        stack_a->head = stack_a->head->next;
    }
    printf("\n");
    return (stack_a);
}

void    print_stack(t_stack *stack)
{
    printf("stack a = ");
    //printf("%d,", stack->tail->data);
    while (stack->head != NULL)
    {
        //printf("%d\n", stack->head->data);
        stack->head = stack->head->next;
    }  
} 