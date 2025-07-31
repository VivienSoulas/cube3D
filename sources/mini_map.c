#include "cub3D.h"

void	ft_pixel_to_mini_map(t_mini_map *mini_map, int x, int y, int colour)
{
	int	offset;

	offset = (mini_map->line_len * y) + (x * mini_map->bits_per_pixel / 8);
	*((unsigned int *)(offset + mini_map->img_pixels_ptr)) = colour;
}

// calculte the player's relative position to the minimap
// then find the position is the map and colours it
void ft_player_to_minimap(t_cub3D *cub)
{
	int	my;
	int	mx;

	cub->mini_map->player_mini_x = cub->player->pos_x * cub->mini_map->cell_width;
	cub->mini_map->player_mini_y = cub->player->pos_y * cub->mini_map->cell_heigth;
	my = 0;
	while (my < cub->mini_map->cell_heigth)
	{
		mx = 0;
		while (mx < cub->mini_map->cell_width)
		{
			ft_pixel_to_mini_map(cub->mini_map, cub->mini_map->player_mini_x + mx, cub->mini_map->player_mini_y + my, cub->mini_map->player_colour);
			mx++;
		}
		my++;
	}
}

// convert the received grid cells into pixels cell to colour
void	ft_printing_mini_map(t_cub3D *cub, int x, int y, int colour)
{
	int	mx;
	int	my;

	my = 0;
	while (my < cub->mini_map->cell_heigth)
	{
		mx = 0;
		while (mx < cub->mini_map->cell_width)
		{
			ft_pixel_to_mini_map(cub->mini_map, x * cub->mini_map->cell_width + mx, y * cub->mini_map->cell_heigth + my, colour);
			mx++;
		}
		my++;
	}
}

// creates cell within the minimaps
// allows us to see the walls and player
// walks through each cell of the grided map
void	ft_mini_map_render(t_cub3D *cub)
{
	int	x;
	int	y;
	int	colour;

	cub->mini_map->cell_width = cub->mini_map->width / cub->map->width;
	cub->mini_map->cell_heigth = cub->mini_map->height / cub->map->height;
	y = 0;
	while (y < cub->map->height)
	{
		x = 0;
		while (x < cub->map->width)
		{
			if (cub->map->grid[y][x] == '1')
				colour = cub->mini_map->wall_colour;
			else if (cub->map->grid[y][x] == '0')
				colour = cub->floor_color;
			ft_printing_mini_map(cub, x, y, colour);
			x++;
		}
		y++;
	}
	ft_player_to_minimap(cub);
	printf("minimap render generated\n");
}
