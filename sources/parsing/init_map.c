/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/30 13:51:50 by natalia       #+#    #+#                 */
/*   Updated: 2025/10/24 10:52:19 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*check_and_dup_line(char *line)
{
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (ft_strdup(line));
}

void	set_map(t_data *data, int index_line)
{
	char	*line;
	int		index_map;

	index_map = 0;
	line = get_next_line(data->fd);
	while (line != NULL)
	{
		if (index_line++ >= data->map_starts)
		{
			data->map[index_map] = check_and_dup_line(line);
			if (data->map[index_map] == NULL)
			{
				free(line);
				close(data->fd);
				while (--index_map >= 0)
					free(data->map[index_map]);
				free(data->map);
				data->map = NULL;
			}
			index_map++;
		}
		free(line);
		line = get_next_line(data->fd);
	}
}

bool	init_map(t_data *data, char *arg)
{
	data->fd = open(arg, O_RDONLY);
	if (has_fd_opened(data->fd) == false)
		return (false);
	data->map = ft_calloc(sizeof(char *),
			((data->total_lines - data->map_starts) + 1));
	if (data->map == NULL)
	{
		printf("Error: Failure (malloc) on init_map\n");
		return (false);
	}
	set_map(data, 0);
	if (data->map == NULL)
	{
		printf("Error: Failure (malloc) on init_map\n");
		return (false);
	}
	close(data->fd);
	return (true);
}
