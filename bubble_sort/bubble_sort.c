/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:48:03 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/14 18:35:57 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//implementation of bubble sort

//while i < n - 1
	//while j < n - 1 - i
		//if (arr[j] > arr[j + 1])
			//swap

#include "../libft.h"

int	ft_arrlen(int *arr)
{
	int count = 0;

	while (*arr)
	{
		arr++;
		count++;
	}
	return (count);
}

void	bubble_sort(int *arr)
{
	int	i, j;
	int	n = ft_arrlen(arr);

	i = 0;
	while (i < n - 1) {
		j = 0;
		while (j < n - 1 - i) {
			if (arr[j] > arr[j +1 ]) {
				const int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main()
{
	int	arr[] = {45, 7, 85, 23, 9, 5};
	int	i = 0;
	int	j = 0;

	ft_printf("Oiginal:	");
	while (i < 6)
		ft_printf("%i ", arr[i++]);
	ft_printf("\n");

	bubble_sort(arr);

	ft_printf("Sorted:		");
	while (j < 6)
		ft_printf("%i ", arr[j++]);
	ft_printf("\n");
}
