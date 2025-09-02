/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 11:16:33 by natalia       #+#    #+#                 */
/*   Updated: 2025/09/02 12:25:50 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"
int	check_map_char(t_data	*data)
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
bool	is_map_valid(t_data *data)
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

int	find_the_longest_line(t_data *data)
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

void	init_map(t_data *data, char *arg)
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

bool	has_map_started(t_data *data)
{
	if (data->no_texture != NULL && data->so_texture != NULL
		&& data->ea_texture != NULL && data->we_texture != NULL
		&& data->has_celling_color != false && data->has_floor_color != false
		&& data->has_map_started == false)
	{
		data->map_starts = data->total_lines;
		return (true);
	}
	return (false);
}

void	init_attributes(t_data *data, char *arg)
{
	char	*line;

	data->fd = open(arg, O_RDONLY);
	if (has_fd_opened(data->fd) == false)
		ft_exit(1, NULL); //check if exit will work well or should I change to return and make init atributes a bool
	while ((line = get_next_line(data->fd)) != NULL)
	{
		if (line[0] == '\n')
			data->total_lines++;
		else
		{
			if (ft_isalpha(line[0]))
			{
				if(is_attributes_inputed(line, data) == false)
				{
					// free(line);
					close(data->fd);
					ft_exit(1, line);
					// return ;
				}
			}
			else if (has_map_started(data))
				data->has_map_started = true;
			data->total_lines++;
		}
		free(line);
	}
	close(data->fd);
}

int	flood_fill(char **map, int r, int x, int y, int	total_lines)
{
	// printf("--%s--\n", data->map[x]);
	if (map[0] && ft_strchr(map[0], '0'))
		return (1);
	if (!map[x])
		return (1);
	if (ft_strlen(map[x]) == 0)
		return (1);
	if (map[x][y] && (map[x][y] == '1' \
		|| map[x][y] == '2'))
		return (0);
	if ((x > total_lines - 1 || x < 0)
		|| (y > (int)ft_strlen(map[x]) || y < 0))
		return (1);
	if (map[x][y] == ' ')
    	return (1); // leak: reached empty space
	if (map[x][y] != '1' && map[x][y] != '2' && map[x][y] != '0'
 	   && map[x][y] != 'N' && map[x][y] != 'S'
 	   && map[x][y] != 'E' && map[x][y] != 'W')
 	   return (1); // invalid character

	map[x][y] = '2';
	r += flood_fill(map, r, x, y + 1, total_lines);
	r += flood_fill(map, r, x, y - 1, total_lines);
	r += flood_fill(map, r, x + 1, y, total_lines);
	r += flood_fill(map, r, x - 1, y, total_lines);
	return (r);
}

bool	is_player(char	c)
{
	return (c == 'N' || c == 'S'|| c == 'W' || c == 'E');
}

/*
* If the function needs to return the player posistion, it can be renamed to
* find_player_postion, if the position is on set in `data` on this function,
* init_player_position or fill_player_position are valid alternatives.
*/
void	init_player_position(t_data *data)
{
	int	x;
	int	y;
	bool is_player_found = 0;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while(data->map[x][y])
		{
			if (is_player(data->map[x][y]))
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
	data->player_x = x;
	data->player_y = y;
	printf("4 Player position: [%d][%d]\n", data->player_x, data->player_y);
}

char	**copy_map(t_data	*data)
{
	char	**new_map;
	int		i;

	printf("total line: %d\n", (data->total_lines - data->map_starts));
	new_map = ft_calloc(sizeof(char *), (data->total_lines - data->map_starts + 1));
	//check faillure
	i = 0;
	while (i < (data->total_lines - data->map_starts))
	{
		new_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	return (new_map);
}
void init_and_validade_data(t_data *data, char *argv)
{
	char **map;

	init_attributes(data, argv);
	init_map(data, argv);
	init_player_position(data);
	if (check_map_char(data) == 1)
	{
		//make free and etc.
		//mudar pra exit
		return ;
	}
	map = copy_map(data);
	// printf("flood fill: %d\n", flood_fill(map, 0, (&data)->player_x, (&data)->player_y, (&data)->total_lines));
	if (flood_fill(map, 0, data->player_x, data->player_y, data->total_lines) != 0)
		printf("invalid map\n");
	print_map(map);
}
