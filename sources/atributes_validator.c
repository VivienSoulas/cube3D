#include "../includes/cub3D.h"

 //check colors
 //check walls

 int is_valid_number(char *str)
{
    int i = 0;

    if (!str || !*str)
		return (0);

    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (0);  // reject if any non-digit (like space, letters, etc.)
		i++;
    }
    return (1);

}

void free_array(char **arr) //free array
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i] )
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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
		{
			free_array(rgb_color);
			printf ("Error on parsing collors\n");
			return (NULL);
		}
		free (rgb_color[i]);
		rgb_color[i] = malloc(sizeof(char) * ft_strlen(temp) + 1);
		if (temp == NULL)
		{
			free_array(rgb_color);
			printf ("Error on parsing collors\n");
			return (NULL);
		}
		ft_strlcpy(rgb_color[i], temp, ft_strlen(temp) + 1);
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

int *valid_color(char *line)
{
    char **rgb_color;
	int	*rgb;
    int   i;

	i = 0;
	rgb = 0;
	// if (line[1] != ' ')
	// {
	// 	printf("missing space: %s\n", line);
	// 	return (NULL);
	// }
    rgb_color = split_and_trim(line + 1);
    if (!rgb_color)
        return (NULL);
	if (is_valid_color(rgb_color))
	{
		rgb = malloc(sizeof(int) * 3);
		if (!rgb)
		{
			free_array(rgb_color);
			return (NULL);
		}
		while (rgb_color[i])
		{
			rgb[i] = ft_atoi(rgb_color[i]);
			i++;
		}
	}
	else
	{
		free_array(rgb_color);
		return (NULL);
	}
    free_array(rgb_color); // free strings + array
    return (rgb);          // return parsed {R, G, B}
}
// bool input_collors(char *line, t_data *data)
// {
// 	int 	*rgb;

// 	if (line[1] != ' ')
// 	{
// 		printf("missing space: %s\n", line);
// 		return (false);
// 	}
// 	rgb = valid_color(line);
// 	if (rgb == NULL)
// 		return (false);
// 	if (line[0] == 'C')
// 	{
// 		data->celling.r = rgb[0];
// 		printf("after atoi %d\n", data->celling.r);
// 		data->celling.g = rgb[1];
// 		printf("after atoi %d\n", data->celling.g);
// 		data->celling.b = rgb[2];
// 		printf("after atoi %d\n", data->celling.bx);
// 		data->has_celling_color = true;
// 	}
// 	else
// 	{
// 		data->floor.r = rgb[0];
// 		printf("after atoi %d\n", data->floor.r);
// 		data->floor.g = rgb[1];
// 		printf("after atoi %d\n", data->floor.g);
// 		data->floor.b = rgb[2];
// 		printf("after atoi %d\n", data->floor.bx);
// 		data->has_floor_color = true;
// 	}
// 	return (true);
// }

bool input_collors(char *line, t_data *data)
{
	int 	*rgb;
	t_colors	*target;

	rgb = valid_color(line);
	if (rgb == NULL)
		return (false);
	if (line[0] == 'C')
	{
		target = &data->celling;
		data->has_celling_color = true;
	}
	else
	{
		target = &data->floor;
		data->has_floor_color = true;
	}
	target->r = rgb[0];
	target->g = rgb[1];
	target->b = rgb[2];
	printf("after atoi R: %d G: %d B: %d\n", target->r, target->g, target->b);
	return (true);
}

void	input_textures(char *line, t_data *data)
{
	char	*texture;

	if (!ft_isalpha(line[1]) || line[2] != ' ')
	{
		printf("Invalid texture path\n");
		ft_exit(1, line);
	}
	texture = ft_strtrim(line + 2, " \n\t");
	printf("texture: *%s*\n", texture);
	if (line[0] == 'N' && line[1] == 'O')
	{
		data->no_texture = texture;
		printf("data->no_texture: *%s*\n", data->no_texture);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		data->so_texture = texture;
		printf("data->so_texture: *%s*\n", data->so_texture);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		data->we_texture = texture;
		printf("data->we_texture: *%s*\n", data->we_texture);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		data->ea_texture = texture;
		printf("data->ea_texture: *%s*\n", data->ea_texture);
	}
	else
	{
		printf("Invalid character\n");
		free(texture);
		ft_exit(1, line);
	}
	free(texture);
}

bool	is_attributes_inputed(char *line, t_data *data)
{
	if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
	{
		if (input_collors(line, data) == false)
			return (false);
			//pensar numa checagem para ver se a funcao input color nao retornou sem preencher os valores
	}
	else if (line[2] == ' ')
	{
		input_textures(line, data);
			//getting textures
	}
	else
	{
		printf("missing space: %s\n", line);
		return (false);
	}
	return (true);
}
