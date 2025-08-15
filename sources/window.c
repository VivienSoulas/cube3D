#include "cub3D.h"

// creates window
int	ft_create_window(t_cub3D *cub)
{
	cub->window = mlx_new_window(cub->mlx_ptr,
			cub->window_width, cub->window_height, "cub3D");
	if (cub->window == NULL)
		return (ft_exit(cub), ft_error(4), 1);
	return (0);
}

// open all texture files
int	ft_open_texture(t_cub3D *cub)
{
	cub->textures->north = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->north_path,
			&cub->textures->wall_width, &cub->textures->wall_height);
	if (!cub->textures->north)
		return (ft_exit(cub), ft_error(5), 1);
	cub->textures->south = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->south_path, &cub->textures->wall_width,
			&cub->textures->wall_height);
	if (!cub->textures->south)
		return (ft_exit(cub), ft_error(5), 1);
	cub->textures->east = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->east_path, &cub->textures->wall_width,
			&cub->textures->wall_height);
	if (!cub->textures->east)
		return (ft_exit(cub), ft_error(5), 1);
	cub->textures->west = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->west_path, &cub->textures->wall_width,
			&cub->textures->wall_height);
	if (!cub->textures->west)
		return (ft_exit(cub), ft_error(5), 1);
	return (0);
}

// here needs to be the raycasting function(s)
// instead of image render only with colours
void	ft_render_image(t_cub3D *cub)
{
	if (!cub->img->img_ptr)
	{
		cub->img->img_ptr = mlx_new_image(cub->mlx_ptr,
				cub->window_width, cub->window_height);
		cub->img->img_pixels_ptr = mlx_get_data_addr(cub->img->img_ptr,
				&cub->img->bits_per_pixel, &cub->img->line_len,
				&cub->img->endian);
	}
// might need to destroy textures here when render is using them ?
	ft_image_render(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->img->img_ptr, 0, 0);
}

// find and display weapon image
// int	ft_render_weapon(t_cub3D *cub)
// {
// 	cub->weapon->weapon = mlx_xpm_file_to_image(cub->mlx_ptr,
	// "textures/weapon.xpm", &cub->weapon->weapon_width,
	// &cub->weapon->weapon_height);
// 	if (!cub->weapon->weapon)
// 		return (ft_exit(cub), ft_error(5), 1);
// 	cub->weapon->weapon_x = (cub->window_width - cub->weapon->weapon_width) / 2;
// 	cub->weapon->weapon_y = cub->window_height - cub->weapon->weapon_height;
// 	if (cub->weapon->weapon_y < 0)
// 		cub->weapon->weapon_y = 0;
// 	mlx_put_image_to_window(cub->mlx_ptr, cub->window,
//	cub->weapon->weapon, cub->weapon->weapon_x, cub->weapon->weapon_y);
// 	printf("weapon created and applied to window\n");
// 	return (0);
// }

// render minimap to scale
void	ft_render_mini_map(t_cub3D *cub)
{
	if (!cub->mini_map->img_ptr)
	{
		cub->mini_map->width = cub->window_width / 5;
		cub->mini_map->height = cub->mini_map->width;
		cub->mini_map->img_ptr = mlx_new_image(cub->mlx_ptr,
				cub->mini_map->width, cub->mini_map->height);
		cub->mini_map->img_pixels_ptr = mlx_get_data_addr(
				cub->mini_map->img_ptr, &cub->mini_map->bits_per_pixel,
				&cub->mini_map->line_len, &cub->mini_map->endian);
	}
	ft_mini_map_render(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->window,
		cub->mini_map->img_ptr, 0, 0);
}
