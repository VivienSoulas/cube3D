#include "cub3D.h"

void	ft_my_pixel_put(t_mini_map *mini_map, int x, int y, int colour)
{
	int	offset;

	offset = (mini_map->line_len * y) + (x * mini_map->bits_per_pixel / 8);
	*((unsigned int *)(offset + mini_map->img_pixels_ptr)) = colour;

	// int	offset;
	// int	center_x;
	// int	center_y;
	// int	radius;
	// int	distance_squared;

	// center_x = DEFAULT_MINI_WIDTH / 2;
	// center_y = DEFAULT_MINI_HEIGHT / 2;
	// radius = DEFAULT_MINI_WIDTH / 2;  // Assuming square minimap

	// // Calculate distance from center using distance formula
	// distance_squared = (x - center_x) * (x - center_x) + (y - center_y) * (y - center_y);

	// // Only draw pixel if it's within the circle
	// if (distance_squared <= radius * radius)
	// {
	// offset = (mini_map->line_len * y) + (x * mini_map->bits_per_pixel / 8);
	// *((unsigned int *)(offset + mini_map->img_pixels_ptr)) = colour;
	// }
}

void	ft_mini_map_management(t_cub3D *cub, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < DEFAULT_MINI_HEIGHT)
	{
		x = 0;
		while (x < DEFAULT_MINI_WIDTH)
		{
			ft_my_pixel_put(cub->mini_map, x, y, colour);
			x++;
		}
		y++;
	}
}
