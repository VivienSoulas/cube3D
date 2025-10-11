/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:44:43 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/03 09:44:44 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

// Forward declaration to avoid circular dependency
typedef struct s_cub3D	t_cub3d;

typedef struct s_vector
{
	int		start_x;
	int		start_y;
	int		px;
	int		py;
	int		dx;
	int		dy;
	int		steps;
	int		prev_px;
	int		prev_py;
	int		line_x;
	int		line_y;
	int		denom;

}	t_vector;

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
	int		vector_length;
}	t_mini_map;

// initialisation
void	ft_initialise_mini_map(t_cub3d *cub);

// mini map
void	ft_pixel_to_mini_map(t_mini_map *mini_map, int x, int y, int colour);
void	ft_player_to_minimap(t_cub3d *cub);
void	ft_printing_mini_map(t_cub3d *cub, int x, int y, int colour);
void	ft_find_colour(t_cub3d *cub, int line_len, int x, int y);
void	ft_mini_map_render(t_cub3d *cub);

// minimap vector
void	ft_fill_vector_line(t_cub3d *cub);
void	ft_print_vector_minimap(t_cub3d *cub, float cos, float sin);
void	ft_fill_fov_vectors(t_cub3d *cub, float right_angle, float left_angle);
void	ft_field_of_view(t_cub3d *cub);

// minimap utils

void	ft_print_minimap_background(t_cub3d *cub, int x, int y);

// render
void	ft_render_mini_map(t_cub3d *cub);

#endif