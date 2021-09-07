/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:02:21 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/07 16:20:53 by olabrecq         ###   ########.fr       */
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

void rotate(t_stack_node *head, t_stack_node *tail)
{
    // if (head == NULL || head->next == NULL)
    //     return ;
    t_stack_node *temp;

    temp = head;
    head = head->next;
    head->prev = tail;
    tail = temp;
    tail->prev = NULL;

    // temp = head->next;
    // //head->next = NULL;
    // head->prev = tail;
    // //temp->prev = NULL;
    // tail->next = head;
    // tail = head;
    // head = temp;
    // tail->next = NULL;
    printf("%d\n", head->data);
    printf("%d\n", head->next->data);
    printf("%d\n", head->next->next->data);
    printf("%d\n", head->next->next->next->data);
    printf("%d\n", tail->data);
}

void r_rotate(t_stack_node *head, t_stack_node *tail)
{
    int temp;

    temp = 0;
    temp = tail->data;
    tail->data = head->data;
    head->data = temp;
}
