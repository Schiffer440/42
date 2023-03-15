/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:18:43 by adugain           #+#    #+#             */
/*   Updated: 2023/03/15 13:10:09 by adugain          ###   ########.fr       */
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

void    free_matrix(int **tab, t_matrix *matrix)
{
    int    i;

    i = 0;
    while (i < matrix->y)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	print_matrix(t_matrix *matrix)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < matrix->y)
	{
		j = 0;
		while(j < matrix->x)
		{
			ft_printf("%d", matrix->tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	fill_matrix(t_matrix *matrix, char *map)
{
	int	i;
	int	j;
	char	*line;
	char	**data;
	
	i = 0;
	matrix->fd = open(map, O_RDONLY);
	line = get_next_line(matrix->fd);
	data = ft_split(line, ' ');
	while (i < matrix->y)
	{
		j = 0;
		while (j < matrix->x)
		{
			matrix->tab[i][j] = ft_atoi((char *)data[j]);
			j++;
		}
		free(line);
		free_tab(data);
		line = get_next_line(matrix->fd);
		data = ft_split(line, ' ');
		i++;
	}
}

void	get_wrecked(char *str)
{
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	else
		return ;
}

void	get_matrix_base(t_matrix *matrix, char *map)
{
	char	*line;
	
	matrix->fd = open(map, O_RDONLY);
	line = get_next_line(matrix->fd);
	get_wrecked(line);
	matrix->x = wordcount(line, ' ');
	free(line);
	while (line != NULL)
	{
		line = get_next_line(matrix->fd);
		free(line);
		matrix->y++;
	}
	close(matrix->fd);
}

void	create_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	matrix->tab = malloc(sizeof(int*) * matrix->y);
	while (i < matrix->y)
	{
		matrix->tab[i] = malloc(sizeof(int) * matrix->x);
		i++;
	}
}

int	check_matrix(t_matrix *matrix)
{
	int	i;
	int	j;
	int	elem;
	
	i = 0;
	j = 0;
	elem = 0;
	while (i < matrix->y)
	{
		while (matrix->tab[i])
			j++;
		while (matrix->tab[i - 1])
			elem++;
		if (i != 0 && j != elem)
			return (0);
		else
			i++;
	}
	return (1);
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
	print_matrix(&matrix);
	if (check_matrix(&matrix) == 0)
		return (free_matrix(matrix.tab, &matrix), 0);
	free_matrix(matrix.tab, &matrix);
	ft_printf("y:%d\nx:%d", matrix.y, matrix.x);
}