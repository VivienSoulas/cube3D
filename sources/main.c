#include "../includes/cub3D.h"

#include <fcntl.h>   // open
#include <unistd.h>  // close
#include <stdio.h>   // printf
#include <stdlib.h>  // free

void instantiate_data(t_input *input)
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

int	check_map_char(t_input	*data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'W'
				&& data->map[i][j] != ' ')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
bool	is_map_valid(char *line, int i, int tot_lines)
{
	int	x;

	x = 0;
	printf("i: %d\n", i);
	printf("tot_lines: %d\n", tot_lines);
	//validation for first and last line
	if (i == 0 || i == tot_lines - 1)
	{
		while (line[x] ==' ')
		x++;
		while (line[x] != '\n')
		{
			if (line[x] != '1')
			{
				printf("Invalid map - not surronded by walls\n");
				return (NULL);
			}
			x++;
		}
	}
	else
	{
		while (line[x] != '\n')
			x++;
		if (line[0] != '1' || line[x-1] != '1')
		{
			printf("Invalid map - not surronded by walls\n");
			return (NULL);
		}
	}
	return (true);
}

void	init_map(t_input *data, char *arg)
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
	if (has_fd_opened(data->fd) == false)
		return;
 	while ((line = get_next_line(data->fd)) != NULL)
	{
		if (i < data->map_starts)
			i++;
		else
		{
			new_line = ft_strtrim(line, "\n");
			if (new_line == NULL)
				break ;
			data->map[x] = new_line;
			printf("data->map: %s\n", data->map[x]);
			x++;
		}
	}
	close(data->fd);
}

void	init_attributes(t_input *data, char *arg)
{
	char	*line;

    data->fd = open(arg, O_RDONLY);
    if (has_fd_opened(data->fd) == false)
		ft_exit(1, NULL);
    while ((line = get_next_line(data->fd)) != NULL)
    {
		if (line[0] == '\n')
			data->total_lines++;
		else
		{
			if (ft_isalpha(line[0]))
				input_colors_and_textures(line, data);
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

	check_args(argc, argv);//I am using exit to leave the program
	instantiate_data(&data); //nothing to fail
	init_attributes(&data, argv[1]);
	init_map(&data, argv[1]);
	if (check_map_char(&data) == 1)
	{
		//make free and etc.
		return (1);
	}

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
