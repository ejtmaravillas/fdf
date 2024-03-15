/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setscreen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:17:05 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/14 20:25:59 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_screen(t_map_data *data)
{
	ft_printf("Calibrating drawing scale...\n");
	zoom_out(data);
	zoom_in(data);
	data->max_x = data->max_x + fabs(data->min_x);
	data->max_y = data->max_y + fabs(data->min_y);
	data->x_offset = fabs(data->min_x) + (WINDOW_WIDTH - data->max_x) / 2;
	data->y_offset = fabs(data->min_y) + (WINDOW_HEIGHT - data->max_y) / 2;
	data->initx_offset = data->x_offset;
	data->inity_offset = data->y_offset;
	data->initgrid_scale = data->grid_scale;
}

void	zoom_out(t_map_data *data)
{
	while ((data->max_x - data->min_x > WINDOW_WIDTH || \
		data->max_y - data->min_y > WINDOW_HEIGHT))
	{
		data->max_y /= 2;
		data->max_x /= 2;
		data->max_z /= 2;
		data->min_x /= 2;
		data->min_y /= 2;
		data->min_z /= 2;
		data->x_offset = (WINDOW_WIDTH - data->max_x - data->min_x) / 2;
		data->y_offset = (WINDOW_HEIGHT - data->max_y - data->min_y) / 2;
		data->grid_scale /= 2;
	}
}

void	zoom_in(t_map_data *data)
{
	while (((data->max_x - data->min_x) * 1.5 < WINDOW_WIDTH && \
		((data->max_y - data->min_y) * 1.5) < WINDOW_HEIGHT))
	{
		data->max_y *= 1.5;
		data->max_x *= 1.5;
		data->max_z *= 1.5;
		data->min_x *= 1.5;
		data->min_y *= 1.5;
		data->min_z *= 1.5;
		data->x_offset = (WINDOW_WIDTH - data->max_x - data->min_x) * 1.5;
		data->y_offset = (WINDOW_HEIGHT - data->max_y - data->min_y) * 1.5;
		data->grid_scale *= 1.5;
	}
}
