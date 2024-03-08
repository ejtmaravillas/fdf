/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:14:29 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/07 13:14:29 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_points(t_map_data *data)
{
	int	x;
	int	y;

	data->point_map = malloc(sizeof(t_map_point *) * data->row);
	y = 0;
	while (y < data->row)
	{
		x = 0;
		data->point_map[y] = malloc(sizeof(t_map_point) * data->col);
		while (x < data->col)
		{
			data->point_map[y][x] = set_coordinate(x, y, data->data_map[y][x]);
			get_rotationpoints(data->point_map[y][x], data);
			x++;
		}
		y++;
	}
}

t_map_point	set_coordinate(float x, float y, float z)
{
	t_map_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_map_point	get_rotationpoints(t_map_point a, t_map_data *data)
{
	a = rotation_x(a, data);
	a = rotation_y(a, data);
	a = rotation_z(a, data);
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
	if (a.z > data->max_y)
		data->max_z = a.z;
	if (fabs(data->min_z) > data->max_z)
		data->max_z = fabs(data->min_z);
	// printf("a.x: %f a.y: %f a.z: %f\n", a.x, a.y, a.z);
	// printf("MP max_x: %f max_y: %f\n", data->max_x, data->max_y);
	return (a);
}
