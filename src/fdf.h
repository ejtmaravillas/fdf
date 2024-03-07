/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:06:04 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/13 19:43:29 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../mlx/mlx.h"

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 500

typedef struct s_map_point
{
	float	x;
	float	y;
	float	z;
}	t_map_point;

typedef struct s_map_data
{
	int		**data_map;
	char	***color_map;
	int		row;
	int		col;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map_point	**point_map;
	float	theta_x;
	float	theta_y;
	float	theta_z;
	float	max_x;
	float	max_y;
	float	max_z;
	float	min_x;
	float	min_y;
	float	min_z;
	float	grid_scale;
}	t_map_data;

// INITIALIZE MATRIX
void	map_data(t_map_data *data, int argc, char **argv);
void	ft_check_args(int argc, char **argv);
void	set_values(t_map_data *data);
void	ft_matrix_fill(t_map_data *data, int index, char **argv);
int		ft_argv_len(char **argv);
void	data_init(t_map_data *data, char *argv);
void	matrix_get_size(t_map_data *data, char *argv);
void	matrix_init(t_map_data *data, int fd);
void	check_fd(char *argv);
void	free_dpointer(char **pointer, void *str, int d);
void	free_matrixdata(t_map_data *data);
int		get_fd(char *argv);
void	error(char **split_str, char *nextline, int d);
void    map_points(t_map_data *data);
t_map_point    set_coordinate(float x, float y, float z);
// INITIALIZE MATRIX

// MLX
void	img_mlx_pixel_put(t_map_data *data, int x, int y, int color);

//rotation
void    get_rotationpoints(t_map_point *a, t_map_data *data);
void	rotation_x(t_map_point *a, t_map_data *data);
void	rotation_y(t_map_point *a, t_map_data *data);
void	rotation_z(t_map_point *a, t_map_data *data);
#endif