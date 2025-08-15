#ifndef CUB3D_H
# define CUB3D_H

# define DEFAULT_WIDTH 1000
# define DEFAULT_HEIGHT 1000

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

// System includes
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>

// Project includes
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "minimap.h"
# include "movement.h"
# include "graphic.h"
# include "dda.h"

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		angle;
	double	radians_angle;
	float	cos_right;
	float	sin_right;
	float	cos_left;
	float	sin_left;
	char	start_dir;
	float	fov;
	double	fov_factor;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_cub3D
{
	int				fd;
	void			*mlx_ptr;
	void			*window;
	int				window_width;
	int				window_height;
	int				floor_color;
	int				ceiling_color;
	int				mouse_x;
	double			new_x;
	double			new_y;
	int				keypressed[65537];
	int				mouse_on_off;
	t_image			*img;
	t_mini_map		*mini_map;
	t_weapon		*weapon;
	t_textures		*textures;
	t_map			*map;
	t_player		*player;
	t_vector		*vector;
	t_dda			*dda;
	t_wall			*wall;
}	t_cub3D;

// error
void	ft_error(int id);

// exit
void	ft_exit(t_cub3D *cub);
void	ft_destroy_texture(t_cub3D *cub);
void	ft_free_struct(t_cub3D **cub);
void	ft_free_cub(t_cub3D **cub);

// free
void	ft_free_set_null(void **data);
void	ft_free_array(char **array);

// initialisation
int		ft_initialise_cub(t_cub3D *cub, char **av);

// map parsing
void	ft_map_parsing(int fd, t_cub3D *cub);

// temp
int		ft_read_map(t_cub3D *cub);

// utils
int		ft_alloc_struct(t_cub3D *cub);
int		ft_absolute(int a);
void	ft_update_dda_vector(t_cub3D *cub);
void	ft_update(t_cub3D *cub);

#endif