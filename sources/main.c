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
bool	is_map_valid(t_input *data)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	printf("tot_lines: %d\n", data->total_lines);
	//validation for first and last line
	while (data->map[i] != NULL)
	{
		if (i == 0 || i == data->total_lines - 1)
		{
			while (data->map[i][x] ==' ')
				x++;
			while (data->map[i][x] != '\n')
			{
				if (data->map[i][x] != '1')
				{
					printf("Invalid map - not surronded by walls\n");
					return (NULL);
				}
				x++;
			}
		}
		else
		{
			while (data->map[i][x] != '\n')
				x++;
			if (data->map[i][x] != '1' || data->map[i][x] != '1')
			{
				printf("Invalid map - not surronded by walls\n");
				return (NULL);
			}
		}
	}
	return (true);
}

int	find_the_longest_line(t_input *data)
{
	int	i;
	int	x;
	int	longest_line;

	i = 0;
	longest_line = 0;
	while (data->map[i] != NULL)
	{
		x = 0;
		while (data->map[i][x] != '\0')
			x++;
		if (x > longest_line)
			longest_line = x;
		i++;
	}
	return (longest_line);
}

// bool	is_map_valid(char *line, int i, int tot_lines)
// {
// 	int	x;

// 	x = 0;
// 	printf("i: %d\n", i);
// 	printf("tot_lines: %d\n", tot_lines);
// 	//validation for first and last line
// 	if (i == 0 || i == tot_lines - 1)
// 	{
// 		while (line[x] ==' ')
// 		x++;
// 		while (line[x] != '\n')
// 		{
// 			if (line[x] != '1')
// 			{
// 				printf("Invalid map - not surronded by walls\n");
// 				return (NULL);
// 			}
// 			x++;
// 		}
// 	}
// 	else
// 	{
// 		while (line[x] != '\n')
// 			x++;
// 		if (line[0] != '1' || line[x-1] != '1')
// 		{
// 			printf("Invalid map - not surronded by walls\n");
// 			return (NULL);
// 		}
// 	}
// 	return (true);
// }

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

// int flood_fill(t_input *data, int y, int x)
// {
//     // out of bounds (top, bottom, left, right)
//     if (y < 0 || y >= data->total_lines)
//         return (1);
//     if (x < 0 || x >= (int)ft_strlen(data->map[y]))
//         return (1);

//     char c = data->map[y][x];

//     // leak if we reach space
//     if (c == ' ')
//         return (1);

//     // stop if we hit wall or already visited
//     if (c == '1' || c == '2')
//         return (0);

//     // valid floor/player
//     if (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
//         return (1); // invalid char

//     // mark visited
//     data->map[y][x] = '2';

//     // flood in 4 directions
//     if (flood_fill(data, y, x + 1)) return (1);
//     if (flood_fill(data, y, x - 1)) return (1);
//     if (flood_fill(data, y + 1, x)) return (1);
//     if (flood_fill(data, y - 1, x)) return (1);

//     return (0);
// }


int	flood_fill(t_input *data, int r, int x, int y)
{
	// printf("--%s--\n", data->map[x]);
	if (data->map[0] && ft_strchr(data->map[0], '0'))
		return (1);
	if (!data->map[x])
		return (1);
	if (ft_strlen(data->map[x]) == 0)
		return (1);
	if (data->map[x][y] && (data->map[x][y] == '1' \
		|| data->map[x][y] == '2'))
		return (0);
	if ((x > data->total_lines - 1 || x < 0)
		|| (y > (int)ft_strlen(data->map[x]) || y < 0))
		return (1);
	if (data->map[x][y] == ' ')
    	return (1); // leak: reached empty space
	if (data->map[x][y] != '1' && data->map[x][y] != '2' && data->map[x][y] != '0'
 	   && data->map[x][y] != 'N' && data->map[x][y] != 'S'
 	   && data->map[x][y] != 'E' && data->map[x][y] != 'W')
 	   return (1); // invalid character

	data->map[x][y] = '2';
	r += flood_fill(data, r, x, y + 1);
	r += flood_fill(data, r, x, y - 1);
	r += flood_fill(data, r, x + 1, y);
	r += flood_fill(data, r, x - 1, y);
	return (r);
}

/*
* If the function needs to return the player posistion, it can be renamed to
* find_player_postion, if the position is on set in `data` on this function,
* init_player_position or fill_player_position are valid alternatives.
*/
void	init_player_position(t_input *data)
{
	int	x;
	int	y;
	bool is_player_found = 0;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		while(data->map[x][y])
		{
			if (data->map[x][y] == 'N')
			{
				is_player_found = 1;
				break;
			}
			y++;
		}
		if (is_player_found)
			break;
		x++;
	}
	printf("Player position is x: %d and y:%d", x, y);
}

int main(int argc, char **argv)
{
	t_input	data;

	check_args(argc, argv);//I am using exit to leave the program
	instantiate_data(&data); //nothing to fail
	init_attributes(&data, argv[1]);
	init_map(&data, argv[1]);
	init_player_position(&data); //implement the player position inside
									//the structure. I think the best will
									//be havind a player struct that is
									//linked inside the data struct
	if (check_map_char(&data) == 1)
	{
		//make free and etc.
		return (1);
	}
	printf("Longest line: %d\n", find_the_longest_line(&data));
	printf("flood fill: %d\n", flood_fill(&data,0, 3, 4));
	int i = 0;
	while ((&data)->map[i] != NULL)
	{
		printf("%s\n", (&data)->map[i]);
		i++;
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
