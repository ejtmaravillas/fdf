/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/08 17:53:13 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(t_map_data *data)
{
	int	x;
	int	y;

	printf("MAP DRAW\n");
	y = 0;
	while (y < data->row)
	{
		x = 0;
		while (x < data->col)
		{
			if (x < data->col - 1)
				draw_line(data, data->point_map[y][x], \
				data->point_map[y][x + 1]);
			if (y < data->row - 1)
				draw_line(data, data->point_map[y][x], \
				data->point_map[y + 1][x]);
			x++;
		}
		y++;
	}
	// printf("theta_x: %f theta_y: %f theta_z: %f\n", data->theta_x, data->theta_y, data->theta_z);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}

//DDA
void	draw_line(t_map_data *data, t_map_point p1, t_map_point p2)
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
	while (round(x) != round(p2.x))
	{
		if ((x > 0 && x < WINDOW_WIDTH) || (y > 0 && y < WINDOW_HEIGHT))
			img_mlx_pixel_put(data, round(fabs(x)), round(fabs(y)), 0xFFFFFF);
		x += data->dda_dx / data->dda_step;
		y += data->dda_dy / data->dda_step;
	}
}

void	draw_params(t_map_data *data, t_map_point p1, t_map_point p2)
{
	data->dda_dx = p2.x - p1.x;
	data->dda_dy = p2.y - p1.y;
	data->dda_slope = data->dda_dx / data->dda_dy;
	if (fabs(data->dda_dx) > fabs(data->dda_dy))
		data->dda_step = fabs(data->dda_dx);
	else
		data->dda_step = fabs(data->dda_dy);
}
