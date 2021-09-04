/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_print_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:50:31 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/01 13:07:46 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void create_n_print_stack(char *argv[], int stack_size)
{
    int i;
    t_stack *stack_a;
    t_stack *stack_b;

    i = 0;
    while (i < stack_size)
    {
        stack_a->head->data = ft_atol(argv[i]);
        stack_b->head->data = 0;
        head = head->next;
        i++;
    }
    i = 0;
    while(i < stack_size)
    {
        ft_putnbr(array_a[i]);
        ft_putchar(',');
        i++;
    }
    ft_putchar('\n');
    return (array_a);
}  */

int *create_n_print_array(char *argv[], int stack_size)
{
    int i;
    int *array_a;
    
    array_a = malloc(sizeof(int) * stack_size);

    i = 0;
    while (i < stack_size)
    {
        array_a[i] = ft_atol(argv[i]);
        i++;
    }
    i = 0;
    while(i < stack_size)
    {
        ft_putnbr(array_a[i]);
        ft_putchar(',');
        i++;
    }
    ft_putchar('\n');
    return (array_a);
} 