/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:25:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/16 13:10:43 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    int free_me;
    int *arr;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = malloc(sizeof(t_stack));
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
    stack_b->head = NULL;
    //stack_a->size = stack_size_calculator(argc, argv);
    printf("stack size = %d\n", stack_a->size);
    //valid arg
    if_valid_args(argv, stack_a->size);
    //create n print array
    arr = create_array(argv, stack_a->size);
    ft_putstr_fd("array = ", 1);
    print_array(arr, stack_a->size);
    //quick_sort_array(arr, 0, (stack_a->size - 1));
    ft_putstr_fd("sorted array = ", 1);
    print_array(arr, stack_a->size);
    arr = array_indexing(arr, stack_a->size);
    print_array(arr, stack_a->size);

    //create n print stack a & b
    //stack_a = create_stack(stack_a->size, argv, stack_a);
    //print_stack(stack_a);
    //--------TEST TESTING TEST --------//
    //quick_sort(stack_a->head);
    //check_stack(stack_a, stack_a->size);
    //stack_indexing(stack_a, stack_a->size);
    //radix_sort(stack_a->size, stack_a, stack_b);
    //print_stack(stack_a);
    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    //deallocate(&stack_a, &stack_b);
    printf("fin\n");
}
