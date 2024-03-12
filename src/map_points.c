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
	t_color_point	color_point;

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
		color_point.t = 0;
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
	color_point.t = 0;
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
