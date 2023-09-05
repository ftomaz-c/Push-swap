/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:54:53 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:09:59 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  calloc()  function allocates memory for an array of nmemb elements	*/
/* of size bytes each and returns a pointer to the allocated memory.		*/
/* The memory is set to zero. If nmemb or size is 0, then calloc() returns	*/
/* either NULL, or a unique pointer value that can later be successfully	*/
/* passed to free(). If the multiplication of nmemb and size would result in*/
/* integer overflow, then calloc() returns an error.						*/
/*The  calloc() function return a pointer to the allocated memory, which is	*/
/* suitably aligned for any built-in type. On error, this function returns	*/
/* NULL. NULL may also be returned by a successful call to calloc() with	*/
/* nmemb or size equal to zero.												*/

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
