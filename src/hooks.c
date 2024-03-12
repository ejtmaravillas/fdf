/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:00:06 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/11 21:40:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_map_data *data)
{
	clean_img(data);
	// printf("keysym: %d\n", keysym);
	// printf("grid_scale: %f\n", data->grid_scale);
	if (keysym == 117 || keysym == 106 || keysym == 105 \
	|| keysym == 107 || keysym == 111 || keysym == 108)
		handle_rotation(keysym, data);
	else if (keysym == 119 || keysym == 97 \
	|| keysym == 115 || keysym == 100)
		handle_offset(keysym, data);
	else if (keysym == 65451 || keysym == 65453)
		handle_scale(keysym, data);
	else if (keysym == 65289 || keysym == 65509 || keysym == 65505 \
	|| keysym == 96 || keysym == 65507)
	{
		hook_setdefault(data);
		handle_projection(keysym, data);
	}
	else if (keysym == 110 || keysym == 109)
		handle_z(keysym, data);
	else if (keysym == 114)
		reset_values(data);
	else if (keysym == 65307)
		ft_close(data);
	// printf("max_x: %f max_y: %f\n", data->max_x, data->max_y);
	map_draw(data);
	return (0);
}

// NUMPAD
// 0 = 65438
// 1 = 65436
// 2 = 65433
// 3 = 65435
// 4 = 65430
// 5 = 65437
// 6 = 65432
// 7 = 65429
// 8 = 65431
// 9 = 65434

void	handle_z(int keysym, t_map_data *data)
{
	if (keysym == 110 && data->z_factor <= 2.5 )
		data->z_factor += 0.05;
	else if (keysym == 109 && data->z_factor >= 0.5)
		data->z_factor -= 0.05;
	// printf("z_factor: %f\n", data->z_factor);
}
void	hook_setdefault(t_map_data *data)
{
	data->grid_scale = 50;
	data->max_x = 0;
	data->max_y = 0;
	data->max_z = 0;
	data->min_x = 0;
	data->min_y = 0;
	data->min_z = 0;
	data->x_offset = 0;
	data->y_offset = 0;
	data->z_factor = 1;
}

void	handle_projection(int keysym, t_map_data *data)
{
	if (keysym == 96)
	{
		data->projection = 1;
		data->theta_x = 0.174533;
		data->theta_y = 3.14159;
		data->theta_z = 1.5708;
		find_maxmin(data);
		set_screen(data);
	}
	else if (keysym == 65289)
	{
		data->projection = 2;
		data->theta_x = -0.785398;
		data->theta_y = 0.785398;
		data->theta_z = 0;
		find_maxmin(data);
		set_screen(data);
	}
	else if (keysym == 65509)
	{
		data->projection = 3;
		data->theta_x = 0;
		data->theta_y = 0;
		data->theta_z = 0;
		find_maxmin(data);
		set_screen(data);
	}
	else if (keysym == 65505)
	{
		data->projection = 4;
		data->theta_x = -1.5708;
		data->theta_y = 0;
		data->theta_z = 0;
		find_maxmin(data);
		set_screen(data);
	}
	else if (keysym == 65507)
	{
		data->projection = 5;
		data->theta_x = -1.5708;
		data->theta_y = -1.5708;
		data->theta_z = 0;
		find_maxmin(data);
		set_screen(data);
	}
}

void	find_maxmin(t_map_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->row)
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
}

	// if (keysym == 32 || keysym == 38 || keysym == 34
	// || keysym == 40 || keysym == 31 || keysym == 37)
	// 	handle_rotation(keysym, data);
	// else if (keysym == 0 || keysym == 2
	// || keysym == 13 || keysym == 1)
	// 	handle_offset(keysym, data);

// LINUX KEYS
// w = 119
// a = 97
// s = 115
// d = 100

// u = 117
// j = 106
// i = 105
// k = 107
// o = 111
// l = 108

// ~ == 96
// TAB == 65289
// CAPS == 65509
// LSHIFT == 65505
// LCTRL == 65507

void	clean_img(t_map_data *data)
{
	// int	i;
	// int	j;

	// i = -1;
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// while (++i <= round(data->max_x + data->x_offset))
	// {
	// 	j = -1;
	// 	while (++j <= round(data->max_y + data->y_offset))
	// 		img_mlx_pixel_put(data, i, j, 0x00000000);
	// }
}

void	handle_rotation(int keysym, t_map_data *data)
{
	if (keysym == 117)
		data->theta_x += 0.01;
	else if (keysym == 106)
		data->theta_x -= 0.01;
	else if (keysym == 105)
		data->theta_y += 0.01;
	else if (keysym == 107)
		data->theta_y -= 0.01;
	else if (keysym == 111)
		data->theta_z += 0.01;
	else if (keysym == 108)
		data->theta_z -= 0.01;
}
// LINUX KEYS
// w = 119
// a = 97
// s = 115
// d = 100

// u = 117
// j = 106
// i = 105
// k = 107
// o = 111
// l = 108
void	handle_offset(int keysym, t_map_data *data)
{
	if (keysym == 100)
		data->x_offset += 5;
	else if (keysym == 97)
		data->x_offset -= 5;
	else if (keysym == 115)
		data->y_offset += 5;
	else if (keysym == 119)
		data->y_offset -= 5;
}

void	handle_scale(int keysym, t_map_data *data)
{
	if (keysym == 65451 && data->grid_scale < 150)
		data->grid_scale += 0.5;
	else if (keysym == 65453 && data->grid_scale > 1)
		data->grid_scale -= 0.5;
}

// w = 13
// a = 0
// s = 1
// d = 2

// + = 65451
// - = 65453

// u = 32
// j = 38
// i = 34
// k = 40
// o = 31
// l = 37

// n = 110
// m = 109

void	ft_menu(t_map_data *data)
{
	ft_menu_extension(data);
	// mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 
	// 	425, 0xAFA9A9, "mouse click - grid location");
	// mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 
	// 	450, 0xAFA9A9, "y and u - change projection");
	// mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 475, 0xAFA9A9, 
	// "9 and 0 - menu change");
	// mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 
	// 	500, 0xAFA9A9, "3 and 4 - change mode");
	// mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 525, 0xAFA9A9, 
	// "m - change map");
	// mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 
	// 	550, 0xAFA9A9, "r - reset map");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WINDOW_WIDTH - 125, \
		20, 0X00FFFF, "MAP NAME");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WINDOW_WIDTH - 125, \
		45, 0X00FFFF, data->name);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, \
		WINDOW_HEIGHT - 10, 0XFFFF00, "By: ELI JOSHUA MARAVILLAS");
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

	s = WINDOW_WIDTH - 125;
	y = 100;
	mlx_string_put(data->mlx_ptr, data->mlx_win, s, 80, 0X00FFFF, "PROJECTION TYPE");
	if (data->projection == 1)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "ISOMETRIC Projection");
	if (data->projection == 2)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "PARALLEL Projection");
	if (data->projection == 3)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "TOP VIEW");
	if (data->projection == 4)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "FRONT VIEW");
	if (data->projection == 5)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "SIDE VIEW");
	mlx_string_put(data->mlx_ptr, data->mlx_win, s, \
		WINDOW_HEIGHT - 10, 0X00FFFF, ft_strjoin("zoom: ", ft_itoa(round(data->grid_scale))));
	// if (vars->tranform_number == 1)
	// {
	// 	mlx_string_put(vars->mlx, vars->win, s, y, 
	// 	0xAFA9A9, "Isometric Projection");
	// }
	// else if (vars->tranform_number == 2)
	// {
	// 	mlx_string_put(vars->mlx, vars->win, s, 
	// 	100, 0xAFA9A9, "Parallel Projection");
	// }
	// else if (vars->tranform_number == 3)
	// 	mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "Top View");
	// else if (vars->tranform_number == 4)
	// 	mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "Right View");
	// else if (vars->tranform_number == 5)
	// 	mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "Bottom View");
	// mlx_string_put(vars->mlx, vars->win, 100, 20, 0xAFA9A9, "COMMANDS");
	// mlx_string_put(vars->mlx, vars->win, 100, 50, 0xAFA9A9, "/\\ - up");
}
