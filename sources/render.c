#include "cub3D.h"

void	ft_pixel_to_window(t_image *image, int x, int y, int colour)
{
	int	offset;

	offset = (image->line_len * y) + (x * image->bits_per_pixel / 8);
	*((unsigned int *)(image->img_pixels_ptr + offset)) = colour;
}

void	ft_image_render(t_cub3D *cub, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->window_height)
	{
		x = 0;
		while (x < cub->window_width)
		{
			ft_pixel_to_window(cub->img, x, y, colour);
			x++;
		}
		y++;
	}
}
