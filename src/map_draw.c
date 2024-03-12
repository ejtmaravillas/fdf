/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/12 18:48:43 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(t_map_data *data)
{
	int	x;
	int	y;

	y = -1;
	find_maxmin(data);
	if (data->min_z < 0)
		data->range_z = data->max_z + fabs(data->min_z);
	else
		data->range_z = data->max_z - data->min_z;
	while (++y < data->row)
	{
		x = 0;
		while (x < data->col)
		{
			// printf("Y: %d X: %d\n", y, x);
			if (x < data->col - 1)
				draw_line(data, data->point_map[y][x], \
				data->point_map[y][x + 1]);
			if (y < data->row - 1)
				draw_line(data, data->point_map[y][x], \
				data->point_map[y + 1][x]);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	ft_menu(data);
}

void	draw_line(t_map_data *data, t_map_point p1, t_map_point p2)
{
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

void	draw_h(t_map_data *data, t_map_point p1, t_map_point p2)
{
	float	x;
	float	y;

	x = p1.x;
	y = p1.y;
	while (fabs(p2.x - x) > 0.5)
	{
		if (data->min_z < 0)
			data->color_gradient = (p1.z + fabs(data->min_z)) / data->range_z;
		else
			data->color_gradient = p1.z / data->range_z;
		if ((x > 0 && x < WINDOW_WIDTH - 1) && (y > 0 && y < WINDOW_HEIGHT - 1))
			img_mlx_pixel_put(data, round(fabs(x)), round(fabs(y)), \
			percent_to_color(data->color_gradient, data, data->color_a, \
			data->color_b));
		x += data->dda_dx / data->dda_step;
		y += data->dda_dy / data->dda_step;
	}
}

void	draw_v(t_map_data *data, t_map_point p1, t_map_point p2)
{
	float	x;
	float	y;

	x = p1.x;
	y = p1.y;
	while (fabs(p2.y - y) > 0.5)
	{
		if (data->min_z < 0)
			data->color_gradient = (p1.z + fabs(data->min_z)) / data->range_z;
		else
			data->color_gradient = p1.z / data->range_z;
		if ((x > 0 && x < WINDOW_WIDTH - 1) && (y > 0 && y < WINDOW_HEIGHT - 1))
			img_mlx_pixel_put(data, round(fabs(x)), round(fabs(y)), \
			percent_to_color(data->color_gradient, data, data->color_a, \
			data->color_b));
		x += data->dda_dx / data->dda_step;
		y += data->dda_dy / data->dda_step;
	}
}

void	draw_params(t_map_data *data, t_map_point p1, t_map_point p2)
{
	data->color_gradient = 0;
	data->dda_dx = p2.x - p1.x;
	data->dda_dy = p2.y - p1.y;
	data->dda_slope = data->dda_dx / data->dda_dy;
	if (fabs(data->dda_dx) > fabs(data->dda_dy))
		data->dda_step = fabs(data->dda_dx);
	else
		data->dda_step = fabs(data->dda_dy);
}
