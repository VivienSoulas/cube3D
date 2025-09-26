/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 11:16:33 by natalia       #+#    #+#                 */
/*   Updated: 2025/09/12 14:57:32 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

bool	has_invalid_char(t_data	*data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x] != NULL)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] != '0' && data->map[x][y] != '1'
				&& !is_player(data->map[x][y]) && data->map[x][y] != ' ')
			{
				printf("Invalid char: '%c' on position [%d][%d]\n", data->map[x][y], x, y);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

char	*check_and_dup_line(char *line)
{
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (ft_strdup(line));
}

int	init_map(t_data *data, char *arg) //I need to optimize this function
{
	char	*line;
	int		index_line;
	int		index_map;

	index_line = 0;
	index_map = 0;
	data->map = ft_calloc(sizeof(char *), ((data->total_lines - data->map_starts) + 1));
	if (data->map == NULL)
		return (1);
	data->fd = open(arg, O_RDONLY);
	if (has_fd_opened(data->fd) == false)
	{
		free(data->map);
		data->map = NULL;
		return (1);
	}
	while ((line = get_next_line(data->fd)) != NULL)
	{
		// printf("index line: %d\n", index_line);
		if (index_line++ >= data->map_starts)
		{
			data->map[index_map] = check_and_dup_line(line);
			if (data->map[index_map] == NULL)
			{
				free(line);
				close(data->fd);
				// Free already allocated map lines before breaking
				while (--index_map >= 0)
					free(data->map[index_map]);
				free(data->map);
				data->map = NULL;
				return (1);
			}
			index_map++;
		}
		free(line);
	}
	close(data->fd);
	return (0);
}

/*
* If the function needs to return the player posistion, it can be renamed to
* find_player_postion, if the position is on set in `data` on this function,
* init_player_position or fill_player_position are valid alternatives.
*/
int	init_player_position(t_data *data)
{
	int	x;
	int	y;
	bool is_player_found = 0;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if (is_player(data->map[y][x]))
			{
				if (is_player_found)
					return (1);  // More than 1 player found
				is_player_found = 1;
				data->start_dir = data->map[y][x];
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		if (data->map_width < x)
			data->map_width = x;
		y++;
	}
	data->map_height = y;
	// printf("4 Player position: [%d][%d]\n", data->player_x, data->player_y);
	return (0);
}

int	*find_zero(char **map)
{
	int	i;
	int	j;
	int	*pos;

	i = 0;
	pos = ft_calloc(2, sizeof(int));
	if (pos == NULL)
		return (NULL);
	pos[0] = -1;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				pos[0] = i;
				pos[1] = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return(pos);
}

int	validate_map(t_data *data)
{
	char	**map;
	int		*pos;

	map = copy_map(data);
	if (map == NULL)
		return (1);  // Failure on parsing
	pos = find_zero(map);
	if (pos == NULL)
	{
		free(map);
		return (1);  // Failure on parsing
	}
	while (pos[0] != -1)
	{
		if (flood_fill(map, 0, pos[0], pos[1] , (data->total_lines - data->map_starts)) != 0)
		{
			print_map(map); //TODO Remove this line
			free_array(map);
			free(pos);
			return (1);  // Invalid map
		}
		free(pos);
		pos = find_zero(map);
		if (pos == NULL)  // Check if find_zero failed
		{
			free_array(map);
			return (1);  // Memory allocation failed
		}
	}
	free(pos);
	print_map(map); //TODO Remove this line
	free_array(map);
	return (0);
}

int parse_data(t_data *data, char *argv)
{
	if (init_attributes(data, argv) != 0)
		return (1);
	if (init_map(data, argv) != 0)
		return (1);  // init_map failed
	print_map(data->map);//TODO Remove this line
	if (init_player_position(data) != 0)
		return (1);  // Error in player position (more than 1 player)
	if (data->player_x == -1 && data->player_y == -1)
		return (1);  // No player found
	if (has_invalid_char(data) == 1)
		return (1);  // Invalid characters in map
	if (validate_map(data) != 0)
		return (1);  // Map validation failed
	return (0);
}
