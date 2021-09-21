/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:45:18 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/21 13:09:58 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    int            free_me;
    t_stack         stack;
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
    init_stack(&stack, stack_size);
    printf("stack size = %d\n", stack.a->size);
    if_valid_args(argv, stack.a->size);
    create_array(argv, stack.a);
    ft_putstr_fd("array = ", 1);
    ft_putstr_fd("array a = ", 1);  print_array(stack.a->arr, stack.a->size);
    ft_putstr_fd("array b = ", 1);  print_array(stack.b->arr, stack.b->size);
    array_indexing(&stack);
    ft_putstr_fd("array a = ", 1);  print_array(stack.a->arr, stack.a->size);
    printf("max value = %d\n", stack.a->max);
    printf("min value = %d\n", stack.a->min);
    printf("mid value = %d\n", stack.a->mid);

    // //check_number(arr_a, stack_size);
    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    printf("fin\n");
}
// besoin de debugger array indexing 
    //find_max_value(stack.a);
    //find_min_value(stack.a);
    //find_mid_value(stack.a);
    //stack.a->mid = stack.a->min + stack.a->max / stack.a->size;