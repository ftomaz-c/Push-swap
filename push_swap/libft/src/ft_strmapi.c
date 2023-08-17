/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:36:25 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 14:47:58 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applies the function ’f’ to each character of the string ’s’, and passing	*/
/*its index as first argument to create a new string (with malloc(3))		*/
/*resulting from successive applications of ’f’. Returns the string created	*/
/*from the successive applications of ’f’or NULL if the allocation fails.	*/
/*s: The string on which to iterate.										*/
/*f: The function to apply to each character.								*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	size_t			s_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	new_s = ft_calloc(s_len + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
