/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:27:02 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/18 16:21:59 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define A = 1
#define B = 2
#define both = 3

typedef struct  s_info
{
    int big_pivot;
    int small_pivot;
    int ra;
    int rb;
    int pa;
    int pb;   
    int index;
}               t_info;

// Get stack
int             get_stack(int argc, char **argv);

// Stack analizer function
int             stack_size_calculator(int argc, char *argv[]);
void            if_valid_args(char *argv[], int stack_size);

// Create n print array
int             *create_array(char *argv[], int stack_size);
void            print_array(int *arr, int stack_size);
void            delete_array(int *arr_b, int stack_size);
int             *array_indexing(int *arr, int stack_size);
int             find_mid_value(int stack_size);

// Error message function
void            error_message();

// Outils function (fonction de ma libft)
void	        ft_putstr_fd(char *s, int fd);
int	            ft_atoi(const char *str);
int	            ft_isdigit(int c);
void            ft_putchar(char c);
void	        ft_putnbr(int nb);
char	        **ft_split(char const *s, char c);

// Free argument function 
void	        free_argv(char *argv[]);

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