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
		return (NULL);
	instantiate_data(data); //nothing to fail
	if (parse_data(data, av[1]) == 1)  //a lot to free and use exit or return
		return (NULL);
	return (data);
}
