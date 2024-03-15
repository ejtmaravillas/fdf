#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include <fcntl.h>

typedef struct s_map_data
{
    char **data_map;
    int row;
    int col;
}   t_map_data;

void    ft_check_args(int argc, char **argv);
void    ft_matrix_fill(t_map_data *data, int index, char **argv);
int     ft_argv_len(char **argv);
void    data_init(t_map_data *data, char *argv);
void	matrix_get_size(t_map_data *data, char *argv);
void	matrix_init(t_map_data *data, int fd);
void	check_fd(char *argv);
void	free_dpointer(char **pointer, void *str, int d);
void	free_matrixdata(t_map_data *data);
int		get_fd(char *argv);
void	error(char **split_str, char *nextline, int d);
#endif