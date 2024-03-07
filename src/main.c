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
	t_map_data	data;
	int			index;
	// int			row;
	// int			col;

	map_data(&data, argc, argv);
    // printf("max_x: %f\n", data.max_x);
    // printf("min_x: %f\n", data.min_x);
    // printf("max_y: %f\n", data.max_y);
    // printf("min_y: %f\n", data.min_y);
	// row = data.row;
	// col = data.col;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF - EMARAVIL");
	data.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
			&data.endian);
	// img_mlx_pixel_put(&img, 5, 5, 0xFF0000);
	index = 0;
	// while (index < 100)
	// {
	// 	img_mlx_pixel_put(&data, 700.95 + index, 250.01 + index, 0xFFFF0000);
	// 	index++;
	// }
	// index = 0;
	// while (index < 100)
	// {
	// 	img_mlx_pixel_put(&img, 500, (HEIGHT * 0.50) + index, 0xFF0000FF);
	// 	index++;
	// }
	// index = 0;
	// while (index < 100)
	// {
	// 	img_mlx_pixel_put(&img, 500 + index, (HEIGHT * 0.50 + 100), 0xFF00FF00);
	// 	index++;
	// }
	// index = 0;
	// while (index < 100)
	// {
	// 	img_mlx_pixel_put(&img, (500 + 100), HEIGHT * 0.50 + index, 0xFF00FF00);
	// 	index++;
	// }
	// for (int y = HEIGHT * 0.1; y < HEIGHT * 0.9; ++y)
	// {
	// 	for (int x = WIDTH * 0.1; x < WIDTH * 0.9; ++x)
	// 	{
	// 		img_mlx_pixel_put(&img,
	// 			x,
	// 			y,
	// 			rand() % 0xffffff);
	// 	}
	// }
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	// mlx_string_put(data.mlx_ptr, data.mlx_win, 100, 20, 0x00FF0000, "FDF");
	// mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, data);
	// mlx_hook(data.mlx_win, 17, 0, ft_close, data);
	// mlx_hook(data.mlx_win, 4, 1L << 2, mouse_hook, data);
	map_draw(&data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
	free_matrixdata(&data);
	return (0);
}

void	img_mlx_pixel_put(t_map_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
