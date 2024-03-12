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

t_color_point set_color(char *str)
{
	t_color_point color_point;

	color_point.r = 0;
	color_point.g = 0;
	color_point.b = 0;
	color_point.t = 0;
	if (str != NULL && ft_strlen(str) == 8)
		color_point = hex_to_dec_8(str);
	else if (str != NULL && ft_strlen(str) == 10)
		color_point = hex_to_dec_10(str);
	else if (str == NULL)
	{
		color_point.r = 255;
		color_point.g = 255;
		color_point.b = 255;
		color_point.t = 255;
	}
	return (color_point);
}

t_color_point	hex_to_dec_8(char *str)
{
	int x;
	t_color_point color_point;

	x = 2;
	color_point.r = 0;
	color_point.g = 0;
	color_point.b = 0;
	color_point.t = 255;
	while (str[x] != '\0' && ft_strlen(str) == 8)
	{
		if (x == 2 || x == 3)
		{
			color_point.r += (hex_conv(str[x]) * pow(16, 3 - x));
		}
		else if (x == 4 || x == 5)
			color_point.g += (hex_conv(str[x]) * pow(16, 5 - x));
		else if (x == 6 || x == 7)
			color_point.b += (hex_conv(str[x]) * pow(16, 7 - x));
		x++;
	}
	return (color_point);
}

t_color_point	hex_to_dec_10(char *str)
{
	int x;
	t_color_point color_point;

	x = 2;
	color_point.r = 0;
	color_point.g = 0;
	color_point.b = 0;
	color_point.t = 0;
	while (str[x] != '\0' && ft_strlen(str) == 10)
	{
		if (x == 2 || x == 3)
			color_point.t += (hex_conv(str[x]) * pow(16, 3 - x));
		else if (x == 4 || x == 5)
			color_point.r += (hex_conv(str[x]) * pow(16, 5 - x));
		else if (x == 6 || x == 7)
			color_point.g += (hex_conv(str[x]) * pow(16, 7 - x));
		else if (x == 8 || x == 9)
			color_point.b += (hex_conv(str[x]) * pow(16, 9 - x));
		x++;
	}
	return (color_point);
}

int	hex_conv(char c)
{
	char *str;
	char *str_s;
	int	x;

	x = 0;
	str = "0123456789ABCDEF";
	str_s = "0123456789abcdef";
	while (str[x] != '\0')
	{
		if (str[x] == c)
			return (x);
		x++;
	}
	x = 0;
	while (str_s[x] != '\0')
	{
		if (str_s[x] == c)
			return (x);
		x++;
	}
	return (0);
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
	if (a.z > data->max_y)
		data->max_z = a.z;
	if (fabs(data->min_z) > data->max_z)
		data->max_z = fabs(data->min_z);
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
	// data->new_max = data->max_z;
	// if (data->min_z < 0 || (data->min_z < 0 && data->max_z < 0))
	// {
	// 	a.z = a.z - data->min_z + 1;
	// 	data->new_max = data->max_z - data->min_z + 1;
	// }
	return (a);
}
