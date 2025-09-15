#include "cub3D.h"

#include <fcntl.h>   // open
#include <unistd.h>  // close
#include <stdio.h>   // printf
#include <stdlib.h>  // free

t_data	*ft_parse(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	check_args(ac, av);//I am using exit to leave the program
	instantiate_data(data); //nothing to fail
	parse_data(data, av[1]); //a lot to free and use exit or return
	return (data);
}
