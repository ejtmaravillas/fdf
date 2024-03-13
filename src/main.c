/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:30:42 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/13 21:02:13 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	static t_map_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	map_data(&data, argc, argv);
	find_maxmin(&data, 0);
	data.name = argv[1];
	if (data.mlx_win)
		mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	if (data.img)
		mlx_destroy_image(data.mlx_ptr, data.img);
	data.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, \
		&data.bits_per_pixel, &data.line_length, &data.endian);
	data.mlx_win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF - EMARAVIL");
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	// mlx_hook(data.mlx_win, 2, 1L << 9, handle_keypress, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
	// data.initx_offset = data.x_offset;
	// data.inity_offset = data.y_offset;
	map_draw(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

void	img_mlx_pixel_put(t_map_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || y < 0 || x > WINDOW_WIDTH || y > WINDOW_HEIGHT))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_close(t_map_data *data)
{
	free(data->mlx_ptr);
	free_matrixdata(data);
	exit(0);
	return (0);
}
