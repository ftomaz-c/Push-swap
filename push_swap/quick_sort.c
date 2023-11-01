/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:58:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/11/01 17:18:37 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		quick_sort_partition(int arr[], int low, int high);
void	quick_sort(int *arr, int low, int high);

void	quick_sort(int *arr, int low, int high)
{
	int	pivot_idx;

	if (low >= high)
		return ;
	pivot_idx = quick_sort_partition(arr, low, high);
	quick_sort(arr, low, pivot_idx - 1);
	quick_sort(arr, pivot_idx + 1, high);
}

int	find_median(int arr[], int a, int b, int c)
{
	int	x;
	int	y;
	int	z;

	x = arr[a];
	y = arr[b];
	z = arr[c];
	if ((x - y) * (z - x) >= 0)
		return (a);
	else if ((y - x) * (z - y) >= 0)
		return (b);
	else
		return (c);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	quick_sort_partition(int arr[], int low, int high)
{
	int	pivot_index;
	int	pivot;
	int	idx;
	int	i;

	pivot_index = find_median(arr, low, (low + high) / 2, high);
	pivot = arr[pivot_index];
	ft_swap (&arr[high], &arr[pivot_index]);
	idx = low - 1;
	i = low;
	while (i < high)
	{
		if (arr[i] <= pivot)
		{
			idx++;
			ft_swap (&arr[i], &arr[idx]);
		}
		i++;
	}
	ft_swap (&arr[high], &arr[idx + 1]);
	return (idx + 1);
}

