/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:28:56 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/05 13:30:44 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*read_fd(int fd, char *buffer)
{
	char	*line;
	int		readed;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{	
		readed = read(fd, line, BUFFER_SIZE);
		if (readed == -1)
		{
			free(line);
			return (NULL);
		}
		line[readed] = '\0';
		buffer = ft_free(buffer, line);
		if (is_endline(line))
			break ;
	}
	free(line);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = malloc((i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i])
		line[i++] = '\n' ;
	line[i] = '\0';
	return (line);
}

char	*nextline(char *buffer, int k)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = malloc((ft_strlen(buffer) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[k++] = buffer[i++];
	line[k] = '\0';
	free (buffer);
	return (line);
}

int	is_endline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = nextline(buffer, 0);
	return (line);
}
/*
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	char *line;
	int fd = open("txt.txt", O_RDONLY);
	if (fd < 0)
		return 1;
	line  = get_next_line(fd);
	while (line) {
		printf("%s", line);
		free(line);
		line  = get_next_line(fd);
	}
	free (line);
	return 0;
}*/
