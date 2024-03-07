/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/07 22:40:59 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(t_map_data *data)
{
	int	x;
	int	y;
	// int	y_next;

	printf("MAP DRAW\n");
	printf("data->grid_scale: %f\n", data->grid_scale);
	printf("data->x_offset: %f\n", data->x_offset);
	printf("data->y_offset: %f\n", data->y_offset);
	y = 0;
	while (y < data->row)
	{
		x = 0;
		while (x < data->col)
		{
			printf("|| x1: %f y1: %f z1: %f ||\n", data->point_map[y][x].x, data->point_map[y][x].y, data->point_map[y][x].z);
			printf("|| x2: %f y2: %f z2: %f ||\n", data->point_map[y][x + 1].x, data->point_map[y][x + 1].y, data->point_map[y][x + 1].z);
			printf("data->row: %d\n", data->row);
			printf("data->col: %d\n", data->col);
			printf("data->x_offset: %f\n", data->x_offset);
			printf("data->y_offset: %f\n", data->min_y);
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
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}

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
	printf("x1: %f y1: %f z1: %f\n", p1.x, p1.y, p1.z);
	printf("x2: %f y2: %f z2: %f\n", p2.x, p2.y, p2.z);
	x = p1.x;
	y = p1.y;
	draw_params(data, p1, p2);
	while (fabs(p2.x - x) > 0.5)
	{
		img_mlx_pixel_put(data, round(fabs(x)), round(fabs(y)), 0xFFFF0000);
		x += data->dda_dx / data->dda_step;
		y += data->dda_dy / data->dda_step;
		printf("	x: %f y: %f\n", x, y);
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
