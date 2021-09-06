/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_function.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:07:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/06 12:37:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* deallocate : sur 3 node tu commence a la node2 pour deallocate la 1, ensuite tu avance et deallocate la 2...
* a la fin (apres loop) tu deallcate celle qui reste 
*/

#include "../includes/push_swap.h"

void deallocate(t_stack_node **tail,t_stack_node **head)
{
    if (*tail == NULL)
        return;
   t_stack_node *curr = *tail;
    while (curr->next != NULL)
    {
        curr = curr->next;
        free(curr->prev);
    }
    free(curr);
    
    *tail = NULL;
    *head = NULL;
}

t_stack_node	*find_last_node(t_stack_node *node)
{
	while (node)
	{
		if (node->next == NULL)
			return (node);
		node = node->next;
	}
	return (node);
}

void  insert_end(t_stack_node **head, t_stack_node *new_head)
{
    t_stack_node *node;

    if (head != NULL)
    {
        if (*head != NULL)
        {
            node = find_last_node(*head);
            node->next = new_head;
            new_head->prev = node;
        }
        else
            *head = new_head;
    }
}

// ft_lstnew de la libft up grape pour double linked list
t_stack_node *new_node_init(void *data)
{
    t_stack_node *new_node;

    new_node = malloc(sizeof(t_stack_node));
    if (new_node == NULL)
        return (NULL);
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return (new_node);
}

void free_stack(t_stack_node *head)
{
    t_stack_node *next;

    if (head != NULL)
    {
        next =  head->next;
        free(head->data);
        free(head);
        free_stack(next);
    }
}