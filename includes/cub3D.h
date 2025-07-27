#ifndef CUB3D_H
# define CUB3D_H

# define DEFAULT_WIDTH 1000
# define DEFAULT_HEIGHT 750
# define DEFAULT_MINI_WIDTH 200
# define DEFAULT_MINI_HEIGHT 200

# include "libft.h"
# include "mlx.h"
// # include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_textures
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	void	*weapon;
	int		width;
	int		height;
}	t_textures;

typedef struct s_mini_map
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_mini_map;

typedef struct s_cub3D
{
	int			fd;
	void		*mlx_ptr;
	void		*window;
	t_mini_map	*mini_map;
	t_textures	*textures;
	t_map		*map;
}	t_cub3D;

// error
void	ft_error(int id);

// exit
void	ft_exit(t_cub3D *cub);
void	ft_free_cub(t_cub3D **cub);

// free
void	ft_free_set_NULL(void **data);
void	ft_free_array(char **array);

// hooks
int		ft_events(int key, t_cub3D *cub);

// initialisation
int		ft_initialise_cub(t_cub3D *cub, char **av);
int		ft_initialise_mlx(t_cub3D *cub);

// map parsing
void	ft_map_parsing(int fd, t_cub3D *cub);

// mini map
void	ft_mini_map_management(t_cub3D *cub, int colour);
void	ft_my_pixel_put(t_mini_map *mini_map, int x, int y, int colour);

// utils
int		ft_create_map(t_cub3D *cub);

#endif