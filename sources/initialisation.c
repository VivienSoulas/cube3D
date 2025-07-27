#include "cub3D.h"

int	ft_initialise_cub(t_cub3D *cub, char **av)
{
	cub->fd = open(av[1], O_RDONLY);
	if (cub->fd == -1)
		return (ft_exit(cub), ft_error(2), 1);
	// ft_map_parsing(fd, cub);
	// if (!cub->map)
	// 	return (ft_exit(cub), ft_error(4), 1);
if (ft_create_map(cub) == 1)
return (ft_exit(cub), ft_error(4), 1);
	cub->textures = ft_calloc(1, sizeof(t_textures));
	if (!cub->textures)
		return (ft_exit(cub), ft_error(4), 1);
	cub->mini_map = ft_calloc(1, sizeof(t_mini_map));
	if (!cub->mini_map)
		return (ft_exit(cub), ft_error(4), 1);
	return (0);
}

int	ft_initialise_mlx(t_cub3D *cub)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		return (ft_exit(cub), ft_error(4), 1);
	cub->window = mlx_new_window(cub->mlx_ptr,
			DEFAULT_WIDTH, DEFAULT_HEIGHT, "cub3D");
	if (cub->window == NULL)
		return (ft_exit(cub), ft_error(4), 1);
	cub->mini_map->img_ptr = mlx_new_image(cub->mlx_ptr, DEFAULT_MINI_WIDTH, DEFAULT_MINI_HEIGHT);
	cub->mini_map->img_pixels_ptr = mlx_get_data_addr(cub->mini_map->img_ptr, &cub->mini_map->bits_per_pixel, &cub->mini_map->line_len, &cub->mini_map->endian);
ft_mini_map_management(cub, 0xffffff);
mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->mini_map->img_ptr, 0, 0); 
	mlx_key_hook(cub->window, ft_events, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}
