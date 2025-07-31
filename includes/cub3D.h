#ifndef CUB3D_H
# define CUB3D_H

# define DEFAULT_WIDTH 1000
# define DEFAULT_HEIGHT 750

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

# define UP 1
# define DOWN 2
# define RIGHT 3
# define LEFT 4

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

// radians = degrees * pi / 180
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	radians_angle; // must be in radian (from 0 to 2pi)
	//double	dir_x;
	//double	dir_y;
	//double	plane_x;
	//double	plane_y;
	char	start_dir;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct weapon
{
	void	*weapon;
	int		weapon_width;
	int		weapon_height;
	double	weapon_x;
	double	weapon_y;
}	t_weapon;

typedef struct s_textures
{
	char	*north_path;
	void	*north;
	char	*south_path;
	void	*south;
	char	*east_path;
	void	*east;
	char	*west_path;
	void	*west;
	int		wall_width;
	int		wall_height;
}	t_textures;

typedef struct s_mini_map
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		width;
	int		height;
	int		cell_width;
	int		cell_heigth;
	int		wall_colour;
	int		player_colour;
	double	player_mini_x;
	double	player_mini_y;
}	t_mini_map;

// image to render for window
typedef struct s_image
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		width;
	int		height;
}	t_image;

typedef struct s_cub3D
{
	int				fd;
	void			*mlx_ptr;
	void			*window;
	int				window_width;
	int				window_height;
	int				floor_color;
	int				ceiling_color;
	t_image			*img;
	t_mini_map		*mini_map;
	t_weapon		*weapon;
	t_textures		*textures;
	t_map			*map;
	t_player		*player;
}	t_cub3D;

// error
void	ft_error(int id);

// exit
void	ft_exit(t_cub3D *cub);
void	ft_free_cub(t_cub3D **cub);
void	ft_destroy_texture(t_cub3D *cub);

// free
void	ft_free_set_null(void **data);
void	ft_free_array(char **array);

// hooks
int		ft_key_hooks(int key, t_cub3D *cub);
int		ft_mouse_move_event(int x, int y, void *cub);
int		ft_resize(void *cub);
int		ft_red_cross(void *cub);

// initialisation
int		ft_initialise_cub(t_cub3D *cub, char **av);
void	ft_initialise_mini_map(t_cub3D *cub);
int		ft_initialise_mlx(t_cub3D *cub);

// map parsing
void	ft_map_parsing(int fd, t_cub3D *cub);

// mini map
void	ft_mini_map_render(t_cub3D *cub);
void	ft_pixel_to_mini_map(t_mini_map *mini_map, int x, int y, int colour);

// movement
void	ft_movement_hooks(int key, t_cub3D *cub);
void	ft_side_movement(int key, t_cub3D *cub);
void	ft_orientation_change(int key, t_cub3D *cub);

// render
void	ft_pixel_to_window(t_image *image, int x, int y, int colour);
void	ft_image_render(t_cub3D *cub);

// temp
int		ft_read_map(t_cub3D *cub);

// window
int		ft_create_window(t_cub3D *cub);
void	ft_render_image(t_cub3D *cub);
void	ft_render_mini_map(t_cub3D *cub);
int		ft_render_weapon(t_cub3D *cub);
int		ft_open_texture(t_cub3D *cub);

#endif