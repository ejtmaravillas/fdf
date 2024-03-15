/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:38:17 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/15 14:39:53 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_scale(int keysym, t_map_data *data)
{
	if (keysym == ZO_COMMAND && data->grid_scale < 150)
		data->grid_scale += 0.5;
	else if (keysym == ZI_COMMAND && data->grid_scale > 1)
		data->grid_scale -= 0.5;
	find_maxmin(data, 1);
}
