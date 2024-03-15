/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:53:58 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 14:55:01 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_v(t_map_data *data, t_map_point p1, t_map_point p2)
{
	float	x;
	float	y;
	float	z;

	x = p1.x;
	y = p1.y;
	z = p1.z;
	while (fabs(p2.y - y) > 0.5)
	{
		if ((x > 0 && x < WINDOW_WIDTH - 1) && (y > 0 && y < WINDOW_HEIGHT - 1))
		{
			if (data->color_style == 1)
				data->color_gradient = (z - (data->min_z)) / data->range_z;
			else
				data->color_gradient = (p2.y - y) / (p2.y - p1.y);
			draw_pixel(data, x, y);
		}
		x += data->dda_dx / data->dda_step;
		y += data->dda_dy / data->dda_step;
		z += data->dda_dz / data->dda_step;
	}
}

void	draw_h(t_map_data *data, t_map_point p1, t_map_point p2)
{
	float	x;
	float	y;
	float	z;

	x = p1.x;
	y = p1.y;
	z = p1.z;
	while (fabs(p2.x - x) > 0.5)
	{
		if ((x > 0 && x < WINDOW_WIDTH - 1) && (y > 0 && y < WINDOW_HEIGHT - 1))
		{
			if (data->color_style == 1)
				data->color_gradient = (z - (data->min_z)) / data->range_z;
			else
				data->color_gradient = (p2.x - x) / (p2.x - p1.x);
			draw_pixel(data, x, y);
		}
		x += data->dda_dx / data->dda_step;
		y += data->dda_dy / data->dda_step;
		z += data->dda_dz / data->dda_step;
	}
}

void	draw_pixel(t_map_data *data, float x, float y)
{
	if (data->color_style == 1)
	{
		img_mlx_pixel_put(data, round(fabs(x)), round(fabs(y)), \
		percent_to_color(data->color_gradient, data, data->color_a, \
		data->color_b));
	}
	else
	{
		img_mlx_pixel_put(data, round(fabs(x)), round(fabs(y)), \
		percent_to_color(data->color_gradient, data, data->color_b_z, \
		data->color_a_z));
	}
}
