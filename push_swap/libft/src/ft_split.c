/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:11:11 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/17 19:08:00 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns an array of strings obtained by	*/
/* splitting ’s’ using the character ’c’ as a delimiter. The array must end	*/
/* with a NULL pointer. Returns the array of new strings resulting from the	*/
/* split or NULL if the allocation fails.									*/
/*s: The string to be split.												*/
/*c: The delimiter character.												*/

#include "libft.h"

size_t	count_words(char const *str, char c) {

	size_t	count;
	int		word;

	count = 0;
	word = 0;
	while(*str) {
		if (*str != c && word == 0) {
			word = 1;
			count++;
		}
		else if (*str == c)
			word = 0;
		str++;
	}
	return (count);
}

void	free_stash(char **stash, int len) {

	int	i;

	i = 0;
	while (i < len) {
		free(stash[i]);
		i++;
	}
}

void	alloc_and_stash(char **stash, char const *str, int begin, int end, int index) {

	size_t	i;

	stash[index] = ft_calloc(sizeof(char), end - begin + 1);
	if (!stash[index]) {
		free_stash(stash, index);
		return ;
	}
	i = 0;
	while (begin < end)
		stash[index][i++] = str[begin++];
	stash[index][i] = '\0';
}

char	**ft_split(char const *str, char c) {

	char	**stash;
	size_t	index;
	size_t	j;
	size_t	i;

	stash = ft_calloc(sizeof(char *), count_words(str, c) + 1);
	if (!stash)
		return NULL;
	i = 0;
	index = 1;
	while(str[i] != '\0') {
		if (str[i] != c) {
			j = i;
			while (str[i] != c && str[i] != '\0')
				i++;
			alloc_and_stash(stash, str, j, i, index);
			index++;
			}
		else
			i++;
	}
	return (stash);
}
