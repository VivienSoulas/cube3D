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
	int	a;
	int	b;
	int	c;
	int	d;

	a = ft_open_north(cub);
	b = ft_open_south(cub);
	c = ft_open_east(cub);
	d = ft_open_west(cub);
	if (a == 1 || b == 1 || c == 1 || d == 1)
		return (1);
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
	ft_image_render(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->img->img_ptr, 0, 0);
}

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
