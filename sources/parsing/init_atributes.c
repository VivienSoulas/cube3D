/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:55:16 by natalia           #+#    #+#             */
/*   Updated: 2025/09/18 15:11:34 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool are_collors_initialized(char *line, t_data *data)
{
	int	*rgb;

	rgb = get_color_input(line);
	if (rgb == NULL)
		return (false);
	if (line[0] == 'C')
	{
		data->celling.r = rgb[0];
		data->celling.g = rgb[1];
		data->celling.b = rgb[2];
		data->has_celling_color = true;
		printf("after atoi R: %d G: %d B: %d\n", data->celling.r, data->celling.g, data->celling.b);//TODO remove this print
	}
	else
	{
		data->floor.r = rgb[0];
		data->floor.g = rgb[1];
		data->floor.b = rgb[2];
		data->has_floor_color = true;
		printf("after atoi R: %d G: %d B: %d\n", data->floor.r, data->floor.g, data->floor.b);//TODO remove this print
	}
	free(rgb);
	return (true);
}

bool	is_no_texture_initialized(t_data *data, char *texture) //TODO: think in a way to make this funtion generic to all functions
{
	if (data->no_texture == NULL)
	{
		data->no_texture = ft_strdup(texture);
		if (data->no_texture == NULL)
		{
			printf("Error: Failure on parsing texture\n");
			return (false);
		}
	}
	else
	{
		printf("Error: has double no_texture\n");
		return (false);
	}
	return (true);
}

bool	are_textures_initialized(char *line, t_data *data) //TODO keep working on double textures
{
	char	*texture;
	bool	return_value = true;

	// if (!ft_isalpha(line[1]) || line[2] != ' ') //TODO: check if this if is really necessary
	// {
	// 	printf("Invalid texture path\n");
	// 	return (false);
	// }
	texture = ft_strtrim(line + 2, " \n\t");
	if (!texture)
		return (false);
	printf("texture: *%s*\n", texture);
	if (*texture == '\0')
		return (printf("Error:empty texture: %s", line), free(texture), false);
	if (line[0] == 'N' && line[1] == 'O')
		return_value = is_no_texture_initialized(data, texture);
	else if (line[0] == 'S' && line[1] == 'O')
		data->so_texture = ft_strdup(texture);
	else if (line[0] == 'W' && line[1] == 'E')
		data->we_texture = ft_strdup(texture);
	else if (line[0] == 'E' && line[1] == 'A')
		data->ea_texture = ft_strdup(texture);
	else
	{
		printf("Invalid texture path\n");
		free(texture);
		return (false);
	}
	free(texture);
	return (return_value);
}

bool	are_attributes_initialized(char *line, t_data *data)
{
	if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
	{
		if (are_collors_initialized(line, data) == false)
			return (false);
	}
	else if (line[2] == ' ')
	{
		if (are_textures_initialized(line, data) == false)
			return (false);
	}
	else
	{
		printf("missing space: %s\n", line);
		return (false);
	}
	return (true);
}

int	init_attributes(t_data *data, char *arg)
{
	char	*line;

	data->fd = open(arg, O_RDONLY);
	if (has_fd_opened(data->fd) == false)
		return (1);  // Failed to open file
	while ((line = get_next_line(data->fd)) != NULL)
	{
		if (line[0] == '\n')
			data->total_lines++;
		else
		{
			if (ft_isalpha(line[0]))
			{
				if (are_attributes_initialized(line, data) == false)
				{
					free(line);
					close(data->fd);
					return (1);  // Failed to parse attributes
				}
			}
			else if (has_map_started(data))
				data->has_map_started = true;
			data->total_lines++;
		}
		free(line);
	}
	if (!data->no_texture || !data->so_texture
		|| data->we_texture || data->ea_texture)
		printf("Error: missing texture\n");
	close(data->fd);
	return (0);
}
