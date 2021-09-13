/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:46:41 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/13 13:06:25 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void quick_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
// low =  arr[0], high = lengh - 1
int partition(int *arr, int low, int high)
{
    int i = (low - 1);
    int j = low;
    int pivot = arr[high];

    while (j < high - 1)
    {
        if (arr[j] < pivot)
        {
            i++;
            quick_swap(&arr[i], &arr[j]);
        }
    }
    quick_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
