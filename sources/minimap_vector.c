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
void	ft_print_vector_line_minimap(t_cub3D *cub, float cos, float sin)
{
	int	i;

	i = 0;
	cub->vector->prev_px = cub->vector->start_x;
	cub->vector->prev_py = cub->vector->start_y;
	while (i < cub->mini_map->vector_length)
	{
		cub->vector->px = cub->vector->start_x + (int)(cos * i * cub->mini_map->cell_width);
		cub->vector->py = cub->vector->start_y + (int)(sin * i * cub->mini_map->cell_heigth);
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
	float	right_angle;
	float	left_angle;

	cub->vector->start_x = cub->player->pos_x * cub->mini_map->cell_width + (cub->mini_map->cell_width / 4);
	cub->vector->start_y = cub->player->pos_y * cub->mini_map->cell_heigth + (cub->mini_map->cell_heigth / 4);
	right_angle = cub->player->radians_angle - (cub->player->fov / 2);
	left_angle  = cub->player->radians_angle + (cub->player->fov / 2);
	cub->player->cos_right = cos(right_angle);
	cub->player->sin_right = sin(right_angle);
	cub->player->cos_left = cos(left_angle);
	cub->player->sin_left = sin(left_angle);
	ft_print_vector_line_minimap(cub, cub->player->cos_right, cub->player->sin_right);
	ft_print_vector_line_minimap(cub, cub->player->cos_left, cub->player->sin_left);
	printf("vector calculated and printed\n");
}
