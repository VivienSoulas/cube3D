/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:34:46 by natalia           #+#    #+#             */
/*   Updated: 2025/10/03 13:19:11 by nmedeiro         ###   ########.fr       */
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

int	flood_fill(t_data *data, int r, int x, int y)
{
	if (!data->copy_map[x])
		return (1);
	if (ft_strlen(data->copy_map[x]) == 0)
		return (1);
	if (data->copy_map[x][y]
		&& (data->copy_map[x][y] == '1' || data->copy_map[x][y] == '2'))
		return (0);
	if ((x > data->map_lines - 1 || x <= 0)
		|| (y >= (int)ft_strlen(data->copy_map[x]) || y <= 0))
		return (1);
	if (data->copy_map[x][y] == ' ')
		return (1);
	if (data->copy_map[x][y] != '1'
		&& data->copy_map[x][y] != '2' && data->copy_map[x][y] != '0'
			&& !is_player(data->copy_map[x][y]))
		return (1);
	data->copy_map[x][y] = '2';
	r += flood_fill(data, r, x, y + 1);
	r += flood_fill(data, r, x, y - 1);
	r += flood_fill(data, r, x + 1, y);
	r += flood_fill(data, r, x - 1, y);
	return (r);
}
