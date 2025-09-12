/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 11:16:33 by natalia       #+#    #+#                 */
/*   Updated: 2025/09/10 15:13:50 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

bool	has_invalid_char(t_data	*data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x] != NULL)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] != '0' && data->map[x][y] != '1'
				&& !is_player(data->map[x][y]) && data->map[x][y] != ' ')
			{
				printf("Invalid char: '%c' on position [%d][%d]\n", data->map[x][y], x, y);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

char	*check_and_dup_line(char *line)
{
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
		return (ft_strdup(line));
}

void	init_map(t_data *data, char *arg) //I need to optimize this function
{
	char	*line;
	int		index_line;
	int		index_map;

	index_line = 0;
	index_map = 0;
	data->map = ft_calloc(sizeof(char *), ((data->total_lines - data->map_starts) + 1));
	if (data->map == NULL)
		return ;
	data->fd = open(arg, O_RDONLY);
	if (has_fd_opened(data->fd) == false)
		return free (data->map);
	while ((line = get_next_line(data->fd)) != NULL)
	{
		// printf("index line: %d\n", index_line);
		if (index_line++ >= data->map_starts)
		{
			data->map[index_map] = check_and_dup_line(line);
			if (data->map[index_map] == NULL)
			{
				free(line);
				break ;
			}
			index_map++;
		}
		free(line);
	}
	close(data->fd);
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
				data->player_x = x;
				data->player_y = y;
				break;
			}
			y++;
		}
		if (is_player_found)
			break;
		x++;
	}
	// printf("4 Player position: [%d][%d]\n", data->player_x, data->player_y);
}

void parse_data(t_data *data, char *argv)
{
	char **map;

	init_attributes(data, argv);
	init_map(data, argv);
	print_map(data->map);
	init_player_position(data);//acho que posso incluir aqui a checagem se tem mais de 1 players
	if (data->player_x == -1 && data->player_y == -1)
		ft_exit(1, NULL, data, "There's no player"); //check if it worked
	if (has_invalid_char(data) == 1) //only the flood fill check is not enought because the number 2
		ft_exit (1, NULL, data, NULL);
	map = copy_map(data);
	if (map == NULL)
		ft_exit(1, NULL, data, "Failure on parsing");
	if (flood_fill(map, data->player_x, data->player_y, (data->total_lines - data->map_starts)) != 0)
	{
		print_map(map);
		free_array(map);
		ft_exit(1, NULL, data, "Invalid map");
	}
	print_map(map);
	free_array(map);
	//Verify if the parse is check if the map has ONLY one player
	//Verify if the parse is check if the map HAS ONE player
}
