#include "cub3D.h"

void	ft_pixel_to_window(t_image *image, int x, int y, int colour)
{
	int	offset;

	offset = (image->line_len * y) + (x * image->bits_per_pixel / 8);
	*((unsigned int *)(image->img_pixels_ptr + offset)) = colour;
}

void	ft_draw_culums(t_cub3D *cub, int x)
{
	int	wallheight;
	int	wallstart;
	int	wallend;
	int	y;

	y = 0;
	wallheight = (int)(cub->window_height / cub->wall->wall_distance);
	wallstart = -wallheight / 2 + cub->window_height / 2;
	wallend = wallheight / 2 + cub->window_height / 2;
	if (wallstart < 0)
		wallstart = 0;
	if (wallend >= cub->window_height)
		wallend = cub->window_height - 1;
	while (y < cub->window_height)
	{
		if (y < wallstart)
			ft_pixel_to_window(cub->img, x, y, cub->ceiling_color);
		else if (y >= wallstart && y <= wallend)
			ft_pixel_to_window(cub->img, x, y, 0xffffff);
		else
			ft_pixel_to_window(cub->img, x, y, cub->floor_color);
		y++;
	}
}

// this is where raycasting will take place
void	ft_image_render(t_cub3D *cub)
{
	int		x;
	double	camerax;

	x = 0;
	while (x < cub->window_width)
	{
		camerax = 2 * x / (double)cub->window_width - 1;
		cub->dda->rayDirX = cub->dda->dirX + cub->dda->planeX * camerax;
		cub->dda->rayDirY = cub->dda->dirY + cub->dda->planeY * camerax;
		ft_dda(cub, cub->dda->rayDirX, cub->dda->rayDirY);
		ft_draw_culums(cub, x);
		x++;
	}
}
