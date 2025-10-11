/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:45:15 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/03 09:45:16 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_in_bonds_minimap(t_cub3d *cub, int x, int y)
{
	if (x > cub->mini_map->width || x < 0)
		return (1);
	if (y > cub->mini_map->height || y < 0)
		return (1);
	return (0);
}

// check if a position hits a wall in the map
int	ft_hits_wall(t_cub3d *cub, double world_x, double world_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)world_x;
	map_y = (int)world_y;
	if (map_x < 0 || map_x >= cub->map->width
		|| map_y < 0 || map_y >= cub->map->height)
		return (1);
	if (cub->map->grid[map_y] && map_x < (int)ft_strlen(cub->map->grid[map_y]))
		return (cub->map->grid[map_y][map_x] == '1');
	return (1);
}

// DDA-based ray casting that stops at walls
void	ft_cast_ray_to_wall(t_cub3d *cub, float cos_angle, float sin_angle)
{
	cub->vector->ray_x = cub->player->pos_x;
	cub->vector->ray_y = cub->player->pos_y;
	cub->vector->step_x = cos_angle * 0.02;
	cub->vector->step_y = sin_angle * 0.02;
	cub->vector->max_distance = 5.0;
	cub->vector->distance = 0;
	while (cub->vector->distance < cub->vector->max_distance)
	{
		cub->vector->minimap_x = (int)(cub->vector->ray_x
				* cub->mini_map->cell_width);
		cub->vector->minimap_y = (int)(cub->vector->ray_y
				* cub->mini_map->cell_heigth);
		if (ft_in_bonds_minimap(cub, cub->vector->minimap_x,
				cub->vector->minimap_y) == 0)
			ft_pixel_to_mini_map(cub->mini_map, cub->vector->minimap_x,
				cub->vector->minimap_y, 0x0000ff);
		if (ft_hits_wall(cub, cub->vector->ray_x, cub->vector->ray_y))
			break ;
		cub->vector->ray_x += cub->vector->step_x;
		cub->vector->ray_y += cub->vector->step_y;
		cub->vector->distance += 0.02;
	}
}

void	ft_fill_fov_vectors(t_cub3d *cub, float right_angle, float left_angle)
{
	double	new_sin;
	double	new_cos;
	double	step;

	step = 0.02;
	while (right_angle < left_angle)
	{
		new_cos = cos(right_angle);
		new_sin = -sin(right_angle);
		ft_cast_ray_to_wall(cub, new_cos, new_sin);
		right_angle += step;
	}
}

void	ft_field_of_view(t_cub3d *cub)
{
	double	right_angle;
	double	left_angle;

	cub->player->radians_angle = cub->player->angle * M_PI / 180;
	right_angle = cub->player->radians_angle - (cub->player->fov / 2);
	left_angle = cub->player->radians_angle + (cub->player->fov / 2);
	ft_fill_fov_vectors(cub, right_angle, left_angle);
}
