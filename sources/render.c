#include "cub3D.h"

void	ft_pixel_to_window(t_image *image, int x, int y, int colour)
{
	int	offset;

	offset = (image->line_len * y) + (x * image->bits_per_pixel / 8);
	*((unsigned int *)(image->img_pixels_ptr + offset)) = colour;
}

// this is where raycasting will take place
void	ft_image_render(t_cub3D *cub)
{
	int		x;
	int		wall;
	double	cameraX;

	x = 0;
	while (x < cub->window_width)
	{
		cameraX = 2 * x / (double)cub->window_width - 1;
		wall = ft_dda(cub, cameraX);
		// draw wall column
		x++;
	}
	printf("image render generated\n");
}
