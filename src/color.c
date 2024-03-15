/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:00:06 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/10 01:55:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	percent_to_color(float percent, t_map_data *data, t_color_point p1, \
	t_color_point p2)
{
	t_color_point	p3;

	if (data->color_select > 0)
	{
		p3 = get_color_val(percent, p1, p2);
		return (create_trgb(0, p3.r, p3.g, p3.b));
	}
	else
		return (create_trgb(0, 255, 255, 255));
}

t_color_point	get_color_val(float percent, t_color_point p1, t_color_point p2)
{
	t_color_point	color_point;

	color_point.r = round((p2.r - p1.r) * percent) + p1.r;
	color_point.g = round((p2.g - p1.g) * percent) + p1.g;
	color_point.b = round((p2.b - p1.b) * percent) + p1.b;
	return (color_point);
}
