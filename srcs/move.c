/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:02:21 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/08 11:04:11 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* push = pa & pb : swap les 2 head de stack a & stack b
* swap = sa & sb : swap les 2 "premier" t_stack_node (head n head->prev)
* rotate = ra & rb : rotate le premier et dernier element (head n tail) 
* r_rotate = rra & rrb : rotate le dernier et premier element (tail n head)
*/

#include "../includes/push_swap.h"

void push(t_stack_node *head_a, t_stack_node *head_b)
{
    int temp;

    temp = 0;
    temp = head_a->data;
    head_a->data = head_b->data;
    head_b->data = temp;
}

void swap(t_stack_node *head)
{
    if (head == NULL || head->next == NULL)
        return ; 
    int temp;

    temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;
}

void rotate(t_stack *stack_data)
{
    // if (stack_data->size < 2)
    //     return ;
    t_stack_node    *next_head;
        
    next_head = stack_data->head->next;
    // shift head to bottom 
    stack_data->tail->next = stack_data->head;
    stack_data->head->prev = stack_data->tail;
    stack_data->head->next = NULL;
    stack_data->tail = stack_data->head;
    //make top_next as new head 
    stack_data->head = next_head;
    stack_data->head->prev = NULL; 
}

void r_rotate(t_stack *stack_data)
{
    if (stack_data->size < 2)
         return ;
    t_stack_node    *next_tail;
        
    next_tail = stack_data->head->next;
    // shift head to bottom 
    stack_data->head->next = stack_data->tail;
    stack_data->tail->prev = stack_data->head;
    stack_data->tail->next = NULL;
    stack_data->head = stack_data->head;
    //make top_next as new head 
    stack_data->tail = next_tail;
    stack_data->tail->prev = NULL; 
}
