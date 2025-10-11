#include "cub3D.h"

void ft_print_minimap_background(t_cub3D *cub, int x, int y)
{
	int	my;
	int	mx;

	my = 0;
	while (my < cub->mini_map->cell_heigth)
	{
		mx = 0;
		while (mx < cub->mini_map->cell_width)
		{
			ft_pixel_to_mini_map(cub->mini_map, x
				* cub->mini_map->cell_width + mx, y
				* cub->mini_map->cell_heigth + my, 0x000330);
			mx++;
		}
		my++;
	}
}
