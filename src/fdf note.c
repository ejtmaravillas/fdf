#include "fdf.h"

int main(int argc, char **argv)
{
	t_map_data data;
	ft_check_args(argc, argv);
	matrix_get_size(&data, argv[1]);
	data_init(&data, argv[1]);
	ft_printf("data->data_map[7][6]: %d\n", data.data_map[7][6]);
	free_matrixdata(&data);
	return (0);
}

void    data_init(t_map_data *data, char *argv)
{
	int     index;
	char    *singleline;
	char    **split_str;
	int 	fd;
	char	*filedirectory;

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

void    ft_matrix_fill(t_map_data *data, int index, char **argv)
{
	int col;
	int len;

	col = 0;
	len = ft_argv_len(argv);
	while (argv[col] != NULL && index < len)
	{
		if (!ft_strncmp(argv[col], "\n", 1))
			break ;
		data->data_map[index][col] = ft_atoi(argv[col]);
		col++;
	}
}

int		get_fd(char *argv)
{
	char	*filedirectory;
	int fd;

	filedirectory = ft_strjoin("../test_maps/",argv);
	fd = open(filedirectory, O_RDONLY);
	free(filedirectory);
	return (fd);
}

void	matrix_get_size(t_map_data *data, char *argv)
{
	char    *singleline;
	char    **split_str;
	int		fd;
	char	*filedirectory;

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
	int row;
	int col;

	row = 0;
	while (row < data->row)
	{
		free(data->data_map[row]);
		row++;
	}
	free(data->data_map);
}

void	free_dpointer(char **pointer, void *str, int d)
{
	int	count;

	count = 0;
	if (d == 1)
		ft_putendl_fd("Inconsistent column size...", 2);
	while (pointer[count] != NULL)
	{
		free(pointer[count]);
		count++;
	}
	free(pointer);
	pointer = NULL;
	free(str);
	str = NULL;
}

void	matrix_init(t_map_data *data, int fd)
{
	int index;
	int col;

	data->data_map = (int **)malloc(data->row * sizeof(int *));
	printf("row: %d || col: %d\n", data->row, data->col);
	close(fd);
	index = 0;
	while (index < data->row)
	{
		data->data_map[index] = (int *)malloc(data->col * sizeof(int));
		ft_memset(data->data_map[index], 0, sizeof(int) * data->col);
		index++;
	}
	// index = 0;
	// while (index < data->row)
	// {
	// 	col = 0;
	// 	while (col < data->col)
	// 	{
	// 		printf("val[%d][%d]: %d\n", index, col, data->data_map[index][col]);
	// 		col++;
	// 	}
	// 	printf("\n");
	// 	index++;
	// }
	ft_putendl_fd("Matrix Initialized...", 1);
}

void    ft_check_args(int argc, char **argv)
{
	char *extnsn;
	int fd;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments...", 2);
		exit(EXIT_FAILURE);
	}
	extnsn = ft_strchr_gnl(argv[1], '.');
	if (!extnsn)
	{
		ft_putendl_fd("No .fdf extension...", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(extnsn, ".fdf", 4))
	{
		ft_putendl_fd("Wrong extension (no .fdf extension)", 2);
		exit(EXIT_FAILURE);
	}
	check_fd(argv[1]);
}

void	check_fd(char *argv)
{
	int fd;
	char	*filedirectory;

	fd = get_fd(argv);
	if (fd < 0)
	{
		ft_printf("File %s can not be found.\n", argv);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int ft_argv_len(char **argv)
{
	int count;

	count = 0;
	while (argv[count] != NULL)
	{
		count++;
		if (ft_strncmp(argv[count], "\n", 1) && (ft_strchr(argv[count], '\n')))
		{
			count++;
			break ;
		}
		if (ft_strchr(argv[count], '\n'))
			break ;
	}
	return (count);
}