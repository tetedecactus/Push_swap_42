/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:25:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/18 14:43:43 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    int          free_me;
    int             *arr;
    int         *arr_temp;
    int              mid;
    t_stack     *stack_a;
    t_stack     *stack_b;

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
    stack_a->size = stack_size_calculator(argc, argv);
    printf("stack size = %d\n", stack_a->size);
    if_valid_args(argv, stack_a->size);
    arr = create_array(argv, stack_a->size);
    arr_temp = create_array(argv, stack_a->size);
    array_indexing(arr, stack_a->size);
    mid = find_mid_value(arr_temp, stack_a->size);
    printf("mid value = %d\n", mid);
    stack_a = create_stack(stack_a->size, arr, stack_a);
    print_stack(stack_a);
    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    //deallocate(&stack_a, &stack_b);
    printf("fin\n");
}
