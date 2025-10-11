/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:44:43 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/03 09:44:44 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

// Forward declaration to avoid circular dependency
typedef struct s_cub3D	t_cub3d;

typedef struct s_textures
{
	char			*north_path;
	void			*north_img;
	unsigned int	*north;
	char			*north_odd_path;
	void			*north_odd_img;
	unsigned int	*north_odd;
	char			*south_path;
	void			*south_img;
	unsigned int	*south;
	char			*east_path;
	void			*east_img;
	unsigned int	*east;
	char			*west_path;
	void			*west_img;
	unsigned int	*west;
	int				texture_width;
	int				texture_height;
	int				texx;
	int				texy;
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

// initialisation
int		ft_initialise_mlx(t_cub3d *cub);

// render
void	ft_pixel_to_window(t_image *image, int x, int y, int colour);
void	ft_render_walls(t_cub3d *cub, int x, int y, int unclamped_wallstart);
void	ft_draw_culums(t_cub3d *cub, int x);
void	ft_image_render(t_cub3d *cub);

// render walls
void	ft_calc_tex_y_east(t_cub3d *cub, int y, int unclamped_wallstart);
void	ft_calc_tex_y_west(t_cub3d *cub, int y, int unclamped_wallstart);
void	ft_calc_tex_y_south(t_cub3d *cub, int y, int unclamped_wallstart);
void	ft_calc_tex_y_north(t_cub3d *cub, int y, int unclamped_wallstart);

// render utils
void	ft_calc_tex_x_east_west(t_cub3d *cub);
void	ft_calc_tex_x_north_south(t_cub3d *cub);

// window
int		ft_create_window(t_cub3d *cub);
int		ft_open_texture(t_cub3d *cub);
void	ft_render_image(t_cub3d *cub);

// open textures
int		ft_open_west(t_cub3d *cub);
int		ft_open_east(t_cub3d *cub);
int		ft_open_north(t_cub3d *cub);
int		ft_open_south(t_cub3d *cub);

#endif