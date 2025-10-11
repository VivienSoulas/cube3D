/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:45:28 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/03 09:45:29 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_pixel_to_window(t_image *image, int x, int y, int colour)
{
	int	offset;

	offset = (image->line_len * y) + (x * image->bits_per_pixel / 8);
	*((unsigned int *)(image->img_pixels_ptr + offset)) = colour;
}

void	ft_render_walls(t_cub3d *cub, int x, int y, int unclamped_wallstart)
{
	if (cub->wall->hit_side == 0)
	{
		ft_calc_tex_x_east_west(cub);
		if (cub->dda->raydirx > 0)
			ft_calc_tex_y_west(cub, y, unclamped_wallstart);
		else
			ft_calc_tex_y_east(cub, y, unclamped_wallstart);
	}
	else
	{
		ft_calc_tex_x_north_south(cub);
		if (cub->dda->raydiry > 0)
			ft_calc_tex_y_south(cub, y, unclamped_wallstart);
		else
			ft_calc_tex_y_north(cub, y, unclamped_wallstart);
	}
	ft_pixel_to_window(cub->img, x, y, cub->wall->colour);
}

void	ft_draw_culums(t_cub3d *cub, int x)
{
	int	y;
	int	unclamped_wallstart;

	y = 0;
	cub->wall->wallheight = (int)(cub->window_height
			/ cub->wall->wall_distance);
	cub->wall->wallstart = -cub->wall->wallheight / 2 + cub->window_height / 2;
	cub->wall->wallend = cub->wall->wallheight / 2 + cub->window_height / 2;
	unclamped_wallstart = (cub->window_height / 2)
		- (cub->wall->wallheight / 2);
	while (y < cub->window_height)
	{
		if (y < cub->wall->wallstart)
			ft_pixel_to_window(cub->img, x, y, cub->ceiling_color);
		else if (y >= cub->wall->wallstart && y <= cub->wall->wallend)
			ft_render_walls(cub, x, y, unclamped_wallstart);
		else
			ft_pixel_to_window(cub->img, x, y, cub->floor_color);
		y++;
	}
}

// calculate camera position and directions of ray casting
// perpendicular to player
void	ft_image_render(t_cub3d *cub)
{
	int		x;
	double	camerax;

	x = 0;
	while (x < cub->window_width)
	{
		camerax = 2 * x / (double)cub->window_width - 1;
		cub->dda->raydirx = cub->dda->dirx + cub->dda->planex * camerax;
		cub->dda->raydiry = cub->dda->diry + cub->dda->planey * camerax;
		ft_dda(cub, cub->dda->raydirx, cub->dda->raydiry);
		ft_draw_culums(cub, x);
		x++;
	}
}
