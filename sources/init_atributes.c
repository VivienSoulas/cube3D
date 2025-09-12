/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_atributes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/03 10:55:16 by natalia       #+#    #+#                 */
/*   Updated: 2025/09/09 13:50:52 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

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
		printf("after atoi R: %d G: %d B: %d\n", data->celling.r, data->celling.g, data->celling.b);

	}
	else
	{
		data->floor.r = rgb[0];
		data->floor.g = rgb[1];
		data->floor.b = rgb[2];
		data->has_floor_color = true;
		printf("after atoi R: %d G: %d B: %d\n", data->floor.r, data->floor.g, data->floor.b);
	}
	return (true);
}

bool	are_textures_initialized(char *line, t_data *data)
{
	char	*texture;

	if (!ft_isalpha(line[1]) || line[2] != ' ')
	{
		printf("Invalid texture path\n");
		return (false);
	}
	texture = ft_strtrim(line + 2, " \n\t");
	printf("texture: *%s*\n", texture);
	if (line[0] == 'N' && line[1] == 'O')
		data->no_texture = texture;
	else if (line[0] == 'S' && line[1] == 'O')
		data->so_texture = texture;
	else if (line[0] == 'W' && line[1] == 'E')
		data->we_texture = texture;
	else if (line[0] == 'E' && line[1] == 'A')
		data->ea_texture = texture;
	else
	{
		printf("Invalid character\n");
		free(texture);
		return (false);
	}
	free(texture);
	return (true);
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

void	init_attributes(t_data *data, char *arg)
{
	char	*line;

	data->fd = open(arg, O_RDONLY);
	if (has_fd_opened(data->fd) == false)
		ft_exit(1, NULL, data, NULL); //check if exit will work well or should I change to return and make init atributes a bool
	while ((line = get_next_line(data->fd)) != NULL)
	{
		if (line[0] == '\n')
			data->total_lines++;
		else
		{
			if (ft_isalpha(line[0]))
			{
				if(are_attributes_initialized(line, data) == false)
					ft_exit(1, line, data, NULL);//check if close fd inside ft_exit has worked
			}
			else if (has_map_started(data))
				data->has_map_started = true;
			data->total_lines++;
		}
		free(line);
	}
	close(data->fd);
}
