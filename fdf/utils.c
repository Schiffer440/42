/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:18:43 by adugain           #+#    #+#             */
/*   Updated: 2023/03/20 16:08:35 by adugain          ###   ########.fr       */
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
	if (str[strlen(str) - 1] == '\n' && str)
		str[strlen(str) - 1] = '\0';
	else
		return ;
}

int	get_matrix_base(t_matrix *matrix, char *map)
{
	char	*line;
	
	matrix->fd = open(map, O_RDONLY);
	line = get_next_line(matrix->fd);
	get_wrecked(line);
	matrix->x = wordcount(line, ' ');
	matrix->y += 1;
	free(line);
	while (line)
	{
		line = get_next_line(matrix->fd);
		ft_printf("line:%s", line);
		if (line != NULL)
			get_wrecked(line);
		if (line != NULL && matrix->x == wordcount(line, ' '))
		{
			ft_printf("line check:%d\nx:%d\n\n", wordcount(line, ' '), matrix->x);
			free(line);
			matrix->y++;
		}
		else
		{
			close(matrix->fd);
			return(0);
		}
	}
	close(matrix->fd);
	return (1);
}

void	create_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	matrix->tab = malloc(sizeof(int*) * matrix->y);
	while (i < matrix->y)
	{
		ft_printf("creating...\n");
		matrix->tab[i] = malloc(sizeof(int) * matrix->x);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_matrix	matrix;
	
	matrix.x = 0;
	matrix.y = 0;
	if (ac == 2)
	{	
		if (get_matrix_base(&matrix, av[1]) == 0)
			return (0);
	}
	else
		return(0);
	create_matrix(&matrix);
	fill_matrix(&matrix, av[1]);
	print_matrix(&matrix);
	free_matrix(matrix.tab, &matrix);
	ft_printf("y:%d\nx:%d", matrix.y, matrix.x);
}