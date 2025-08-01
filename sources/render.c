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
	int	x;
	int	y;
	int	map_x;
	int	map_y;
	int	colour;

	y = 0;
	while (y < cub->window_height)
	{
		x = 0;
		while (x < cub->window_width)
		{
			map_x = x * cub->map->width / cub->window_width;
			map_y = y * cub->map->height / cub->window_height;
			if (cub->map->grid[map_y][map_x] == '1')
				colour = 0x333333;
			else if (cub->map->grid[map_y][map_x] == '0')
				colour = 0xffffff;
			ft_pixel_to_window(cub->img, x, y, colour);
			x++;
		}
		y++;
	}
	//ft_player_to_minimap(cub);
	printf("image render generated\n");
}
