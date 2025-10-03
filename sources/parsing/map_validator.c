/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:34:46 by natalia           #+#    #+#             */
/*   Updated: 2025/10/03 11:56:37 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

bool	has_map_started(t_data *data)
{
	if (data->no_texture != NULL && data->so_texture != NULL
		&& data->ea_texture != NULL && data->we_texture != NULL
		&& data->has_celling_color != false && data->has_floor_color != false
		&& data->has_map_started == false)
	{
		data->map_starts = data->total_lines;
		return (true);
	}
	return (false);
}

int	flood_fill(char **map, int r, int x, int y, int total_lines)
{
	if (!map[x])
		return (1);
	if (ft_strlen(map[x]) == 0)
		return (1);
	if (map[x][y] && (map[x][y] == '1' || map[x][y] == '2'))
		return (0);
	if ((x > total_lines - 1 || x <= 0)
		|| (y >= (int)ft_strlen(map[x]) || y <= 0))
		return (1);
	if (map[x][y] == ' ')
		return (1);
	if (map[x][y] != '1' && map[x][y] != '2' && map[x][y] != '0'
		&& !is_player(map[x][y]))
		return (1);
	map[x][y] = '2';
	r += flood_fill(map, r, x, y + 1, total_lines);
	r += flood_fill(map, r, x, y - 1, total_lines);
	r += flood_fill(map, r, x + 1, y, total_lines);
	r += flood_fill(map, r, x - 1, y, total_lines);
	return (r);
}
