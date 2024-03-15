/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:00:06 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 15:32:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_map_data *data)
{
	clean_img(data);
	printf("keysym: %d\n", keysym);
	if (keysym == U_COMMAND || keysym == J_COMMAND || keysym == I_COMMAND \
	|| keysym == K_COMMAND || keysym == O_COMMAND || keysym == L_COMMAND)
		handle_rotation(keysym, data);
	else if (keysym == W_COMMAND || keysym == A_COMMAND \
	|| keysym == S_COMMAND || keysym == D_COMMAND)
		handle_offset(keysym, data);
	else if (keysym == ZO_COMMAND || keysym == ZI_COMMAND)
		handle_scale(keysym, data);
	else if (keysym == ISO_COMMAND || keysym == PAR_COMMAND || keysym == \
	FRN_COMMAND || keysym == TOP_COMMAND || keysym == SID_COMMAND)
	{
		hook_setdefault(data);
		handle_projection(keysym, data);
	}
	handle_keypress_extn(keysym, data);
	map_draw(data);
	return (0);
}

void	handle_keypress_extn(int keysym, t_map_data *data)
{
	if (keysym == COLOR0_COMMAND || keysym == COLOR1_COMMAND || \
		keysym == COLOR2_COMMAND || keysym == COLOR3_COMMAND || keysym \
		== COLOR4_COMMAND || keysym == COLOR5_COMMAND || keysym == \
		COLOR6_COMMAND || keysym == COLOR7_COMMAND || keysym == \
		COLOR8_COMMAND || keysym == COLOR9_COMMAND)
		handle_color(keysym, data);
	else if (keysym == M_COMMAND || keysym == N_COMMAND)
		handle_z(keysym, data);
	else if (keysym == C_COMMAND || keysym == V_COMMAND)
		handle_color_style(keysym, data);
	else if (keysym == R_COMMAND)
		reset_values(data);
	else if (keysym == ESC_COMMAND)
		ft_close(data);
}

void	handle_color(int keysym, t_map_data *data)
{
	if (keysym == COLOR1_COMMAND)
	{
		data->color_select = 1;
		data->color_a = set_color("0x0000FF");
		data->color_b = set_color("0xFFFF00");
	}
	else if (keysym == COLOR2_COMMAND)
	{
		data->color_select = 2;
		data->color_a = set_color("0xFFFF00");
		data->color_b = set_color("0x0000FF");
	}
	else if (keysym == COLOR3_COMMAND)
	{
		data->color_select = 3;
		data->color_a = set_color("0xFF00FF");
		data->color_b = set_color("0x00FF00");
	}
	else
		handle_color_extn(keysym, data);
	color_name(data);
}

void	handle_color_extn(int keysym, t_map_data *data)
{
	if (keysym == COLOR4_COMMAND)
	{
		data->color_select = 4;
		data->color_a = set_color("0x00FF00");
		data->color_b = set_color("0xFF00FF");
	}
	else if (keysym == COLOR5_COMMAND)
	{
		data->color_select = 5;
		data->color_a = set_color("0xFF0000");
		data->color_b = set_color("0x00FFFF");
	}
	else if (keysym == COLOR6_COMMAND)
	{
		data->color_select = 6;
		data->color_a = set_color("0x00FFFF");
		data->color_b = set_color("0xFF0000");
	}
	else
		handle_color_extn_a(keysym, data);
}

void	handle_color_extn_a(int keysym, t_map_data *data)
{
	if (keysym == COLOR7_COMMAND)
	{
		data->color_select = 7;
		data->color_a = set_color("0xFFE755");
		data->color_b = set_color("0x871282");
	}
	else if (keysym == COLOR8_COMMAND)
	{
		data->color_select = 8;
		data->color_a = set_color("0x871282");
		data->color_b = set_color("0xFFE755");
	}
	else if (keysym == COLOR9_COMMAND)
	{
		data->color_select = 9;
		data->color_a = set_color("0xFFFFFF");
		data->color_b = set_color("0xFFFFFF");
	}
	else
		data->color_select = 0;
}
