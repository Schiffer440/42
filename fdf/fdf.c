/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:01:36 by adugain           #+#    #+#             */
/*   Updated: 2023/03/29 15:28:11 by adugain          ###   ########.fr       */
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
	t_coord	*coord;
	char	*str;
	int	m_x;
	int	m_y;
	int	**tab;
	
}	t_matrix;

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
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
			matrix->str = ft_strjoin(matrix->str, line);
		matrix->m_y++;
		first_line = false;
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_matrix	matrix;
	
	if (ac == 2)
		read_map(&matrix, av[1]);
	else
		return (0);
	ft_printf("x:%d\ny:%d\n%s", matrix.m_x, matrix.m_y, matrix.str);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return(MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first wind");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx_ptr, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
