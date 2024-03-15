/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:17:23 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 14:55:12 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color_point	set_color(char *str)
{
	t_color_point	color_point;

	color_point.r = 0;
	color_point.g = 0;
	color_point.b = 0;
	color_point.t = 0;
	if (str != NULL && ft_strlen(str) == 8)
		color_point = hex_to_dec_8(str);
	else if (str != NULL && ft_strlen(str) == 10)
		color_point = hex_to_dec_10(str);
	else if (str == NULL)
	{
		color_point.r = 255;
		color_point.g = 255;
		color_point.b = 255;
		color_point.t = 0;
	}
	else
		color_point = hex_to_dec_8(str);
	return (color_point);
}

t_color_point	hex_to_dec_8(char *str)
{
	int				x;
	t_color_point	color_point;

	x = 2;
	color_point.r = 0;
	color_point.g = 0;
	color_point.b = 0;
	color_point.t = 0;
	while (str[x] != '\0')
	{
		if (x == 2 || x == 3)
		{
			color_point.r += (hex_conv(str[x]) * pow(16, 3 - x));
		}
		else if (x == 4 || x == 5)
			color_point.g += (hex_conv(str[x]) * pow(16, 5 - x));
		else if (x == 6 || x == 7)
			color_point.b += (hex_conv(str[x]) * pow(16, 7 - x));
		x++;
	}
	return (color_point);
}

t_color_point	hex_to_dec_10(char *str)
{
	int				x;
	t_color_point	color_point;

	x = 2;
	color_point.r = 0;
	color_point.g = 0;
	color_point.b = 0;
	color_point.t = 0;
	while (str[x] != '\0')
	{
		if (x == 2 || x == 3)
			color_point.t += (hex_conv(str[x]) * pow(16, 3 - x));
		else if (x == 4 || x == 5)
			color_point.r += (hex_conv(str[x]) * pow(16, 5 - x));
		else if (x == 6 || x == 7)
			color_point.g += (hex_conv(str[x]) * pow(16, 7 - x));
		else if (x == 8 || x == 9)
			color_point.b += (hex_conv(str[x]) * pow(16, 9 - x));
		x++;
	}
	return (color_point);
}

int	hex_conv(char c)
{
	char	*str;
	char	*str_s;
	int		x;

	x = 0;
	str = "0123456789ABCDEF";
	str_s = "0123456789abcdef";
	while (str[x] != '\0')
	{
		if (str[x] == c)
			return (x);
		x++;
	}
	x = 0;
	while (str_s[x] != '\0')
	{
		if (str_s[x] == c)
			return (x);
		x++;
	}
	return (0);
}
