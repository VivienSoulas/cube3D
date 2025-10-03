/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:16:33 by natalia           #+#    #+#             */
/*   Updated: 2025/10/03 10:01:19 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	init_player_position(t_data *data)
{
	int		x;
	int		y;
	bool	is_player_found;

	is_player_found = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (is_player(data->map[y][x]))
			{
				if (is_player_found)
					return (1);
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
	while (map[i])
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
	return (pos);
}

int	validate_map(t_data *data)
{
	char	**map;
	int		*pos;

	map = copy_map(data);
	if (map == NULL)
		return (1);
	pos = find_zero(map);
	if (pos == NULL)
	{
		free(map);
		return (1);
	}
	while (pos[0] != -1)
	{
		if (flood_fill(map, 0, pos[0], pos[1] ,
				(data->total_lines - data->map_starts)) != 0)
		{
			print_map(map);
			free_array(map);
			free(pos);
			return (1);
		}
		free(pos);
		pos = find_zero(map);
		if (pos == NULL)
		{
			free_array(map);
			return (1);
		}
	}
	free(pos);
	free_array(map);
	return (0);
}

bool	parse_data(t_data *data, char *argv)
{
	if (!parse_attributes(data, argv))
		return (false);
	if (!init_map(data, argv))
		return (false);
	if (init_player_position(data) != 0)
		return (false);
	if (data->player_x == -1 && data->player_y == -1)
		return (false);
	if (has_invalid_char(data) == 1)
		return (false);
	if (validate_map(data) != 0)
		return (false);
	return (true);
}
