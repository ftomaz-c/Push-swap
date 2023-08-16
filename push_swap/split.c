/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:45:29 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/16 15:20:54 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_isspace(char c) {

	if (c == ' ' || c == '\t' || c == '\n'
	|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

size_t	count_words(char *str) {

	size_t	count;
	int		word;

	count = 0;
	word = 0;
	while(*str) {
		if (!ft_isspace(*str)) {
			word = 1;
			while (!ft_isspace(*str) && *str)
				str++;
			if (word) {
				word = 0;
				count++;
			}
		}
		else
			str++;
	}
	return (count);
}

void	free_nodes(t_list **stash, int len) {

	int	i;

	i = 0;
	while (i < len) {
		free(stash[i]->content);
		free(stash[i]);
		i++;
	}
}

void	alloc_and_stash(t_list **stash, char *str, int begin, int end, int index) {

	size_t	i;

	stash[index] = malloc (sizeof(t_list));
	if (!stash[index]) {
		free_nodes(stash, index);
		return ;
	}
	stash[index]->content = malloc(sizeof(char) * end - begin + 1);
	if (!stash[index]->content) {
		free_nodes(stash, index);
		return ;
	}
	i = 0;
	while (begin < end)
		stash[index]->content[i++] = str[begin++];
	stash[index]->content[i] = '\0';
}

t_list	**split(char *str) {

	t_list	**stash;
	size_t	index;
	size_t	j;
	size_t	i;

	stash = malloc(sizeof(t_list) * count_words(str));
	if (!stash)
		return NULL;
	i = 0;
	index = 0;
	while(str[i] != '\0') {
		if (!ft_isspace(str[i])) {
			j = i;
			while (!ft_isspace(str[i]) && str[i] != '\0')
				i++;
			alloc_and_stash(stash, str, j, i, index);
			index++;
			}
		else
			i++;
	}
	return (stash);
}

// int	main(int argc, char **argv) {

// 	if (argc == 2) {
// 		int	words = count_words(argv[1]);
// 		t_list **argl = split(argv[1]);
// 		int	i = 0;
// 		while (i < words) {
// 			ft_printf("%s\n", argl[i++]->content);
// 		}
// 		free_nodes(argl, words);
// 		free(argl);
// 	}
// 	else
// 		ft_printf("\n");
// }
