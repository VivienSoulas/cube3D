#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "../get_next_line/get_next_line.h"

typedef	struct s_colors
{
	int	r;
	int	g;
	int	bx;
} t_colors;

typedef struct s_data
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	bool		has_floor_color;
	bool		has_celling_color;
	t_colors	celling;
	t_colors	floor;
	int			map_starts;
	bool		has_map_started;
	int			total_lines;
	char		**map;
	char		*file_name;
	int			fd;
	int			player_x;
	int			player_y;
} t_data;

//input_validator
void	input_colors_and_textures(char *line, t_data *data);

//arg_validator
void	check_args(int argc, char **argv);

//error_handling
bool	has_fd_opened(int	fd);
void	ft_exit(int	exit_code, char *line);

// utils
void	print_map(char **map);

//instantiate_data
void instantiate_data(t_data *input);

#endif
