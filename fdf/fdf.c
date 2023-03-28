/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:01:36 by adugain           #+#    #+#             */
/*   Updated: 2023/03/28 12:03:41 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef	struct s_matrix
{
	int	fd;
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

int	main(int ac, char **av)
{
	t_data	data;

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
}
