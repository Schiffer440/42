/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:18:43 by adugain           #+#    #+#             */
/*   Updated: 2023/03/13 16:55:45 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef	struct s_matrix
{
	int	x;
	int	y;
	char	**tab;
}	t_matrix;

void	get_matrix_base(int fd, t_matrix *matrix)
{
	char	*line;
	
	line = get_next_line(fd);
	matrix->x = wordcount(line, ' ') - 1;
	while (line != NULL)
	{
		ft_printf("%s", line);
		line = get_next_line(fd);
		matrix->y++;
	}
	
}

void	create_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	matrix->tab = malloc(sizeof(char *)* matrix->y);
	while(i < matrix->y)
	{
		matrix->tab[i] = malloc(sizeof(char) * matrix->x);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_matrix	matrix;
	int	fd;
	
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return(0);
	get_matrix_base(fd, &matrix);
	create_matrix(&matrix);
	ft_printf("y:%d\nx:%d", matrix.y, matrix.x);
}