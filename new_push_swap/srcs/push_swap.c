/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:45:18 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/18 16:22:16 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    int            free_me;
    int             *arr_a;
    int             *arr_b;
    int                mid;
    int         stack_size;

    free_me = 0;
    argv++;
    if (argc < 2)
        error_message();
    if (argc == 2)
    {
        argv = ft_split(*argv, ' ');
        free_me++;
    }
    stack_size = stack_size_calculator(argc, argv);
    printf("stack size = %d\n", stack_size);
    if_valid_args(argv, stack_size);
    arr_a = create_array(argv, stack_size);
    arr_b = create_array(argv, stack_size);
    ft_putstr_fd("array = ", 1);
    print_array(arr_a, stack_size);
    array_indexing(arr_a, stack_size);
    array_indexing(arr_b, stack_size);
    print_array(arr_a, stack_size);
    mid = find_mid_value(arr_b, stack_size);
    printf("mid value = %d\n", mid);
    delete_array(arr_b, stack_size);
    print_array(arr_b, stack_size);
    
    //check_number(arr_a, stack_size);
    print_array(arr_a, stack_size);
    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    printf("fin\n");
}
