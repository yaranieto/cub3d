/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:25:08 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/07/03 18:36:05 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	char	*nl;
	size_t	len;

	if (!*stash || !**stash)
		return (NULL);
	nl = ft_strchr(*stash, '\n');
	if (nl)
	{
		len = nl - *stash + 1;
		line = ft_substr(*stash, 0, len);
		new_stash = ft_substr(*stash, len, ft_strlen(*stash) - len);
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		line = *stash;
		*stash = NULL;
	}
	return (line);
}

static int	read_and_fill_stash(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes;
	char	*tmp;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		tmp = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = tmp;
		if (ft_strchr(*stash, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*result;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	bytes = read_and_fill_stash(fd, &stash);
	if (bytes < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	result = ft_extract_line(&stash);
	if (!result && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (result);
}

/*cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c*/
/*#include <fcntl.h>    // open
#include <unistd.h>   // close
#include <stdio.h>    // printf
#include <stdlib.h>   // free
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("*.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
