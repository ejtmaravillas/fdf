/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:31:20 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 14:45:38 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_projection(int keysym, t_map_data *data)
{
	if (keysym == ISO_COMMAND)
	{
		data->projection = 1;
		data->theta_x = 0.174533;
		data->theta_y = 3.14159;
		data->theta_z = 1.5708;
	}
	else if (keysym == PAR_COMMAND)
	{
		data->projection = 2;
		data->theta_x = -0.785398;
		data->theta_y = 0.785398;
		data->theta_z = 0;
	}
	handle_projection_extn(keysym, data);
	find_maxmin(data, 1);
	find_maxmin(data, 0);
	set_screen(data);
}

void	handle_projection_extn(int keysym, t_map_data *data)
{
	if (keysym == TOP_COMMAND)
	{
		data->projection = 3;
		data->theta_x = 0;
		data->theta_y = 0;
		data->theta_z = 0;
	}
	else if (keysym == FRN_COMMAND)
	{
		data->projection = 4;
		data->theta_x = -1.5708;
		data->theta_y = 0;
		data->theta_z = 0;
	}
	else if (keysym == SID_COMMAND)
	{
		data->projection = 5;
		data->theta_x = -1.5708;
		data->theta_y = -1.5708;
		data->theta_z = 0;
	}
}

void	find_maxmin_s0(t_map_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->col)
	{
		if (data->point_map[y][x].z * data->z_factor > data->max_z_raw)
			data->max_z_raw = data->point_map[y][x].z * data->z_factor;
		if (data->point_map[y][x].z * data->z_factor < data->min_z_raw)
			data->min_z_raw = data->point_map[y][x].z * data->z_factor;
		x++;
	}
}

void	find_maxmin_s1(t_map_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->col)
	{
		get_rotationpoints(data->point_map[y][x], data);
		x++;
	}
}

void	find_maxmin(t_map_data *data, int set)
{
	int	y;

	y = 0;
	while (y < data->row && set == 0)
	{
		find_maxmin_s0(data, y);
		y++;
	}
	while (y < data->row && set == 1)
	{
		find_maxmin_s1(data, y);
		y++;
	}
}
