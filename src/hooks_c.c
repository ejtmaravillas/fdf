/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:38:52 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 14:39:49 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_values(t_map_data *data)
{
	if (data->projection == 1)
	{
		data->theta_x = 0.174533;
		data->theta_y = 3.14159;
		data->theta_z = 1.5708;
	}
	reset_values_extn(data);
	hook_setdefault(data);
	data->grid_scale = data->initgrid_scale;
	data->x_offset = data->initx_offset;
	data->y_offset = data->inity_offset;
	data->z_factor = 1;
	find_maxmin(data, 1);
	find_maxmin(data, 0);
}

void	reset_values_extn(t_map_data *data)
{
	if (data->projection == 2)
	{
		data->theta_x = -0.785398;
		data->theta_y = 0.785398;
		data->theta_z = 0;
	}
	if (data->projection == 3)
	{
		data->theta_x = 0;
		data->theta_y = 0;
		data->theta_z = 0;
	}
	if (data->projection == 4)
	{
		data->theta_x = -1.5708;
		data->theta_y = 0;
		data->theta_z = 0;
	}
	if (data->projection == 5)
	{
		data->theta_x = -1.5708;
		data->theta_y = -1.5708;
		data->theta_z = 0;
	}
}

void	clean_img(t_map_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= round(data->max_x + data->x_offset))
	{
		j = -1;
		while (++j <= round(data->max_y + data->y_offset))
			img_mlx_pixel_put(data, i, j, 0x00000000);
	}
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void	handle_rotation(int keysym, t_map_data *data)
{
	if (keysym == 32)
		data->theta_x += 0.05;
	else if (keysym == 38)
		data->theta_x -= 0.05;
	else if (keysym == 34)
		data->theta_y += 0.05;
	else if (keysym == 40)
		data->theta_y -= 0.05;
	else if (keysym == 31)
		data->theta_z += 0.05;
	else if (keysym == 37)
		data->theta_z -= 0.05;
	find_maxmin(data, 1);
}

void	handle_offset(int keysym, t_map_data *data)
{
	if (keysym == 2)
		data->x_offset += 5;
	else if (keysym == 0)
		data->x_offset -= 5;
	else if (keysym == 1)
		data->y_offset += 5;
	else if (keysym == 13)
		data->y_offset -= 5;
	find_maxmin(data, 1);
}
