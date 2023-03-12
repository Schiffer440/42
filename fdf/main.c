/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:25:48 by adugain           #+#    #+#             */
/*   Updated: 2023/03/12 16:49:56 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 500
#define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void 	*win2_ptr;
}	t_data;

void	draw_line(t_data *data)
{
	int	i;
	int	x;
	int	y;
	
	i = 0;
	x = 600/2;
	y = 500/2;
	while (i < 100)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
		i++;
		x++;
	}
}
int	handle_no_event(void *data)
{
	return(0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (keysym == XK_E)
		mlx_destroy_window(data->mlx_ptr, data->win2_ptr);
	if (keysym == XK_l)
		draw_line(data);
	return (0);
}


int main(void)
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
	data.win2_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "the second");
	if (data.win2_ptr == NULL)
	{
		free(data.win2_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
