/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:00:06 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/13 23:11:11 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_map_data *data)
{
	clean_img(data);
	// printf("keysym: %d\n", keysym);
	if (keysym == U_COMMAND || keysym == J_COMMAND || keysym == I_COMMAND \
	|| keysym == K_COMMAND || keysym == O_COMMAND || keysym == L_COMMAND)
		handle_rotation(keysym, data);
	else if (keysym == W_COMMAND || keysym == A_COMMAND \
	|| keysym == S_COMMAND || keysym == D_COMMAND)
		handle_offset(keysym, data);
	else if (keysym == ZO_COMMAND || keysym == ZI_COMMAND)
		handle_scale(keysym, data);
	else if (keysym == ISO_COMMAND || keysym == PAR_COMMAND || keysym == FRN_COMMAND \
	|| keysym == TOP_COMMAND || keysym == SID_COMMAND)
	{
		hook_setdefault(data);
		handle_projection(keysym, data);
	}
	else if (keysym == COLOR0_COMMAND || keysym == COLOR1_COMMAND || keysym == COLOR2_COMMAND \
	|| keysym == COLOR3_COMMAND || keysym == COLOR4_COMMAND || keysym == COLOR5_COMMAND \
	|| keysym == COLOR6_COMMAND || keysym == COLOR7_COMMAND || keysym == COLOR8_COMMAND)
		handle_color(keysym, data);
	else if (keysym == M_COMMAND || keysym == N_COMMAND)
		handle_z(keysym, data);
	else if (keysym == C_COMMAND || keysym == V_COMMAND)
		handle_color_style(keysym, data);
	else if (keysym == R_COMMAND)
		reset_values(data);
	else if (keysym == ESC_COMMAND)
		ft_close(data);
	map_draw(data);
	// printf("x: %f y: %f z: %f\n", data->theta_x, data->theta_y, data->theta_z);
	// ft_menu(data);
	return (0);
}

void	handle_color(int keysym, t_map_data *data)
{
	clean_img(data);
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
	else if (keysym == COLOR4_COMMAND)
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
	else if (keysym == COLOR7_COMMAND)
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
	color_name(data);
}

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
	else if (data->color_select == 5)
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
	// printf("z_factor: %f\n", data->z_factor);
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

void	handle_projection(int keysym, t_map_data *data)
{
	if (keysym == ISO_COMMAND)
	{
		data->projection = 1;
		data->theta_x = 0.174533;
		data->theta_y = 3.14159;
		data->theta_z = 1.5708;
	}
	else if (keysym == PAR_COMMAND)
	{
		data->projection = 2;
		data->theta_x = -0.785398;
		data->theta_y = 0.785398;
		data->theta_z = 0;
	}
	else if (keysym == TOP_COMMAND)
	{
		data->projection = 3;
		data->theta_x = 0;
		data->theta_y = 0;
		data->theta_z = 0;
	}
	else if (keysym == FRN_COMMAND)
	{
		data->projection = 4;
		data->theta_x = -1.5708;
		data->theta_y = 0;
		data->theta_z = 0;
	}
	else if (keysym == SID_COMMAND)
	{
		data->projection = 5;
		data->theta_x = -1.5708;
		data->theta_y = -1.5708;
		data->theta_z = 0;
	}
	find_maxmin(data, 1);
	find_maxmin(data, 0);
	set_screen(data);
}

void	find_maxmin(t_map_data *data, int set)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->row && set == 0)
	{
		x = 0;
		while (x < data->col)
		{
			if (data->point_map[y][x].z * data->z_factor > data->max_z_raw)
				data->max_z_raw = data->point_map[y][x].z * data->z_factor;
			if (data->point_map[y][x].z * data->z_factor < data->min_z_raw)
				data->min_z_raw = data->point_map[y][x].z * data->z_factor;
			x++;
		}
		y++;
	}
	while (y < data->row && set == 1)
	{
		x = 0;
		while (x < data->col)
		{
			get_rotationpoints(data->point_map[y][x], data);
			x++;
		}
		y++;
	}
}

void	reset_values(t_map_data *data)
{
	if (data->projection == 1)
	{
		data->theta_x = 0.174533;
		data->theta_y = 3.14159;
		data->theta_z = 1.5708;
	}
	if (data->projection == 2)
	{
		data->theta_x = -0.785398;
		data->theta_y = 0.785398;
		data->theta_z = 0;
	}
	if (data->projection == 3)
	{
		data->theta_x = 0;
		data->theta_y = 0;
		data->theta_z = 0;
	}
	if (data->projection == 4)
	{
		data->theta_x = -1.5708;
		data->theta_y = 0;
		data->theta_z = 0;
	}
	if (data->projection == 5)
	{
		data->theta_x = -1.5708;
		data->theta_y = -1.5708;
		data->theta_z = 0;
	}
	data->grid_scale = data->initgrid_scale;
	data->x_offset = data->initx_offset;
	data->y_offset = data->inity_offset;
	data->z_factor = 1;
	find_maxmin(data, 1);
	find_maxmin(data, 0);
}

void	clean_img(t_map_data *data)
{
	int	i;
	int	j;

	i = -1;
	find_maxmin(data, 1);
	find_maxmin(data, 0);
	while (++i <= round(data->max_x + data->x_offset))
	{
		j = -1;
		while (++j <= round(data->max_y + data->y_offset))
			img_mlx_pixel_put(data, i, j, 0x00000000);
	}
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void	handle_rotation(int keysym, t_map_data *data)
{
	if (keysym == 32)
		data->theta_x += 0.05;
	else if (keysym == 38)
		data->theta_x -= 0.05;
	else if (keysym == 34)
		data->theta_y += 0.05;
	else if (keysym == 40)
		data->theta_y -= 0.05;
	else if (keysym == 31)
		data->theta_z += 0.05;
	else if (keysym == 37)
		data->theta_z -= 0.05;
	find_maxmin(data, 1);
}

void	handle_offset(int keysym, t_map_data *data)
{
	if (keysym == 2)
		data->x_offset += 5;
	else if (keysym == 0)
		data->x_offset -= 5;
	else if (keysym == 1)
		data->y_offset += 5;
	else if (keysym == 13)
		data->y_offset -= 5;
	find_maxmin(data, 1);
}

void	handle_scale(int keysym, t_map_data *data)
{
	if (keysym == ZO_COMMAND && data->grid_scale < 150)
		data->grid_scale += 0.5;
	else if (keysym == ZI_COMMAND && data->grid_scale > 1)
		data->grid_scale -= 0.5;
	find_maxmin(data, 1);
}


void	ft_menu(t_map_data *data)
{
	ft_menu_extension(data);
	mlx_string_put(data->mlx_ptr, data->mlx_win, WINDOW_WIDTH - 250, \
		20, 0X00FFFF, "MAP NAME");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WINDOW_WIDTH - 250, \
		45, 0X00FFFF, data->name);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, WINDOW_HEIGHT - 150, 0X00FFFF, \
		"c and v -> color style");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, WINDOW_HEIGHT - 125, 0X00FFFF, \
		"0 to 8 -> color combination");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, \
		WINDOW_HEIGHT - 30, 0XFFFF00, "By: ELI JOSHUA MARAVILLAS");
}

void	ft_menu_extension(t_map_data *data)
{
	projection_type (data);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 25, 0XFFFF00, "COMMANDS");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 50, 0X00FFFF, "w -> move up");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 75, 0X00FFFF, "a -> move left");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 100, 0X00FFFF, "s -> move down");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 125, 0X00FFFF, "d -> move right");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 150, 0X00FFFF, \
	"r -> reset map");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 175, 0X00FFFF, \
	"+ / - -> zoom");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 200, 0X00FFFF, \
	"n and m -> dec/inc z");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 225, 0X00FFFF, \
		"~ -> ISOMETRIC");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 250, 0X00FFFF, \
		"TAB -> PARALLEL");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 275, 0X00FFFF, \
		"CAPS -> TOPVIEW");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 300, 0X00FFFF, \
		"LSHIFT -> FRONTVIEW");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 325, 0X00FFFF, \
		"LCTRL -> SIDEVIEW");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 350, 0X00FFFF, \
		"o and l -> rotation z");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 375, 0X00FFFF, \
		"i and k -> rotation y");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 400, 0X00FFFF, \
		"u and j -> rotation x");
}

void	projection_type(t_map_data *data)
{
	int	s;
	int	y;

	s = WINDOW_WIDTH - 250;
	y = 100;
	mlx_string_put(data->mlx_ptr, data->mlx_win, s, 80, 0X00FFFF, "PROJECTION TYPE");
	if (data->projection == 1)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "	Isometric Projection");
	if (data->projection == 2)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "	Parallel Projection");
	if (data->projection == 3)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "	Top View");
	if (data->projection == 4)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "	Front View");
	if (data->projection == 5)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "	Side View");
	mlx_string_put(data->mlx_ptr, data->mlx_win, s, \
		135, 0X00FFFF, "COLOR MAP");
	mlx_string_put(data->mlx_ptr, data->mlx_win, s, \
		160, 0X00FFFF, ft_strjoin("	Color A: ", data->color_a_name));
	mlx_string_put(data->mlx_ptr, data->mlx_win, s, \
		185, 0X00FFFF, ft_strjoin("	Color B: ", data->color_b_name));
	mlx_string_put(data->mlx_ptr, data->mlx_win, s, \
		WINDOW_HEIGHT - 30, 0X00FFFF, ft_strjoin("zoom: ", ft_itoa(round(data->grid_scale))));
}
