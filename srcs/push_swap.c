/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:25:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/06 15:23:31 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    int stack_size;
    int free_me;
    int *arr;
    t_stack *stack_a;
    t_stack *stack_b;
    

    free_me = 0;
    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    argv++;
    if (argc < 2)
        error_message();
    if (argc == 2)
    {
        argv = ft_split(argv[0], ' ');
        free_me++;
    }
    //stack size
    stack_size = stack_size_calculator(argc, argv);
    printf("stack size = %d\n", stack_size);
    //valid arg
    if_valid_args(argv, stack_size);
    //create n print array
    ft_putstr_fd("array = ", 1);
    arr = create_array(argv, stack_size);
    print_array(arr, stack_size);
    //create n print stack a & b
    stack_a = create_stack_a(stack_size, argv);
    stack_b = create_stack_b(stack_size, argv);
    
    ft_putnbr((long )stack_a->head->data);
    write(1, "\n", 1);
    ft_putnbr((long )stack_a->head->next->prev->data);
    write(1, "\n", 1);
    ft_putnbr((long )stack_a->head->next->next->data);
    write(1, "\n", 1);
    ft_putnbr((long )stack_a->head->next->next->next->data);
    write(1, "\n", 1);
    ft_putnbr((long )stack_a->head->next->next->next->next->data);
    write(1, "\n", 1);
    
    ft_putnbr((long )stack_a->head->data);
    write(1, "\n", 1);
    ft_putnbr((long )stack_a->head->next->data);
    write(1, "\n", 1);
    ft_putnbr((long )stack_a->head->next->next->data);
    write(1, "\n", 1);
    ft_putnbr((long )stack_a->head->next->next->next->data);
    write(1, "\n", 1);
    ft_putnbr((long )stack_a->head->next->next->next->next->data);
    write(1, "\n", 1);
    print_stack(stack_a);
    print_stack(stack_b);
    
    // print_stack(stack_a);
    // print_stack(stack_b);
   
        
    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    free_stack(stack_a->head);
    free_stack(stack_b->head);
    //free(stack_a);
    printf("fin\n");
}
