#include "../includes/cub3D.h"

#include <fcntl.h>   // open
#include <unistd.h>  // close
#include <stdio.h>   // printf
#include <stdlib.h>  // free

void initialize_data(t_input *input)
{
	input->map=NULL;
	input->no_texture = NULL;
	input->so_texture = NULL;
	input->ea_texture = NULL;
	input->we_texture = NULL;
	input->has_celling_color = false;
	input->has_floor_color = false;
	input->has_map_started = false;
	input->total_lines = 0;
}

int	check_map_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' || map[i][j] != '1'
				|| map[i][j] != 'N' || map[i][j] != 'S'
				|| map[i][j] != 'E' || map[i][j] != 'W')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
char	*validate_map(char *line, int i, int tot_lines)
{
	//implemente validation;
	printf("i: %d\n", i);
	printf("tot_lines: %d\n", tot_lines);
	return (line);
}

void	input_map(t_input *data, char *arg)
{
	char	*line;
	char	*new_line;
	int		i;
	int		x;
	int		map_lenth;

	i = 0;
	x = 0;
	map_lenth = data->total_lines - data->map_starts;
	data->map = malloc(sizeof(char *) * map_lenth + 1);
	//check if malloc worked
	data->map[map_lenth] = NULL;
	data->fd = open(arg, O_RDONLY);
 	while ((line = get_next_line(data->fd)) != NULL)
	{
		if (i < data->map_starts)
			i++;
		else
		{
			new_line = validate_map(line, x, map_lenth);
			x++;
			data->map[x] = new_line;
			printf("data->map: %s\n", data->map[x]);
		}
	}
	close(data->fd);
}

void	input_data(t_input *data, char *arg)
{
	char	*line;

    data->fd = open(arg, O_RDONLY);
    if (data->fd < 0)
    {
        perror("Failure to open file");
        return;
    }
    while ((line = get_next_line(data->fd)) != NULL)
    {
		// printf("%s", line);
		// printf("line: %d\n", i);
		if (line[0] == '\n')
		{
			data->total_lines++;
		}
		else
		{
			if (ft_isalpha(line[0]))
			{
				input_colors_and_textures(line, data);
			}
			else if (data->no_texture != NULL && data->so_texture != NULL
				&& data->ea_texture != NULL && data->we_texture != NULL
				&& data->has_celling_color != false && data->has_floor_color != false
				&& data->has_map_started == false)
			{
				data->map_starts = data->total_lines;
				data->has_map_started = true;
			}
			data->total_lines++;
		}
		free(line);  // very important: free the allocated memory from get_next_line
	}
    close(data->fd);
}


int main(int argc, char **argv)
{
	t_input	data;
	//Check if I receive the necessary args and if name is correct
	check_args(argc, argv);
	initialize_data(&data);
	input_data(&data, argv[1]);
	input_map(&data, argv[1]);

	//I think the best would be validade de .cub file before save it inside the struct
	//Validade arg
		//argv should have a file that contains:
			//NO texture
			//SO texture
			//WE texture
			//EA texture
			//Floor color
			//Celling color
			//map
		//Is map valid
			//Has only the allowed characters (0, 1, N, S, E, W)?
			//Is it surronded by walls?
			//Spaces are a valid part of the map

	return (0);
}
