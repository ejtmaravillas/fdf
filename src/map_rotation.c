/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:43:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/07 17:43:11 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	rotation_x(t_map_point a, t_map_data *data)
{
	float	temp_z;
	float	temp_y;

	temp_z = a.z;
	temp_y = a.y;
	a.y = (temp_y * cos(data->theta_x) + temp_z * \
	sin(data->theta_x));
	a.z = (-temp_y * sin(data->theta_x) + temp_z * \
	cos(data->theta_x));
	return (a);
}

t_map_point	rotation_y(t_map_point a, t_map_data *data)
{
	float	temp_x;
	float	temp_z;

	temp_x = a.x;
	temp_z = a.z;
	a.x = (temp_x * cos(data->theta_y) + temp_z * \
	sin(data->theta_y));
	a.z = (-temp_x * sin(data->theta_y) + temp_z * \
	cos(data->theta_y));
	return (a);
}

t_map_point	rotation_z(t_map_point a, t_map_data *data)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = (temp_x * cos(data->theta_z) - temp_y * \
	sin(data->theta_z));
	a.y = (temp_x * sin(data->theta_z) + temp_y * \
	cos(data->theta_z));
	return (a);
}

t_map_point	get_rotationpoints(t_map_point a, t_map_data *data)
{
	a = rotation_x(a, data);
	a = rotation_y(a, data);
	a = rotation_z(a, data);
	if (data->projection == 1)
		a = get_isometricpoints(a);
	a.x *= data->grid_scale;
	a.y *= data->grid_scale;
	a.z *= data->grid_scale;
	if (a.x < data->min_x)
		data->min_x = a.x;
	if (a.x > data->max_x)
		data->max_x = a.x;
	if (a.y < data->min_y)
		data->min_y = a.y;
	if (a.y > data->max_y)
		data->max_y = a.y;
	if (a.z < data->min_z)
		data->min_z = a.z;
	if (a.z > data->max_z)
		data->max_z = a.z;
	return (a);
}

t_map_point	get_isometricpoints(t_map_point a)
{
	float	temp_x;
	float	temp_y;
	float	temp_z;

	temp_x = a.x;
	temp_y = a.y;
	temp_z = a.z;
	a.x = ((sqrt(3) / 2) * (temp_x - temp_y));
	a.y = (2 * temp_z - temp_x - temp_y) / 2;
	a.z = - (temp_x + temp_y + temp_z) / (2 * sqrt(2));
	return (a);
}
