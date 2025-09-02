#include "../includes/cub3D.h"

 //check colors
 //check walls

int	is_valid_number(char *str)
{
	int i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);

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

char **split_and_trim(char *line)
{
	char	**rgb_color;
	char	*temp;
	int		i;

	i = 0;
	rgb_color = ft_split(line, ',');
	if (!rgb_color)
		return (NULL);
	while (rgb_color[i] != NULL)
	{
		temp = ft_strtrim(rgb_color[i], " \n");
		if (temp == NULL)
			return (free_array(rgb_color), NULL);
		free (rgb_color[i]);
		rgb_color[i] = ft_strdup(temp);
		if (temp == NULL)
			return (free_array(rgb_color), NULL);
		free(temp);
		i++;
	}
	return (rgb_color);
}

bool	is_valid_color(char	**rgb_color)
{
	int	i;
	int	rgb;

	i = 0;
	while (rgb_color[i])
	{
		if (!is_valid_number(rgb_color[i]))
		{
			printf("Error: invalid RGB component -> *%s*\n", rgb_color[i]);
			return (false);
		}
		rgb = ft_atoi(rgb_color[i]);
		if (rgb < 0 || rgb > 255)
		{
			printf("Error: RGB out of range -> %d\n", rgb);
			return (false);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: wrong number of RGB components\n");
		return (false);
	}
	return (true);
}

int *get_color_input(char *line)
{
	char	**rgb_color;
	int		*rgb;
	int		i;

	i = 0;
	rgb = 0;
	rgb_color = split_and_trim(line + 1);
	if (!rgb_color)
		return (printf ("Error on parsing collors\n"), NULL);
	if (is_valid_color(rgb_color))
	{
		rgb = ft_calloc(sizeof(int), 3);
		if (!rgb)
			return (free_array(rgb_color), NULL);
		while (rgb_color[i])
		{
			rgb[i] = ft_atoi(rgb_color[i]);
			i++;
		}
	}
	else
		return (free_array(rgb_color), NULL);
	return (free_array(rgb_color), rgb);
}
bool are_collors_initialized(char *line, t_data *data)
{
	int 	*rgb;

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
