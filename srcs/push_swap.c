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
