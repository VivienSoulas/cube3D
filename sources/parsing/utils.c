/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/01 09:19:01 by natalia       #+#    #+#                 */
/*   Updated: 2025/09/10 15:03:37 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

char	**copy_map(t_data	*data)
{
	char	**new_map;
	int		i;

	// printf("total line: %d\n", (data->total_lines - data->map_starts));
	new_map = ft_calloc(sizeof(char *), (data->total_lines - data->map_starts + 1));
	if (new_map == NULL)
		return (NULL);
	i = 0;
	while (i < (data->total_lines - data->map_starts))
	{
		new_map[i] = ft_strdup(data->map[i]);
		if (new_map[i] == NULL)
		{
			// Free already allocated strings
			while (--i >= 0)
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	return (new_map);
}
