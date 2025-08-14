#ifndef GRAPHIC_H
# define GRAPHIC_H

// Forward declaration to avoid circular dependency
typedef struct s_cub3D t_cub3D;

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

typedef struct s_weapon
{
	void	*weapon;
	int		weapon_width;
	int		weapon_height;
	double	weapon_x;
	double	weapon_y;
}	t_weapon;

// initialisation
int		ft_initialise_mlx(t_cub3D *cub);

// render
void	ft_pixel_to_window(t_image *image, int x, int y, int colour);
void	ft_draw_culums(t_cub3D *cub, int x);
void	ft_image_render(t_cub3D *cub);

// window
int		ft_create_window(t_cub3D *cub);
int		ft_open_texture(t_cub3D *cub);
void	ft_render_image(t_cub3D *cub);
int		ft_render_weapon(t_cub3D *cub);

#endif