/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:58:41 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/28 16:14:10 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

char	*args_to_str(int argc, char **argv)
{
	char	*str;
	char	*tmp;
	char	*space;
	int		i;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		if (str == NULL)
			str = ft_strdup(argv[i]);
		else
		{
			space = " ";
			tmp = ft_strjoin(str, space);
			free(str);
			str = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
		i++;
	}
	return (str);
}

int	count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	**argv_split(int argc, char **argv)
{
	char	*str;

	str = args_to_str(argc, argv);
	argv = ft_split(str, " ");
	free(str);
	return(argv);
}
