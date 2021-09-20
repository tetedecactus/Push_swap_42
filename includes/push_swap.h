/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:27:02 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/20 14:44:43 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_arr
{
    int     *arr;
    int     size;
    int     min;
    int     max;
    int     mid;
} t_arr;

typedef struct  s_stack
{
  t_arr     *a;
  t_arr     *b;
  t_arr     *t;
}               t_stack;

// Get stack
int             get_stack(int argc, char **argv);
void            init_stack(t_stack *stack, int stack_size);

// Stack analizer function
int             stack_size_calculator(int argc, char *argv[]);
void            if_valid_args(char *argv[], int stack_size);

// Create n print array
void            create_array(char *argv[], t_arr *stack);
void            print_array(int *arr, int stack_size);
void            delete_array(int *arr_b, int stack_size);
void            array_indexing(t_stack *stack);
int             find_mid_value(t_stack *value);


// Error message function
void            error_message();

// Outils function (fonction de ma libft)
void	          ft_putstr_fd(char *s, int fd);
int	            ft_atoi(const char *str);
int	            ft_isdigit(int c);
void            ft_putchar(char c);
void	          ft_putnbr(int nb);
char	          **ft_split(char const *s, char c);
void	          ft_bzero(void *s, size_t n);
void	          *ft_calloc(size_t count, size_t size);

// Free argument function 
void	          free_argv(char *argv[]);

// Quick sort  on array function
int             *quick_sort_array(int arr[], int low, int high);

// Move function
void            swap(int *arr);
void            rotate(int *arr, int stack_size);
void            r_rotate(int *arr, int stack_size);
void            push(int *arr_a, int *arr_b, int stack_size);

// Check number of digit
int             *check_number(int *arr, int stack_size);
void            stack_of_three(int *arr, int stack_size);
void            less_than_three(int *arr, int stack_size);

#endif