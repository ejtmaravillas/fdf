/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:00:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/13 18:26:35 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_matrix_fill(t_map_data *data, int index, char **argv)
{
	int		col;
	int		len;
	size_t	strlen;
	char	*comma;

	col = 0;
	len = ft_argv_len(argv);
	while (argv[col] != NULL && index < len)
	{
		strlen = 0;
		if (!ft_strncmp(argv[col], "\n", 1))
			break ;
		data->data_map[index][col] = ft_atoi(argv[col]);
		comma = ft_strchr(argv[col], ',');
		if (comma++)
		{
			strlen = ft_strlen(comma);
			if (ft_strchr(comma, '\n'))
				strlen = ft_strlen(comma) - 1;
			data->color_map[index][col] = malloc(sizeof(char) * (strlen + 1));
			data->color_map[index][col][strlen] = '\0';
			ft_strlcpy(data->color_map[index][col], comma, strlen + 1);
		}
		col++;
	}
}

int	get_fd(char *argv)
{
	char	*filedirectory;
	int		fd;

	filedirectory = argv;
	fd = open(filedirectory, O_RDONLY);
	return (fd);
}

void	error(char **split_str, char *nextline, int d)
{
	if (split_str && nextline)
		free_dpointer(split_str, nextline, d);
	else if (!split_str && nextline)
		free(nextline);
	else if (split_str && !nextline)
		free(split_str);
	exit(EXIT_FAILURE);
}

void	free_matrixdata(t_map_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->row)
	{
		col = 0;
		while (col < data->col)
		{
			free(data->color_map[row][col]);
			// free(data->data_map[row][col]);
			col++;
		}
		free(data->data_map[row]);
		free(data->color_point[row]);
		free(data->color_map[row]);
		free(data->point_map[row]);
		row++;
	}
	free(data->data_map);
	free(data->color_map);
	free(data->color_point);
	free(data->point_map);
}
