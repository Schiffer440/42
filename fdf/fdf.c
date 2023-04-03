/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:01:36 by adugain           #+#    #+#             */
/*   Updated: 2023/04/03 10:46:05 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef	struct s_matrix
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_coord	*coord;
	char	*str;
	int	m_x;
	int	m_y;
	int	**tab;

}	t_matrix;

void    free_matrix(int **tab, t_matrix *matrix)
{
    int    i;

    i = 0;
    while (i < matrix->m_y)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int	handle_keypress(int keysym, t_matrix *matrix)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(matrix->mlx_ptr, matrix->win_ptr);
	return (0);
}

bool	parse_digit(char *map, int *i)
{
	if (!*i || (map[*i - 1] == ' ' || map[*i - 1] == '-'))
		++*i;
	else
		return (false);
	while (map[*i] && ft_isdigit(map[*i]))
		++*i;
	return (true);
}

int	parse_map(char *map)
{
	int	i;
	int	x_nb;
	
	i = 0;
	x_nb = 0;
	while (map[i] && map[i] != '\n')
	{
		if (ft_isdigit(map[i]))
		{
			if (parse_digit(map, &i) == false)
				return (0);
			x_nb++;
		}
		else if (map[i] == '-' && map[i + 1] && ft_isdigit(map[i + 1]))
			i++;
		else if (map[i] == ' ')
			i++;
		else
			return (0);
	}
	return (x_nb);
}

void	read_map(t_matrix *matrix, char *map)
{
	int	fd;
	int	word;
	char	*line;
	bool	first_line;
	
	word = 0;
	fd = open(map, O_RDONLY);
	first_line = true;
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("line:%s", line);
		if (first_line == true)
		{
			matrix->str = ft_strdup(line);
			matrix->m_x = parse_map(line);
		}
		else if (matrix->m_x != parse_map(line))
			return ;
		if (first_line == false)
			matrix->str = ft_strjoin_gnl(matrix->str, line);
		matrix->m_y++;
		first_line = false;
		free(line);
	}
	close(fd);
}

bool	init(t_matrix *matrix)
{
	matrix->mlx_ptr = mlx_init();
	if (matrix->mlx_ptr == NULL)
		return(false);
	matrix->win_ptr = mlx_new_window(matrix->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (matrix->win_ptr == NULL)
		return (false);
	ft_printf("-------------\n");
	matrix->str = NULL;
	matrix->m_x = 0; 
	matrix->m_y = 0;
	return (true);
}

void	fill_tab(t_matrix *matrix)
{
	int	i;

	i = 0;
	matrix->tab = malloc(sizeof(int *) * matrix->m_y);
	while (i < matrix->m_y)
	{
		matrix->tab[i]= malloc(sizeof(int) * matrix->m_x);
		i++;
	}
	
	free(matrix->str);
}

void	fdf(t_matrix *matrix)
{
	fill_tab(matrix);
}

int	main(int ac, char **av)
{
	t_matrix	matrix;
	
	if (ac != 2)
		return (0);
	if (init(&matrix) == false)
		return (0);
	ft_printf("-------------\n");
	read_map(&matrix, av[1]);
	fdf(&matrix);
	ft_printf("x:%d\ny:%d\n%s", matrix.m_x, matrix.m_y, matrix.str);
	mlx_loop_hook(matrix.mlx_ptr, &handle_keypress, &matrix);
	mlx_hook(matrix.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &matrix);
	mlx_loop(matrix.mlx_ptr);
	mlx_destroy_display(matrix.mlx_ptr);
	free(matrix.mlx_ptr);
	free_matrix(matrix.tab, &matrix);
	return (0);
}
