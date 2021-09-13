/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:26:46 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/08 11:04:29 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack_node
{
    int                 data;
    struct s_stack_node *prev;
    struct s_stack_node *next;
}   t_stack_node;

typedef struct s_stack
{
    t_stack_node        *head;
    t_stack_node        *tail;
    int                 size;
}   t_stack;

/* 
* ---Check stack function---
* 1. Calcul la longueur de la stack 
* 2. Reguarde si j'ai un chiffre en double 
* 3. Reguarde si il y a autre chose que des chiffres
* 4. Check de fonction 2 & 3 ensemble
*/
int             stack_size_calculator(int argc, char *argv[]);
int             if_digit_duplicate(char *argv[], int stack_size);
int             if_array_is_digit(char **argv, int stack_size);
void            if_valid_args(char *argv[], int stack_size);

// Create stack function
t_stack         *create_stack(int stack_size, char *argv[], t_stack *stack);
void            print_stack(t_stack *stack);

// Create and print array
int             *create_array(char *argv[], int stack_size);
void            print_array(int *arr, int stack_size);
t_stack         *init_stack(int argc, char *argv[]);

// Error message function
void            error_message();

// Outils function (fonction de ma libft)
void	        ft_putstr_fd(char *s, int fd);
int	            ft_atoi(const char *str);
int	            ft_isdigit(int c);
void            ft_putchar(char c);
void	        ft_putnbr(int nb);

// ft_split function
char	        **ft_split(char const *s, char c);
static char 	**ft_array(char const *s, char **dst, char c, int l);
int	            ft_num_of_chars(char const *s2, char c, int i);
int	            ft_num_of_lines(char const *s1, char c);

// Free argument function 
void	        free_argv(char *argv[]);

// Move function
void            swap(t_stack_node *head);
void            rotate(t_stack *stack_data);
void            r_rotate(t_stack *stack_data);
void            push(t_stack *stack_a, t_stack *stack_b);


// Double linked list function
t_stack_node	*find_last_node(t_stack_node *node);
void            insert_end(t_stack_node **head, t_stack_node *new_head);
t_stack_node    *new_node_init(int data);
void            deallocate(t_stack **tail, t_stack **head);

// Quick sort function
void            quick_swap(int *a, int *b);
int             partition(int *arr, int low, int high);
void            quick_sort(int *arr, int low, int high);

#endif