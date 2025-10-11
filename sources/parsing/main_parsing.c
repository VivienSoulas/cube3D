/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:08:02 by nmedeiro          #+#    #+#             */
/*   Updated: 2025/10/10 10:11:28 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_data_structure(t_data *data)
{
	if (data->no_texture)
		free(data->no_texture);
	if (data->so_texture)
		free(data->so_texture);
	if (data->we_texture)
		free(data->we_texture);
	if (data->ea_texture)
		free(data->ea_texture);
	if (data->file_name)
		free(data->file_name);
	if (data->map)
		free_array(data->map);
	if (data->fd > 0)
		close(data->fd);
	free(data);
}

t_data	*ft_parse(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	if (!check_args(ac, av))
		return (free(data), NULL);
	instantiate_data(data);
	if (!parse_data(data, av[1]))
	{
		clean_data_structure(data);
		return (NULL);
	}
	return (data);
}
