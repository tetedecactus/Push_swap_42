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

int *array_indexing(int *arr, int stack_size)
{
    int i;
    int j;
    int index;
    int arr_temp[stack_size];
    
    i = 0;
    index = 1;
    while (i < stack_size)
    {
        j = 0;
        while (j < stack_size)
        {
            if (arr[i] > arr[j])
                index++;
            j++;
        }
        arr_temp[i] = index;
        index = 1;
        i++;
    }
    i = 0;
    while (i < stack_size)
    {
        arr[i] = arr_temp[i];
        i++;
    }
    return (arr);
}

int *create_array(char *argv[], int stack_size)
{
    int i;
    int *array_a;
    
    array_a = malloc(sizeof(int) * stack_size);

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
    ft_putchar('\n');
} 

int find_mid_value(int *arr, int stack_size)
{
    int mid_value;

    arr = quick_sort_array(arr, 0, stack_size);
    mid_value = (arr[0] + arr[stack_size] / 2);

    return (mid_value);
}