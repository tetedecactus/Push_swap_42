/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:46:41 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/14 15:08:41 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// quick sort on array
void quick_array_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

// low =  arr[0], high = lengh - 1
int partition_array(int arr[], int low, int high)
{
    int i;
    int j;
    int pivot;

    j = low;
    i = (low - 1);
    while (j <= high - 1)
    {
        pivot = arr[high];
        if (arr[j] < pivot)
        {
            i++;
            quick_array_swap(&arr[i], &arr[j]);
        }
        j++;
    }
    quick_array_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort_array(int arr[], int low, int high)
{
    int pi;

    if (low < high)
    {
        pi = partition_array(arr, low, high);

        quick_sort_array(arr, low, pi - 1);
        quick_sort_array(arr, pi + 1, high);
    }
}
//--------------- Quick sort double linked list ----------------//

void swap_in_stack(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

t_stack_node *partition(t_stack_node *low, t_stack_node *high)
{
    int x;
    t_stack_node *i;
    t_stack_node *j;
    
    j = low;
    i = low->prev;
    x = high->data;
    while (j != high)
    {
        if (j->data <= x)
        {
            if (i == NULL)
                i = low;
            else
                i = i->next;
            swap_in_stack(&(i->data), &(j->data));
        }
        j = j->next;
    }
    if (i == NULL)
        i = low;
    else
        i = i->next;
    swap_in_stack(&(i->data), &(high->data));
    
    return (i);
}

void _quick_sort(t_stack_node *low, t_stack_node *high)
{
    t_stack_node *p;
    
    if (high != NULL && low != high && low != high->next)
    {
        p = partition(low, high);
        _quick_sort(low, p->prev);
        _quick_sort(p->next, high);
    }
}

void quick_sort(t_stack_node *head)
{
    t_stack_node *high;
    
    high = find_last_node(head);
    
    _quick_sort(head, high);
}

//// if i & j swap : pa
//// if j == null && que l > h :  rra then pa
/// if stack_a > 2 element continu sinon si 1er > 2ieme :sa
