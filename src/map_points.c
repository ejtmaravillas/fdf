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
	data->color_point = malloc(sizeof(t_color_point *) * data->row);
	y = 0;
	while (y < data->row)
	{
		x = 0;
		data->point_map[y] = malloc(sizeof(t_map_point) * data->col);
		data->color_point[y] = malloc(sizeof(t_color_point) * data->col);
		while (x < data->col)
		{
			data->point_map[y][x] = set_coordinate(x, y, data->data_map[y][x]);
			data->color_point[y][x] = set_color(data->color_map[y][x]);
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
