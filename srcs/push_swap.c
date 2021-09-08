/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:25:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/08 10:48:39 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    int free_me;
    int *arr;
    t_stack *stack_a;
    t_stack *stack_b;

    free_me = 0;
    argv++;
    if (argc < 2)
        error_message();
    if (argc == 2)
    {
        argv = ft_split(argv[0], ' ');
        free_me++;
    }
    stack_a = init_stack(argc, argv);
    //stack_a->size = stack_size_calculator(argc, argv);
    printf("stack size = %d\n", stack_a->size);
    //valid arg
    if_valid_args(argv, stack_a->size);
    //create n print array
    ft_putstr_fd("array = ", 1);
    arr = create_array(argv, stack_a->size);
    print_array(arr, stack_a->size);
    //create n print stack a & b
    stack_a = create_stack(stack_a->size, argv, stack_a);
    print_stack(stack_a);
    
    swap(stack_a->head);
    print_stack(stack_a);
    
    rotate(stack_a);
    print_stack(stack_a);

    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    //deallocate(&stack_a, &stack_b);
    printf("fin\n");
}
