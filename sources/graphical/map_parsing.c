/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:02:29 by vsoulas           #+#    #+#             */
/*   Updated: 2025/07/26 16:15:52 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_map_parsing(int fd, t_cub3D *cub)
{
	(void)fd;
	(void)cub;
	// char	*line;

	// line = get_next_line(fd);
	// while (line != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
}

int	ft_count_lines(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		i++;
	}
	return (i);
}

int	ft_map_validity(t_cub3D *cub)
{
	int	i;
	int	j;
	int	len;
	int	lines;

	lines = ft_count_lines(cub->map->grid);
	if (lines < 3)
		return (1);
	j = 0;
	while (cub->map->grid[0][j])
	{
		if (cub->map->grid[0][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (cub->map->grid[lines - 1][j])
	{
		if (cub->map->grid[lines - 1][j] != '1')
			return (1);
		j++;
	}
	i = 1;
	while (i < lines - 1)
	{
		len = ft_strlen(cub->map->grid[i]);
		if (len < 3 || cub->map->grid[i][0] != '1' || cub->map->grid[i][len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
