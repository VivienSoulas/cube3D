/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:45:07 by vsoulas           #+#    #+#             */
/*   Updated: 2025/11/14 11:19:35 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_initialise_cub(t_cub3d *cub, int ac, char **av)
{
	if (ft_alloc_struct(cub) == 1)
		return (ft_error(4), 1);
	cub->window_width = DEFAULT_WIDTH;
	cub->window_height = DEFAULT_HEIGHT;
	cub->player->fov = M_PI / 3;
	cub->player->fov_factor = tan(cub->player->fov / 2);
	cub->mouse_on_off = true;
	cub->data = ft_parse(ac, av);
	if (!cub->data)
		return (1);
	if (ft_convert_tdata(cub) == 1)
		return (1);
	ft_update_dda_vector(cub);
	return (0);
}

int	ft_convert_tdata(t_cub3d *cub)
{
	cub->map = malloc(sizeof(t_map));
	if (!cub->map)
		return (ft_error(4), 1);
	cub->map->width = cub->data->map_width;
	cub->map->height = cub->data->map_height;
	cub->player->pos_x = (double)cub->data->player_x;
	cub->player->pos_y = (double)cub->data->player_y;
	cub->player->start_dir = cub->data->start_dir;
	if (cub->data->start_dir == 'N')
		cub->player->angle = 90;
	else if (cub->data->start_dir == 'S')
		cub->player->angle = 270;
	else if (cub->data->start_dir == 'E')
		cub->player->angle = 0;
	else if (cub->data->start_dir == 'W')
		cub->player->angle = 180;
	cub->floor_color = (cub->data->floor.r << 16)
		| (cub->data->floor.g << 8) | cub->data->floor.b;
	cub->ceiling_color = (cub->data->celling.r << 16)
		| (cub->data->celling.g << 8) | cub->data->celling.b;
	cub->textures->north_path = cub->data->no_texture;
	cub->textures->south_path = cub->data->so_texture;
	cub->textures->east_path = cub->data->ea_texture;
	cub->textures->west_path = cub->data->we_texture;
	return (cub->map->grid = cub->data->map, 0);
}

void	ft_initialise_mini_map(t_cub3d *cub)
{
	cub->mini_map->width = 350;
	cub->mini_map->height = 350;
	cub->mini_map->wall_colour = 0x333333;
	cub->mini_map->player_colour = 0xFF0000;
	cub->mini_map->vector_length = 5;
}

int	ft_initialise_mlx(t_cub3d *cub)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		return (ft_error(4), 1);
	if (ft_open_texture(cub) == 1)
		return (1);
	if (ft_create_window(cub) == 1)
		return (1);
	ft_render_image(cub);
	ft_render_mini_map(cub);
	return (0);
}
