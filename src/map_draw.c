/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 14:54:23 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(t_map_data *data)
{
	int	x;
	int	y;

	y = -1;
	draw_select_style(data);
	while (++y < data->row)
	{
		x = -1;
		while (++x < data->col)
			draw_select_color(data, x, y);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	ft_menu(data);
}

void	draw_select_style(t_map_data *data)
{
	if (data->color_style == 1)
		data->range_z = data->max_z - data->min_z;
	if (data->color_style == 0)
		data->range_z = data->max_z_raw - data->min_z_raw;
}

void	draw_select_color(t_map_data *data, int x, int y)
{
	if (x < data->col - 1)
	{
		if (data->color_select == 9)
		{
			data->color_a_z = data->color_point[y][x];
			data->color_b_z = data->color_point[y][x + 1];
			data->color_a = data->color_point[y][x];
			data->color_b = data->color_point[y][x + 1];
		}
		draw_line(data, data->point_map[y][x], \
		data->point_map[y][x + 1]);
	}
	if (y < data->row - 1)
	{
		if (data->color_select == 9)
		{
			data->color_a_z = data->color_point[y][x];
			data->color_b_z = data->color_point[y + 1][x];
			data->color_a = data->color_point[y][x];
			data->color_b = data->color_point[y + 1][x];
		}
		draw_line(data, data->point_map[y][x], \
		data->point_map[y + 1][x]);
	}
}

void	draw_line(t_map_data *data, t_map_point p1, t_map_point p2)
{
	p1.z *= data->z_factor;
	p2.z *= data->z_factor;
	if (data->color_style == 0 && !(data->color_select == 9))
	{
		data->color_a_z = get_color_val((p1.z - data->min_z_raw) / \
		data->range_z, data->color_a, data->color_b);
		data->color_b_z = get_color_val((p2.z - data->min_z_raw) / \
		data->range_z, data->color_a, data->color_b);
	}
	p1 = get_rotationpoints(p1, data);
	p2 = get_rotationpoints(p2, data);
	p1.x += data->x_offset;
	p1.y += data->y_offset;
	p2.x += data->x_offset;
	p2.y += data->y_offset;
	draw_params(data, p1, p2);
	draw_h(data, p1, p2);
	draw_v(data, p1, p2);
}

void	draw_params(t_map_data *data, t_map_point p1, t_map_point p2)
{
	data->color_gradient = 0;
	data->dda_dx = p2.x - p1.x;
	data->dda_dy = p2.y - p1.y;
	data->dda_dz = p2.z - p1.z;
	data->dda_slope = data->dda_dx / data->dda_dy;
	if (fabs(data->dda_dx) > fabs(data->dda_dy))
		data->dda_step = fabs(data->dda_dx);
	else
		data->dda_step = fabs(data->dda_dy);
}
