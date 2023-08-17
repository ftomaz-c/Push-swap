/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:41:59 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/07/17 23:06:56 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_stash(&stash, fd);
	if (!stash)
		return (NULL);
	extract_line(stash, &line);
	if (line[0] == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	clean_stash(&stash);
	return (line);
}

void	read_and_stash(char **stash, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	bytes_read = 1;
	while (bytes_read != 0 && !found_newline(*stash))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(*stash);
			*stash = NULL;
			return ;
		}
		buffer[bytes_read] = '\0';
		*stash = ft_strjoin(*stash, buffer);
	}
	free(buffer);
}

void	extract_line(char *stash, char **line)
{
	size_t	len;
	size_t	new_line;
	size_t	i;

	len = ft_strlen(stash);
	*line = malloc(sizeof(char) * (len + 1));
	if (!(*line))
	{
		free(*line);
		*line = NULL;
		return ;
	}
	new_line = 0;
	while (stash[new_line] != '\n' && stash[new_line] != '\0')
		new_line++;
	if (stash[new_line] == '\n')
		new_line++;
	i = 0;
	while (i < new_line)
	{
		(*line)[i] = stash[i];
		i++;
	}
	(*line)[i] = '\0';
}

void	clean_stash(char **stash)
{
	size_t	new_line;
	char	*temp;
	size_t	len;
	int		i;

	new_line = 0;
	while ((*stash)[new_line] != '\n' && (*stash)[new_line] != '\0')
		++new_line;
	if ((*stash)[new_line] == '\n')
		new_line++;
	len = ft_strlen(*stash) - new_line;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp || len == 0)
	{
		free(temp);
		free(*stash);
		*stash = NULL;
		return ;
	}
	i = 0;
	while ((*stash)[new_line] != '\0')
		temp[i++] = (*stash)[new_line++];
	temp[i] = '\0';
	free(*stash);
	*stash = temp;
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("hp1.txt", O_RDWR);
	while (line = get_next_line(fd))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
