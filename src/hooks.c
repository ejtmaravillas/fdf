/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:00:06 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/08 17:57:06 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_map_data *data)
{
	clean_img(data);
	printf("keysym: %d\n", keysym);
	if (keysym == 32 || keysym == 38 || keysym == 34 \
	|| keysym == 40 || keysym == 31 || keysym == 37)
		handle_rotation(keysym, data);
	else if (keysym == 0 || keysym == 2 \
	|| keysym == 13 || keysym == 1)
		handle_offset(keysym, data);
	map_draw(data);
	printf("theta_x: %f theta_y: %f theta_y: %f\n", data->theta_x, data->theta_y, data->theta_z);
	printf("max_x: %f max_y: %f\n", data->max_x, data->max_y);
	return (0);
}

void	clean_img(t_map_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= round(data->max_x))
	{
		j = -1;
		while (++j <= round(data->max_y))
			img_mlx_pixel_put(data, i, j, 0x00000000);
		// printf("i: %d j: %d\n", i, j);
	}
	printf("max_x: %f max_y: %f\n", data->max_x, data->max_y);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void	handle_rotation(int keysym, t_map_data *data)
{
	if (keysym == 32)
		data->theta_x += 0.03;
	else if (keysym == 38)
		data->theta_x -= 0.03;
	else if (keysym == 34)
		data->theta_y += 0.03;
	else if (keysym == 40)
		data->theta_y -= 0.03;
	else if (keysym == 31)
		data->theta_z += 0.03;
	else if (keysym == 37)
		data->theta_z -= 0.03;
}

void	handle_offset(int keysym, t_map_data *data)
{
	if (keysym == 2)
		data->x_offset += 10;
	else if (keysym == 0)
		data->x_offset -= 10;
	else if (keysym == 1)
		data->y_offset += 10;
	else if (keysym == 13)
		data->y_offset -= 10;
}

// w = 13
// a = 0
// s = 1
// d = 2

// u = 32
// j = 38
// i = 34
// k = 40
// o = 31
// l = 37