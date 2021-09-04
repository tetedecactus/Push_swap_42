/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:02:21 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/04 14:03:27 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* swap = sa & sb : swap les 2 "premier" t_stack_node (head n head->prev)
* rotate = ra & rb : rotate le premier et dernier element (head n tail) 
* r_rotate = rra & rrb : rotate le dernier et premier element (tail n head)
*/

#include "../includes/push_swap.h"

void swap(t_stack_node *head)
{
    int temp;

    temp = 0;
    temp = head->data;
    head->data = head->prev->data;
    head->prev->data = temp;
}

void rotate(t_stack_node *head, t_stack_node *tail)
{
    int temp;

    temp = 0;
    temp = head->data;
    head->data = tail->data;
    tail->data = temp;
}

void r_rotate(t_stack_node *head, t_stack_node *tail)
{
    int temp;

    temp = 0;
    temp = tail->data;
    tail->data = head->data;
    head->data = temp;
}