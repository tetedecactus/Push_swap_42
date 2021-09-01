/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_print_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:50:31 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/01 10:37:12 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void create_n_print_array(char *argv[], int stack_size)
{
    int i;
    int array_a[stack_size];
    int array_b[stack_size];
    int array_tempo[stack_size];

    i = 0;
    while (i < stack_size)
    {
        array_a[i] = ft_atol(argv[i]);
        array_b[i] = 0;
        array_tempo[i] = array_a[i];
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
}
