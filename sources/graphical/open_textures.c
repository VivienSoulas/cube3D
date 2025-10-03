/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:45:20 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/03 09:45:21 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_open_north(t_cub3D *cub)
{
	int	bpp;
	int	line_len;
	int	endian;

	cub->textures->north_img = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->north_path, &cub->textures->texture_width,
			&cub->textures->texture_height);
	if (!cub->textures->north_img)
		return (1);
	cub->textures->north
		= (unsigned int *)mlx_get_data_addr(cub->textures->north_img,
			&bpp, &line_len, &endian);
	cub->textures->north_odd_path = ft_strdup("./textures/North_odd.xpm");
	cub->textures->north_odd_img = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->north_odd_path, &cub->textures->texture_width,
			&cub->textures->texture_height);
	if (!cub->textures->north_odd_img)
		return (1);
	cub->textures->north_odd
		= (unsigned int *)mlx_get_data_addr(cub->textures->north_odd_img,
			&bpp, &line_len, &endian);
	return (0);
}

int	ft_open_south(t_cub3D *cub)
{
	int	bpp;
	int	line_len;
	int	endian;

	cub->textures->south_img = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->south_path, &cub->textures->texture_width,
			&cub->textures->texture_height);
	if (!cub->textures->south_img)
		return (1);
	cub->textures->south
		= (unsigned int *)mlx_get_data_addr(cub->textures->south_img,
			&bpp, &line_len, &endian);
	return (0);
}

int	ft_open_east(t_cub3D *cub)
{
	int	bpp;
	int	line_len;
	int	endian;

	cub->textures->east_img = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->east_path, &cub->textures->texture_width,
			&cub->textures->texture_height);
	if (!cub->textures->east_img)
		return (1);
	cub->textures->east
		= (unsigned int *)mlx_get_data_addr(cub->textures->east_img,
			&bpp, &line_len, &endian);
	return (0);
}

int	ft_open_west(t_cub3D *cub)
{
	int	bpp;
	int	line_len;
	int	endian;

	cub->textures->west_img = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->west_path, &cub->textures->texture_width,
			&cub->textures->texture_height);
	if (!cub->textures->west_img)
		return (1);
	cub->textures->west
		= (unsigned int *)mlx_get_data_addr(cub->textures->west_img,
			&bpp, &line_len, &endian);
	return (0);
}
