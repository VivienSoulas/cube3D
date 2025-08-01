#include "cub3D.h"

static int	ft_in_bonds_minimap(t_cub3D *cub, int x, int y)
{
	// int	grid_x;
	// int	grid_y;

	if (x > cub->mini_map->width || x < 0)
		return (1);
	if (y > cub->mini_map->height || y < 0)
		return (1);
	// grid_x = x / cub->mini_map->cell_width;
	// grid_y = y / cub->mini_map->cell_heigth;
	// if (grid_x >= cub->map->width || grid_y >= cub->map->height)
	// 	return (1);
	// if (cub->map->grid[grid_y][grid_x] == '1')
	// 	return (1);
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
		// if (ft_in_bonds_minimap(cub, cub->vector->px, cub->vector->py) == 1)
		// 	break ;
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

void	ft_fill_fov_vectors(t_cub3D *cub, float right_angle, float left_angle)
{
	float	new_sin;
	float	new_cos;
	double	step;

	step = 0.005;
	while (right_angle < left_angle)
	{
		new_cos = cos(right_angle);
		new_sin = sin(right_angle);
		ft_print_vector_line_minimap(cub, new_cos, new_sin);
		right_angle += step;
	}
}

void	ft_field_of_view(t_cub3D *cub)
{
	float	right_angle;
	float	left_angle;

	cub->vector->start_x = cub->player->pos_x * cub->mini_map->cell_width + (cub->mini_map->cell_width / 4);
	cub->vector->start_y = cub->player->pos_y * cub->mini_map->cell_heigth + (cub->mini_map->cell_heigth / 4);
	right_angle = cub->player->radians_angle - (cub->player->fov / 2);
	left_angle  = cub->player->radians_angle + (cub->player->fov / 2);
	ft_fill_fov_vectors(cub, right_angle, left_angle);
	printf("vector calculated and printed\n");
}
