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

int	percent_to_color(float percent, t_map_data *data, t_color_point p1, t_color_point p2)
{
	t_color_point p3;

	if (data->color_select == 0)
	{
		p3 = get_color_val(percent, p1, p2);
		return (create_trgb(p3.t, p3.r, p3.g, p3.b));
	}
	else if (data->color_select == 1)
	{
		p3 = get_color_val(percent, p2, p1);
		return (create_trgb(p3.t, p3.r, p3.g, p3.b));
	}
	else if (data->color_select == 2)
	{
		p1.t = 0;
		p1.r = 255;
		p1.g = 255;
		p1.b = 0;
		p2.t = 0;
		p2.r = 0;
		p2.g = 0;
		p2.b = 255;
		p3 = get_color_val(percent, p1, p2);
		return (create_trgb(p3.t, p3.r, p3.g, p3.b));
	}
	else if (data->color_select == 3)
	{
		p1.t = 0;
		p1.r = 0;
		p1.g = 0;
		// p1.b = rand() % 255;
		p1.b = 255;
		p2.t = 0;
		p2.r = 255;
		p2.g = 255;
		p2.b = 0;
		p3 = get_color_val(percent, p1, p2);
		return (create_trgb(p3.t, p3.r, p3.g, p3.b));
	}
	else
		return (create_trgb(0, 255, 255, 255));
}


t_color_point get_color_val(float percent, t_color_point p1, t_color_point p2)
{
	t_color_point color_point;

	// printf("p1.t: %d p1.r: %d p1.g: %d p1.b: %d\n", p1.t, p1.r, p1.g, p1.b);
	// printf("p2.t: %d p2.r: %d p2.g: %d p2.b: %d\n", p2.t, p2.r, p2.g, p2.b);
	// printf("percent: %f\n", percent);
	color_point.r = (p2.r - p1.r) * percent + p1.r;
	color_point.g = (p2.g - p1.g) * percent + p1.g;
	color_point.b = (p2.b - p1.b) * percent + p1.b;
	color_point.t = (p2.t - p1.t) * percent + p1.t;
	// printf("	t: %d r: %d g: %d b: %d\n", color_point.t, color_point.r, color_point.g, color_point.b);
	return (color_point);
}