#include "cub3D.h"

void	ft_pixel_to_window(t_image *image, int x, int y, int colour)
{
	int	offset;

	offset = (image->line_len * y) + (x * image->bits_per_pixel / 8);
	*((unsigned int *)(image->img_pixels_ptr + offset)) = colour;
}

void	ft_draw_culums(t_cub3D *cub, int x)
{
	int	wallHeight;
	int	drawStart;
	int	drawEnd;
	int	y;

	y = 0;
	wallHeight = (int)(cub->window_height / cub->wall->wall_distance);
	drawStart = -wallHeight / 2 + cub->window_height /2;
	drawEnd = wallHeight / 2 + cub->window_height /2;
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= cub->window_height)
		drawEnd = cub->window_height - 1;
	while (y < cub->window_height)
	{
		if (y < drawStart)
			ft_pixel_to_window(cub->img, x, y, cub->ceiling_color);
		else if (y >= drawStart && y <= drawEnd)
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
	double	cameraX;

	x = 0;
	while (x < cub->window_width)
	{
		cameraX = 2 * x / (double)cub->window_width - 1;
		cub->dda->rayDirX = cub->dda->dirX + cub->dda->planeX * cameraX;
		cub->dda->rayDirY = cub->dda->dirY + cub->dda->planeY * cameraX;
		ft_dda(cub, cub->dda->rayDirX, cub->dda->rayDirY);
		ft_draw_culums(cub, x);
		x++;
	}
}
