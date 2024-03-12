/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:00:52 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/13 16:44:17 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_check_args(int argc, char **argv)
{
	char	*extnsn;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments...", 2);
		exit(EXIT_FAILURE);
	}
	extnsn = ft_strchr_gnl(argv[1] + 1, '.');
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
	int		fd;

	fd = get_fd(argv);
	if (fd < 0)
	{
		ft_printf("File %s can not be found.\n", argv);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int	ft_argv_len(char **argv)
{
	int	count;

	count = 0;
	while (argv[count] != NULL)
	{
		count++;
		if (argv[count] != NULL && ft_strncmp(argv[count], "\n", 1) && (ft_strchr(argv[count], '\n')))
		{
			count++;
			break ;
		}
		if (argv[count] != NULL && ft_strchr(argv[count], '\n'))
			break ;
	}
	return (count);
}
