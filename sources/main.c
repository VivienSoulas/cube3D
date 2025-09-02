#include "../includes/cub3D.h"

#include <fcntl.h>   // open
#include <unistd.h>  // close
#include <stdio.h>   // printf
#include <stdlib.h>  // free

int main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);//I am using exit to leave the program
	instantiate_data(&data); //nothing to fail
	parse_data(&data, argv[1]); //a lot to free and use exit or return
	return (0);
}
