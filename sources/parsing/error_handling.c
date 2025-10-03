/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:29:09 by natalia           #+#    #+#             */
/*   Updated: 2025/10/03 10:16:50 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	has_fd_opened(int fd)
{
	if (fd < 0)
	{
		perror("Failure to open file\n");
		return (false);
	}
	return (true);
}

int	ft_exit_parsing(int exit_code, char *line, t_data *data, char *msg)
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
		printf("Error\n%s\n", msg);
	return (exit_code);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
