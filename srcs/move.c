/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:02:21 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/15 19:15:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* push = pa & pb : swap les 2 head de stack a & stack b
* swap = sa & sb : swap les 2 "premier" t_stack_node (head n head->prev)
* rotate = ra & rb : rotate le premier element a la fin (head n tail) 
* r_rotate = rra & rrb : rotate le dernier element au debut (tail n head)
*/

#include "../includes/push_swap.h"

void push(t_stack *stack_a, t_stack *stack_b)
{
    t_stack_node *futur_head;
    
    if (stack_a->head == NULL)
        return ; 
    futur_head = stack_a->head;
    stack_a->head =  stack_a->head->next;
    if (stack_a->head != NULL)
        stack_a->head->prev = NULL;
    futur_head->next = NULL;
    if (stack_b->head != NULL)
    {
        stack_b->head->prev = futur_head;
        futur_head->next = stack_b->head;
    }
    stack_b->head = futur_head;
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

void ss_swap(t_stack_node *head_a, t_stack_node *head_b)
{
    swap(head_a);
    swap(head_b);
}

void rotate(t_stack *stack_data)
{
    if (stack_data->size < 2)
        return ;
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

void rr_rotate(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}

void r_rotate(t_stack *stack_data)
{
    if (stack_data->size < 2)
         return ;
    t_stack_node    *next_tail;
        
    next_tail = stack_data->tail->prev;
    // shift tail to head
    stack_data->head->prev = stack_data->tail;
    stack_data->tail->next = stack_data->head;
    stack_data->head->prev = NULL;
    stack_data->head = stack_data->tail;
    // make tail_next as new tail
    stack_data->tail = next_tail;
    stack_data->tail->next = NULL; 
}

void rr_r_rotate(t_stack *stack_a, t_stack *stack_b)
{
    r_rotate(stack_a);
    r_rotate(stack_b);
}