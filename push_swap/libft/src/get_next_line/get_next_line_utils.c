/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:03:31 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:09:35 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int	found_newline(char *stash)
{
	int	i;

	i = 0;
	if (stash == NULL)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*temp;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	temp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!temp)
// 	{
// 		free(temp);
// 		free(s1);
// 		return (NULL);
// 	}
// 	while (s1 != NULL && s1[i] != '\0')
// 	{
// 		temp[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 		temp[i++] = s2[j++];
// 	temp[i] = '\0';
// 	if (s1)
// 		free(s1);
// 	return (temp);
// }

// int	ft_strlen(char *str)
// {
// 	size_t	count;
// 	size_t	i;

// 	i = 0;
// 	count = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 	{
// 		count++;
// 		i++;
// 	}
// 	return (count);
// }
