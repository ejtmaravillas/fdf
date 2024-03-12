/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/12 11:54:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(t_map_data *data)
{
	int	x;
	int	y;

	// printf("MAP DRAW\n");
	y = -1;
	while (++y < data->row)
	{
		x = 0;
		while (x < data->col)
		{
			// printf("X: %d Y: %d\n", x, y);
			if (x < data->col - 1)
				draw_line(data, data->point_map[y][x], \
				data->point_map[y][x + 1], data->color_point[y][x], data->color_point[y][x + 1]);
			if (y < data->row - 1)
				draw_line(data, data->point_map[y][x], \
				data->point_map[y + 1][x], data->color_point[y][x], data->color_point[y + 1][x]);
			x++;
		}
	}
	// printf("theta_x: %f theta_y: %f theta_z: %f\n", data->theta_x, data->theta_y, data->theta_z);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	ft_menu(data);
}



//DDA
void	draw_line(t_map_data *data, t_map_point p1, t_map_point p2, t_color_point pc1, t_color_point pc2)
{
	float	x;
	float	y;

	p1 = get_rotationpoints(p1, data);
	p2 = get_rotationpoints(p2, data);
	p1.x += data->x_offset;
	p1.y += data->y_offset;
	p2.x += data->x_offset;
	p2.y += data->y_offset;
	x = p1.x;
	y = p1.y;
	draw_params(data, p1, p2);
	while (fabs(p2.x - x) > 0.5)
	{
		data->color_gradient += (p1.y/data->range_z)/data->grid_scale;
		// data->color_gradient = 1;
		// printf("X gradient: %f\n", data->color_gradient);
		// printf("X range: %f\n", data->range_z);
		if ((x > 0 && x < WINDOW_WIDTH - 1) && (y > 0 && y < WINDOW_HEIGHT - 1))
			img_mlx_pixel_put(data, round(fabs(x)), round(fabs(y)), percent_to_color(data->color_gradient, data, pc1, pc2));
		x += data->dda_dx / data->dda_step;
		y += data->dda_dy / data->dda_step;
	}
	while (fabs(p2.y - y) > 0.5)
	{
		data->color_gradient += (p1.y/data->range_z)/data->grid_scale;
		// data->color_gradient = 1;
		// printf("Y gradient: %f\n", data->color_gradient);
		// printf("Y range: %f\n", data->range_z);
		if ((x > 0 && x < WINDOW_WIDTH - 1) && (y > 0 && y < WINDOW_HEIGHT - 1))
			img_mlx_pixel_put(data, round(fabs(x)), round(fabs(y)), percent_to_color(data->color_gradient, data, pc1, pc2));
		x += data->dda_dx / data->dda_step;
		y += data->dda_dy / data->dda_step;
	}
}



void	draw_params(t_map_data *data, t_map_point p1, t_map_point p2)
{
	// data->range_z = fabs(p1.z - p2.z) / data->max_z;
	data->range_z = data->max_y - data->min_y;
	data->color_gradient = 0;
	data->dda_dx = p2.x - p1.x;
	data->dda_dy = p2.y - p1.y;
	data->dda_slope = data->dda_dx / data->dda_dy;
	if (fabs(data->dda_dx) > fabs(data->dda_dy))
		data->dda_step = fabs(data->dda_dx);
	else
		data->dda_step = fabs(data->dda_dy);
}
