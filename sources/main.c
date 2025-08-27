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

// void	input_map(char *line, t_input *data)
// {
// 	int	i;

// 	i = 0;

// }

void	input_data(t_input *data, char *arg)
{
	char	*line;
	int		i;

	i = 1;
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
			i++;
		}
		else
		{
			if (ft_isalpha(line[0]))
			{
				input_colors_and_textures(line, data);
			}
			else if (data->no_texture != NULL && data->so_texture != NULL
				&& data->ea_texture != NULL && data->we_texture != NULL
				&& data->has_celling_color != false && data->has_floor_color != false)
			{
				// input_map(line, data);
				// printf("map starts on line: %d\n", i);
				// printf("Map starts\n");
				data->map_starts = i;
				break;
			}
			i++;
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
