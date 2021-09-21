/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:42:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/21 10:34:06 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
            quick_array_swap(&(arr[i]), &(arr[j]));
        }
        j++;
    }
    quick_array_swap(&(arr[i + 1]), &(arr[high]));
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