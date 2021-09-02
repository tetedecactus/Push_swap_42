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

t_array     init_struct_array(int stack_size)
{
    t_array tab;
    
    tab.array_a = malloc(sizeof(int) * stack_size);
    tab.array_b = malloc(sizeof(int) * stack_size);
    tab.array_tempo = malloc(sizeof(int) * stack_size);
    
    return (tab);
}

int main(int argc, char *argv[])
{
    //t_array tab;
    int stack_size;
    int free_me;
    int *array_a;
    
    argv++;
    if (argc < 2)
        error_message();
    if (argc == 2)
    {
        argv = ft_split(argv[0], ' ');
        free_me++;
    }
    stack_size = stack_size_calculator(argc, argv);
    printf("stack = %d\n", stack_size);
    init_struct_array(stack_size);
    if_valid_args(argv, stack_size);
    create_n_print_array(argv, stack_size);
    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    //free(struct);
    printf("fin\n");
}