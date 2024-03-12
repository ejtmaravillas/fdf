/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setscreen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:17:05 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/11 15:53:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_screen(t_map_data *data)
{
	if ((data->max_x  - data->min_x > WINDOW_WIDTH || data->max_y - data->min_y > WINDOW_HEIGHT))
		zoom_out(data);
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
	while ((data->max_x  - data->min_x > WINDOW_WIDTH || data->max_y - data->min_y > WINDOW_HEIGHT))
	{
		data->max_y /= 2;
		data->max_x /= 2;
		data->min_x /= 2;
		data->min_y /= 2;
		data->x_offset = (WINDOW_WIDTH - data->max_x - data->min_x) / 2;
		data->y_offset = (WINDOW_HEIGHT - data->max_y - data->min_y) / 2;
		data->grid_scale /= 2;
	}
}

void	zoom_in(t_map_data *data)
{
	printf("ZOOM in!\n");
	while (data->max_x * 3 < WINDOW_WIDTH || data->max_y * 3 < WINDOW_HEIGHT)
	{
		data->max_x *= 3;
		data->max_y *= 3;
		data->x_offset = fabs(data->x_offset * 3);
		data->y_offset = fabs(data->y_offset * 3);
		data->grid_scale *= 3;
	}
}
