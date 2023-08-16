/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:58:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/16 10:13:20 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		partition(int arr[], int lo, int hi);
void	quick_sort(int *arr, int lo, int hi);

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int len = sizeof(arr) / sizeof(arr[0]);

	ft_printf("Original array: ");
	int i = 0;
	while (i < len) {
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");

	quick_sort(arr, 0, len - 1);

	ft_printf("Sorted array: ");
	i = 0;
	while (i < len) {
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");

	return 0;
}

void	quick_sort(int *arr, int lo, int hi) {

	if (lo >= hi)
		return;

	int pivot_idx = partition(arr, lo, hi);

	quick_sort(arr, lo, pivot_idx - 1);
	quick_sort(arr, pivot_idx + 1, hi);
}

/* int	partition(int *arr, int lo, int hi) { //Lomuto partition technique

	int	pivot = arr[hi];
	int	idx = lo - 1;
	int	i = lo;

	while (i < hi) {
		if (arr[i] <= pivot) {
			idx++;
			int tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
		}
		i++;
	}

	idx++;
	arr[hi] = arr[idx];
	arr[idx] = pivot;

	return idx;
} */

int find_median(int arr[], int a, int b, int c) {
	int x = arr[a];
	int y = arr[b];
	int z = arr[c];

	if ((x - y) * (z - x) >= 0) {
		return a;
	}
	else if ((y - x) * (z - y) >= 0) {
		return b;
	}
	else {
		return c;
	}
}

int partition(int arr[], int lo, int hi) { //median of three partition tecnique
	int pivot_index = find_median(arr, lo, (lo + hi) / 2, hi);
	int pivot = arr[pivot_index];

	int tmp = arr[hi];
	arr[hi] = arr[pivot_index];
	arr[pivot_index] = tmp;

	int idx = lo - 1;
	int i = lo;
	while (i < hi) {
		if (arr[i] <= pivot) {
			idx++;
			tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
		}
		i++;
	}

	tmp = arr[hi];
	arr[hi] = arr[idx + 1];
	arr[idx + 1] = tmp;

	return idx + 1;
}
