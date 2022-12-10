/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:42:17 by adugain           #+#    #+#             */
/*   Updated: 2022/12/10 15:59:50 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

void	read_and_stash(int fd, char *buf, char *stash)
{
	int	readed;
	
	stash = NULL;
	readed = 1;
	buf = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (readed != -1)
	{
		
		readed = read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
}

void	write_line(char *line, char *stash)
{
	int	i;
	int	len;
	
	i = 0;
	len = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			i++;
			len++;
			break ;
		}
		i++;
		len++;
	}
	line = malloc(sizeof(char *) * len + 1);
	i = 0;
	while (i < len)
		line[i++] = stash[i++];
	line[i] = '\0';
}

void	clean_stash(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\n')
	{
		if (stash[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	
}

char	*get_next_line(int fd)
{
	static char 	*stash;
	char	*buf;
	char	*line;
	
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	//1.read file and put his content into stash
	read_and_stash(fd, buf, stash);
	//2.isolate the line and write it
	write_line(line, stash);
	//3.return the written line and clean the stash
	clean_stash(stash);
	return (line);
}

int main ()
{
	int fd;
	
	fd = open("qwerty.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}