#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_input
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	//floor color
	//celling color
	char	**map;

} t_input;

//input_validator
int	check_map_char(char **map);

//arg_validator
void	check_args(int argc, char **argv);

#endif
