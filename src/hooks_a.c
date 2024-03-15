/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:30:40 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 14:53:09 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_name(t_map_data *data)
{
	if (data->color_select == 1)
	{
		data->color_a_name = "0x0000FF";
		data->color_b_name = "0xFFFF00";
	}
	else if (data->color_select == 2)
	{
		data->color_a_name = "0xFFFF00";
		data->color_b_name = "0x0000FF";
	}
	else if (data->color_select == 3)
	{
		data->color_a_name = "0xFF00FF";
		data->color_b_name = "0x00FF00";
	}
	else if (data->color_select == 4)
	{
		data->color_a_name = "0x00FF00";
		data->color_b_name = "0xFF00FF";
	}
	color_name_extn(data);
	find_maxmin(data, 1);
}

void	color_name_extn(t_map_data *data)
{
	if (data->color_select == 5)
	{
		data->color_a_name = "0xFF0000";
		data->color_b_name = "0x00FFFF";
	}
	else if (data->color_select == 6)
	{
		data->color_a_name = "0x00FFFF";
		data->color_b_name = "0xFF0000";
	}
	else if (data->color_select == 7)
	{
		data->color_a_name = "0xFFE755";
		data->color_b_name = "0x871282";
	}
	else if (data->color_select == 8)
	{
		data->color_a_name = "0x871282";
		data->color_b_name = "0xFFE755";
	}
	else
	{
		data->color_a_name = "0xFFFFFF";
		data->color_b_name = "0xFFFFFF";
	}
}

void	handle_color_style(int keysym, t_map_data *data)
{
	if (keysym == C_COMMAND)
		data->color_style = 1;
	else if (keysym == V_COMMAND)
		data->color_style = 0;
	find_maxmin(data, 1);
}

void	handle_z(int keysym, t_map_data *data)
{
	if (keysym == M_COMMAND && data->z_factor <= 5)
	{
		data->z_factor += 0.05;
		data->max_z_raw = 0;
		data->min_z_raw = 0;
	}
	else if (keysym == N_COMMAND && data->z_factor >= 0.2)
	{
		data->z_factor -= 0.05;
		data->max_z_raw = 0;
		data->min_z_raw = 0;
	}
	find_maxmin(data, 1);
	find_maxmin(data, 0);
}

void	hook_setdefault(t_map_data *data)
{
	data->grid_scale = 60;
	data->max_x = 0;
	data->max_y = 0;
	data->max_z = 0;
	data->max_z_raw = 0;
	data->min_x = 0;
	data->min_y = 0;
	data->min_z = 0;
	data->min_z_raw = 0;
	data->x_offset = 0;
	data->y_offset = 0;
	data->z_factor = 1;
	data->color_gradient = 0;
}
