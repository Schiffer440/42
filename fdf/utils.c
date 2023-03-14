/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:18:43 by adugain           #+#    #+#             */
/*   Updated: 2023/03/14 09:56:13 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef	struct s_matrix
{
	int	fd;
	int	x;
	int	y;
	int	**tab;
	
}	t_matrix;

void	get_matrix_base(t_matrix *matrix, char *map)
{
	char	*line;
	
	matrix->fd = open(map, O_RDONLY);
	line = get_next_line(matrix->fd);
	matrix->x = wordcount(line, ' ') - 1;
	//free(line);
	while (line != NULL)
	{
		ft_printf("%s", line);
		line = get_next_line(matrix->fd);
		matrix->y++;
		//free(line);
	}
	close(matrix->fd);
}

void	create_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	matrix->tab = malloc(sizeof(int *)* matrix->y);
	while(i < matrix->y)
	{
		matrix->tab[i] = malloc(sizeof(int) * matrix->x);
		i++;
	}
}

void	fill_matrix(t_matrix *matrix, char *map)
{
	char *line;
	char **data;

}

int	main(int ac, char **av)
{
	t_matrix	matrix;
	
	matrix.x = 0;
	matrix.y = 0;
	if (ac == 2)
		get_matrix_base(&matrix, av[1]);
	else
		return(0);
	create_matrix(&matrix);
	fill_matrix(&matrix, av[1]);
	ft_printf("y:%d\nx:%d", matrix.y, matrix.x);
}