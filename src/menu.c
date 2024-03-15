/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:20:24 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 14:23:39 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu(t_map_data *data)
{
	ft_menu_extension(data);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 25, 0XFFFF00, "COMMANDS");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 50, 0X00FFFF, \
		"w -> move up");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 75, 0X00FFFF, \
		"a -> move left");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 100, 0X00FFFF, \
		"s -> move down");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 125, 0X00FFFF, \
		"d -> move right");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 150, 0X00FFFF, \
	"r -> reset map");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WINDOW_WIDTH - 250, \
		20, 0X00FFFF, "MAP NAME");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WINDOW_WIDTH - 250, \
		45, 0X00FFFF, data->name);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, \
		WINDOW_HEIGHT - 150, 0X00FFFF, \
		"c and v -> color style");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, \
		WINDOW_HEIGHT - 125, 0X00FFFF, \
		"0 to 8 -> color combination");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, \
		WINDOW_HEIGHT - 30, 0XFFFF00, "By: ELI JOSHUA MARAVILLAS");
}

void	ft_menu_extension(t_map_data *data)
{
	projection_type (data);
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
	mlx_string_put(data->mlx_ptr, data->mlx_win, s, 80, 0X00FFFF, \
		"PROJECTION TYPE");
	if (data->projection == 1)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "	Isometric Projection");
	else if (data->projection == 2)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "	Parallel Projection");
	else if (data->projection == 3)
		mlx_string_put(data->mlx_ptr, data->mlx_win, s, y, \
		0X00FFFF, "	Top View");
	projection_type_extn(data);
}

void	projection_type_extn(t_map_data *data)
{
	int	s;
	int	y;

	s = WINDOW_WIDTH - 250;
	y = 100;
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
		WINDOW_HEIGHT - 30, 0X00FFFF, ft_strjoin("zoom: ", \
		ft_itoa(round(data->grid_scale))));
}
