/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/28 09:29:09 by natalia       #+#    #+#                 */
/*   Updated: 2025/09/09 13:47:29 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

bool	has_fd_opened(int	fd)
{
	if (fd < 0)
	{
		perror("Failure to open file\n");
		return (false);
	}
	return (true);
}

void	ft_exit(int	exit_code, char *line, t_data *data, char *msg)
{
	if (line != NULL)
		free(line);
	if (data->fd)
		close(data->fd);
	if (data->map != NULL)
	{
		free_array(data->map);
	}
	if (msg != NULL)
		printf("%s\n", msg);
	exit(exit_code);
}

void free_array(char **array)
{
	int i = 0;

	if (!array)
		return;
	while (array[i] )
	{
		free(array[i]);
		i++;
	}
	free(array);
}
