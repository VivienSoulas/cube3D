#include "cub3D.h"

static int	ft_in_bonds_minimap(t_cub3D *cub, int x, int y)
{
	if (x > cub->mini_map->width || x < 0)
		return (1);
	if (y > cub->mini_map->height || y < 0)
		return (1);
	return (0);
}

// fill the dots between the previous function
void	ft_fill_vector_line(t_cub3D *cub)
{
	int	s;
	int	denom;

	s = 0;
	while (s <= cub->vector->steps)
	{
		if (cub->vector->steps != 0)
			denom = cub->vector->steps;
		else
			denom = 1;
		cub->vector->line_x = cub->vector->prev_px + (cub->vector->px - cub->vector->prev_px) * s / denom;
		cub->vector->line_y = cub->vector->prev_py + (cub->vector->py - cub->vector->prev_py) * s / denom;
		if (ft_in_bonds_minimap(cub, cub->vector->line_x, cub->vector->line_y) == 0)
			ft_pixel_to_mini_map(cub->mini_map, cub->vector->line_x, cub->vector->line_y, 0x0000ff);
	s++;
	}
}

// calculate and print the vector line on minimap
void	ft_print_vector_line_minimap(t_cub3D *cub, int start_x, int start_y)
{
	int	i;

	i = 0;
	cub->vector->prev_px = start_x;
	cub->vector->prev_py = start_y;
	while (i < cub->mini_map->vector_length)
	{
		cub->vector->px = start_x + (int)(cub->player->cos * i * cub->mini_map->cell_width);
		cub->vector->py = start_y + (int)(cub->player->sin * i * cub->mini_map->cell_heigth);
		cub->vector->dx = ft_absolute(cub->vector->px - cub->vector->prev_px);
		cub->vector->dy = ft_absolute(cub->vector->py - cub->vector->prev_py);
		if (cub->vector->dx > cub->vector->dy)
			cub->vector->steps = cub->vector->dx;
		else
			cub->vector->steps = cub->vector->dy;
		ft_fill_vector_line(cub);
		cub->vector->prev_px = cub->vector->px;
		cub->vector->prev_py =cub->vector->py;
		i++;
	}
}

// calculate the vector starting position
// convert player's position to pixel coordinates on the minimap
// calculate the direction of the vector
void	ft_field_of_view(t_cub3D *cub)
{
	cub->vector->start_x = cub->player->pos_x * cub->mini_map->cell_width + (cub->mini_map->cell_width / 4);
	cub->vector->start_y = cub->player->pos_y * cub->mini_map->cell_heigth + (cub->mini_map->cell_heigth / 4);
	cub->player->cos = cos(cub->player->radians_angle);
	cub->player->sin = sin(cub->player->radians_angle);
	ft_print_vector_line_minimap(cub, cub->vector->start_x, cub->vector->start_y);
	printf("vector calculated and printed\n");
}
