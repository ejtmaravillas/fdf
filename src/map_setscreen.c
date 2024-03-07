/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setscreen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:17:05 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/07 22:22:51 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_screen(t_map_data *data)
{
	int	x_diff;
	int	y_diff;

	x_diff = WINDOW_WIDTH - data->max_x;
	y_diff = WINDOW_HEIGHT - data->max_y;
	data->max_x = data->max_x - data->min_x;
	data->max_y = data->max_y - data->min_y;
	data->x_offset = -data->min_x;
	data->y_offset = -data->min_y;
	if (x_diff < 0 || y_diff < 0)
		zoom_out(data);
	else
		zoom_in(data);
}

void	zoom_out(t_map_data *data)
{
	while ((data->max_x > WINDOW_WIDTH || data->max_y > WINDOW_HEIGHT))
	{
		data->max_y /= 2;
		data->max_x /= 2;
		data->x_offset = fabs(data->x_offset / 2);
		data->y_offset = fabs(data->y_offset / 2);
		data->grid_scale /= 2;
		if (data->grid_scale < 1)
		{
			if (data->max_y > WINDOW_HEIGHT)
				data->max_y = WINDOW_HEIGHT;
			if (data->max_x > WINDOW_WIDTH)
				data->max_x = WINDOW_WIDTH;
			break ;
		}
	}
}

void	zoom_in(t_map_data *data)
{
	while (data->max_x > WINDOW_WIDTH || data->max_y > WINDOW_HEIGHT)
	{
		data->max_x *= 3;
		data->max_y *= 3;
		data->x_offset = fabs(data->x_offset * 3);
		data->y_offset = fabs(data->y_offset * 3);
		data->grid_scale *= 3;
	}
}
