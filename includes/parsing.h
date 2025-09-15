# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "../get_next_line/get_next_line.h"

typedef	struct s_colors
{
	int	r;
	int	g;
	int	b;
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
	char		start_dir;
	int			map_width;
	int			map_height;
} t_data;

t_data 	*ft_parse(int ac, char **av);

//arg_validator
int		check_args(int argc, char **argv);

//error_handling
bool	has_fd_opened(int	fd);
int		ft_exit_parsing(int	exit_code, char *line, t_data *data, char *msg);
void	free_array(char **array);

// utils
void	print_map(char **map);
char	**copy_map(t_data	*data);

//instantiate_data
void	instantiate_data(t_data *input);

//parse_data
int		parse_data(t_data *data, char *argv);
bool	has_map_started(t_data *data);
int		init_player_position(t_data *data);
int		validate_map(t_data *data);

//atributes_validator
int		*get_color_input(char *line);

//init_atribute
int		init_attributes(t_data *data, char *arg);

//map_validador.
bool	is_player(char	c);
bool	has_map_started(t_data *data);
int		flood_fill(char **map, int r, int x, int y, int	total_lines);