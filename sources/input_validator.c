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

int *valid_color(char *line)
{
    char **rgb_color;
    int  *rgb;
    int   i;

	if (line[1] != ' ')
	{
		printf("missing space: %s\n", line);
		return (NULL);
	}
    rgb_color = split_and_trim(line + 1);
    if (!rgb_color)
        return (NULL);
    rgb = malloc(sizeof(int) * 3);
    if (!rgb)
    {
        free_array(rgb_color);
        return (NULL);
    }
    i = 0;
    while (rgb_color[i])
    {
        if (!is_valid_number(rgb_color[i]))
        {
            printf("Error: invalid RGB component -> *%s*\n", rgb_color[i]);
			free_array(rgb_color);
            free(rgb);
            return (NULL);
        }
        rgb[i] = ft_atoi(rgb_color[i]);
        if (rgb[i] < 0 || rgb[i] > 255)
        {
            printf("Error: RGB out of range -> %d\n", rgb[i]);
            free_array(rgb_color);
            free(rgb);
            return (NULL);
        }
        i++;
    }
    if (i != 3)
    {
        printf("Error: wrong number of RGB components\n");
        free_array(rgb_color);
        free(rgb);
        return (NULL);
    }
    free_array(rgb_color); // free strings + array
    return (rgb);          // return parsed {R, G, B}
}


void input_collors(char *line, t_input *data)
{
	int *rgb_color;

	rgb_color = valid_color(line);
	if (rgb_color == NULL)
		return ;
	//think of a way that this returns stops the process to continue, maybe use a int returning 0 in case it worked and 1 in case it didn't work?
	if (line[0] == 'C')
	{
		data->celling.r = rgb_color[0];
		printf("after atoi %d\n", data->celling.r);
		data->celling.g = rgb_color[1];
		printf("after atoi %d\n", data->celling.g);
		data->celling.bx = rgb_color[2];
		printf("after atoi %d\n", data->celling.bx);
		data->has_celling_color = true;
	}
	else
	{
		data->floor.r = rgb_color[0];
		printf("after atoi %d\n", data->floor.r);
		data->floor.g = rgb_color[1];
		printf("after atoi %d\n", data->floor.g);
		data->floor.bx = rgb_color[2];
		printf("after atoi %d\n", data->floor.bx);
		data->has_floor_color = true;
	}
}

void	input_textures(char *line, t_input *data)
{
	char	*texture;

	if (!ft_isalpha(line[1]) || line[2] != ' ')
	{
		printf("Invalid texture path\n");
		return ; //in this case it is invalid;
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
		return ;
	}
}

void	input_colors_and_textures(char *line, t_input *data)
{
	if (line[0] == 'C' || line[0] == 'F')
	{
		input_collors(line, data);
			//pensar numa checagem para ver se a funcao input color nao retornou sem preencher os valores
	}
	else
	{
		input_textures(line, data);
			//getting textures
	}
}
