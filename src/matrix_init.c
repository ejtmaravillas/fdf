/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:56:56 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/13 16:44:04 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_data(t_map_data *data, int argc, char **argv)
{
	ft_check_args(argc, argv);
	matrix_get_size(data, argv[1]);
	data_init(data, argv[1]);
	map_points(data);
}

void	data_init(t_map_data *data, char *argv)
{
	int		index;
	char	*singleline;
	char	**split_str;
	int		fd;

	set_values(data);
	index = 0;
	fd = get_fd(argv);
	while (1)
	{
		singleline = get_next_line(fd);
		if (!singleline)
		{
			free(singleline);
			break ;
		}
		split_str = ft_split(singleline, ' ');
		ft_matrix_fill(data, index, split_str);
		free_dpointer(split_str, singleline, 0);
		index++;
	}
}

void	set_values(t_map_data *data)
{
	data->theta_x = 0.523599;
	data->theta_y = 0.523599;
	data->theta_z = 0;
	data->max_x = 0;
	data->max_y = 0;
	data->max_z = 0;
	data->min_x = 0;
	data->min_y = 0;
	data->min_z = 0;
	data->grid_scale = 1;
}
void	matrix_get_size(t_map_data *data, char *argv)
{
	char	*singleline;
	char	**split_str;
	int		fd;

	data->row = 0;
	data->col = 0;
	fd = get_fd(argv);
	while (1)
	{
		singleline = get_next_line(fd);
		if (!singleline)
			break ;
		split_str = ft_split(singleline, ' ');
		if (data->col != ft_argv_len(split_str) && data->row > 0)
			error(split_str, singleline, 1);
		data->col = ft_argv_len(split_str);
		free_dpointer(split_str, singleline, 0);
		data->row++;
	}
	matrix_init(data, fd);
}

void	matrix_init(t_map_data *data, int fd)
{
	int	i;

	data->data_map = (int **)malloc(data->row * sizeof(int *));
	data->color_map = (char ***)malloc((data->row + 1) * sizeof(char **));
	printf("row: %d || col: %d\n", data->row, data->col);
	close(fd);
	i = 0;
	while (i < data->row)
	{
		data->data_map[i] = (int *)malloc(data->col * sizeof(int));
		data->color_map[i] = (char **)malloc((data->col + 1) * sizeof(char *));
		ft_memset(data->data_map[i], 0, sizeof(int) * data->col);
		ft_memset(data->color_map[i], 0, sizeof(char *) * (data->col + 1));
		i++;
	}
	data->color_map[i] = NULL;
	ft_putendl_fd("Matrix Initialized...", 1);
}
