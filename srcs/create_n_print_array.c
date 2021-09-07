/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_print_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:50:31 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/07 13:53:46 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *create_array(char *argv[], int stack_size)
{
    int i;
    int *array_a;
    
    array_a = malloc(sizeof(char) * stack_size - 1);

    i = 0;
    while (i < stack_size)
    {
        array_a[i] = ft_atoi(argv[i]);
        i++;
    }
    return (array_a);
}  

void print_array(int *arr, int stack_size)
{
    int i;

    i = 0;
    while(i < stack_size)
    {
        ft_putnbr(arr[i]);
        ft_putchar(',');
        i++;
    }
    free(arr);
    ft_putchar('\n');
} 