/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:25:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/05 13:49:52 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *init_stack_a(void)
{
    t_stack *stack_a;

    stack_a->head = NULL;
    stack_a->tail = NULL;
    return (stack_a);
}

t_stack *init_stack_b(void)
{
    t_stack *stack_b;

    stack_b->head = NULL;
    stack_b->tail = NULL;
    return (stack_b);
}

int main(int argc, char *argv[])
{
    int stack_size;
    int free_me;
    int *arr;
    t_stack *stack_a;

    stack_a = malloc(sizeof(t_stack));
    argv++;
    if (argc < 2)
        error_message();
    if (argc == 2)
    {
        argv = ft_split(argv[0], ' ');
        free_me++;
    }
    stack_size = stack_size_calculator(argc, argv);
    printf("stack size = %d\n", stack_size);
    if_valid_args(argv, stack_size);
    ft_putstr_fd("array = ", 1);
    arr = create_array(argv, stack_size);
    print_array(arr, stack_size);



    ////probleme 2///////// create stack probleme
    ft_putstr_fd("stack = ", 1);
    stack_a = create_stack(stack_size, argv);
    //printf("%d,", stack_a->head->data);
    print_stack(stack_a);





    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    //free(arr);
    printf("fin\n");
}
