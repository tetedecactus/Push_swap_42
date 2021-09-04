/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:25:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/01 13:08:46 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    int stack_size;
    int free_me;
    //t_stack *stack_a;
    int *arr;

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

    //arr = malloc(sizeof(stack_size));
////probeleme//////////
    //printf ("array =");
    arr = create_array(argv, stack_size);
    print_array(arr, stack_size);
////probleme 2/////////
    //printf ("stack =");
    //stack_a = create_stack(stack_size, argv);
    //print_stack(stack_a);

    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    free(arr);
    printf("fin\n");
}
