#include "../includes/cub3D.h"

#include <fcntl.h>   // open
#include <unistd.h>  // close
#include <stdio.h>   // printf
#include <stdlib.h>  // free

void initialize_data(t_input *input)
{
	input->map=NULL;
	input->no_texture = NULL;
	input->so_texture = NULL;
	input->ea_texture = NULL;
	input->we_texture = NULL;
	input->has_celling_color = false;
	input->has_floor_color = false;
}

void	input_data(t_input *data, char *arg)
{

    char *line;

    data->fd = open(arg, O_RDONLY);
    if (data->fd < 0)
    {
        perror("Failure to open file");
        return;
    }
    while ((line = get_next_line(data->fd)) != NULL)
    {
        printf("%s", line);
		if (line[0] == 'C' || line[0] == 'F')
		{
			//get celling and flor collor and put in the struct
		}
		else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		{
			//getting textures
		}
		if (data->no_texture != NULL && data->so_texture != NULL
			&& data->ea_texture != NULL && data->we_texture != NULL
			&& data->has_celling_color != false && data->has_floor_color != false)
		{
			printf("Map starts\n");
		}
		//else (check if it missing some textures and
		//celling and floor, because only after that the map starts)
        free(line);  // very important: free the allocated memory from get_next_line
    }
    // close(fd);
}


int main(int argc, char **argv)
{
	t_input	data;
	//Check if I receive the necessary args and if name is correct
	check_args(argc, argv);
	initialize_data(&data);
	input_data(&data, argv[1]);

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
