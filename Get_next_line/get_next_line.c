/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:42:17 by adugain           #+#    #+#             */
/*   Updated: 2022/12/12 17:15:14 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*clean_buf(char *buf)
{
	int	i;
	int	j;
	char	*n_buf;

	i = 0;
	j = 0;
	n_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (buf[i] != '\n')
		i++;
	while (j < i)
	{
		n_buf[j] = buf[j];
		j++;
	}
	return (n_buf);
}
char	*read_and_stash(int fd, char *buf, char *stash)
{
	int	readed;

	readed = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	while (!ft_strchr(buf, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		printf("buf = %s\n", buf);
		stash = ft_strjoin(stash, buf);
		printf("stash = %s\n", stash);
	}
	buf = clean_buf(buf);
	printf("new buf=%s\n", buf);
	return (stash);
}

char	*write_line(char *line, char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	printf("stash = %s\n", stash);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free(stash), NULL);
	printf("Malloc line OK\n");
	while (++j < i)
		line[j] = stash[j];
	line[j] = '\0';
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	char 	*stash;
	static char	*buf;
	char	*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	//1.read file and put his content into stash
	stash = read_and_stash(fd, buf, stash);
	printf("stash 1.0 =%s\n", stash);
	//2.isolate the line and write it
	line = write_line(line, stash);
	printf("stash 2.0 =%s\n", stash);
	printf("line =%s\n", line);
	//3.clean and create the new static
	//clean_stash(stash);
	return (line);
}

int main ()
{
	int fd;
	
	fd = open("qwerty.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}