#include "cub3D.h"

#include <fcntl.h>   // open
#include <unistd.h>  // close
#include <stdio.h>   // printf
#include <stdlib.h>  // free

t_data	*ft_parse(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	if (check_args(ac, av) == 1) //I am using exit to leave the program
	{
		free(data);
		return (NULL);
	}
	instantiate_data(data); //nothing to fail
	if (!parse_data(data, av[1]))  //a lot to free and use exit or return
	{
		// Free any allocated data before returning NULL
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
		return (NULL);
	}
	return (data);
}
