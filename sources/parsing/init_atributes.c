/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:55:16 by natalia           #+#    #+#             */
/*   Updated: 2025/10/03 11:54:42 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	parse_colors(char *line, t_data *data)
{
	int	*rgb;

	rgb = get_color_input(line);
	if (rgb == NULL)
		return (false);
	if (line[0] == 'C' && data->celling.r == -1
		&& data->celling.g == -1 && data->celling.b == -1)
	{
		data->celling.r = rgb[0];
		data->celling.g = rgb[1];
		data->celling.b = rgb[2];
		data->has_celling_color = true;
	}
	else if (line[0] == 'F')
	{
		data->floor.r = rgb[0];
		data->floor.g = rgb[1];
		data->floor.b = rgb[2];
		data->has_floor_color = true;
	}
	else
		return (printf("Error: Has double color\n"), false);
	free(rgb);
	return (true);
}

char	*init_texture(char *data, char *texture)
{
	char	*result;

	if (data == NULL)
	{
		result = ft_strdup(texture);
		if (result == NULL)
		{
			printf("Error: Failure on parsing texture\n");
			return (NULL);
		}
	}
	else
	{
		printf("Error: has double no_texture\n");
		return (NULL);
	}
	return (result);
}

bool	parse_textures(char *line, t_data *data)
{
	char	*texture;
	char	*result;

	if (!ft_isalpha(line[1]) || line[2] != ' ')
		return (printf("Error: Invalid texture path\n"), false);
	texture = ft_strtrim(line + 2, " \n\t");
	if (!texture)
		return (printf("Error: Failure in init textures\n"), false);
	if (*texture == '\0')
	{
		printf("Error: Empty texture: %s", line);
		return (free(texture), false);
	}
	result = NULL;
	if (line[0] == 'N' && line[1] == 'O')
		result = (data->no_texture = init_texture(data->no_texture, texture));
	else if (line[0] == 'S' && line[1] == 'O')
		result = (data->so_texture = init_texture(data->so_texture, texture));
	else if (line[0] == 'W' && line[1] == 'E')
		result = (data->we_texture = init_texture(data->we_texture, texture));
	else if (line[0] == 'E' && line[1] == 'A')
		result = (data->ea_texture = init_texture(data->ea_texture, texture));
	else
		printf("Invalid texture path\n");
	return (free(texture), (result != NULL));
}

bool	parse_atribute_line(char *line, t_data *data)
{
	if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
	{
		if (parse_colors(line, data) == false)
			return (false);
	}
	else if (line[0] == 'N' || line[0] == 'S'
		|| line[0] == 'E' || line[0] == 'W')
	{
		if (parse_textures(line, data) == false)
			return (false);
	}
	else
	{
		printf("Error: extra line found: %s\n", line);
		return (false);
	}
	return (true);
}

bool	parse_attributes(t_data *data, char *arg)
{
	char	*line;

	data->fd = open(arg, O_RDONLY);
	if (has_fd_opened(data->fd) == false)
		return (false);
	line = get_next_line(data->fd);
	while (line != NULL)
	{
		if (line[0] == '\n')
			data->total_lines++;
		else
		{
			if (ft_isalpha(line[0]))
			{
				if (parse_atribute_line(line, data) == false)
					return (free(line), close(data->fd), false);
			}
			else if (has_map_started(data))
				data->has_map_started = true;
			data->total_lines++;
		}
		free(line);
		line = get_next_line(data->fd);
	}
	if (!are_attributes_initialized(data))
		return (false);
	return (close(data->fd), true);
}
