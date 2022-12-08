/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:42:17 by adugain           #+#    #+#             */
/*   Updated: 2022/12/08 17:29:34 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char 	*check_return(char *str)
{
	int	i;
	char 	*n_str;
	
	while (str[i])
	{
		if (str[i] == '\n')
		{
			n_str = malloc(sizeof(char *) * i + 1);
			break ;
		}
		i++;
	}
	n_str[i + 1] = '\0';
	return (n_str);

}
char	*get_next_line(int fd)
{
	static char	*stash;
	char	*buf;
	char	*line;
	
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{
		read(fd, buf, BUFFER_SIZE);
		if (read(fd, buf, BUFFER_SIZE) == -1)
			return(NULL);
		stash = ft_strjoin(stash, buf);
	}
	line = check_return(stash);
	return (line);
}

int main ()
{
	printf("%s", get_next_line(1));
	return (0);
}