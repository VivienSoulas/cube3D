#include "cub3D.h"

int	ft_initialise_cub(t_cub3D *cub, char **av)
{
	cub->fd = open(av[1], O_RDONLY);
	cub->img = ft_calloc(1, sizeof(t_image));
	cub->mini_map = ft_calloc(1, sizeof(t_mini_map));
	cub->weapon = ft_calloc(1, sizeof(t_weapon));
	cub->textures = ft_calloc(1, sizeof(t_textures));
	cub->player = ft_calloc(1, sizeof(t_player));
	if (cub->fd == -1 || !cub->img || !cub->mini_map || !cub->weapon || !cub->textures || !cub->player)
		return (ft_exit(cub), ft_error(4), 1);
	cub->mini_map->width = 200;
	cub->mini_map->height = 200;
	cub->window_width = DEFAULT_WIDTH;
	cub->window_height = DEFAULT_HEIGHT;
	// ft_map_parsing(fd, cub);
	// if (!cub->map)
	// 	return (ft_exit(cub), ft_error(4), 1);
if (ft_create_map(cub) == 1)
return (ft_exit(cub), ft_error(4), 1);
	return (0);
}

int	ft_initialise_mlx(t_cub3D *cub)
{
// initialise connection
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		return (ft_exit(cub), ft_error(4), 1);

// creates window
	if (ft_create_window(cub) == 1)
		return (1);
// 	cub->window = mlx_new_window(cub->mlx_ptr, cub->window_width, cub->window_height, "cub3D");
// 	if (cub->window == NULL)
// 		return (ft_exit(cub), ft_error(4), 1);

// render image window size
	ft_render_image(cub);
	// cub->img->img_ptr = mlx_new_image(cub->mlx_ptr, cub->window_width, cub->window_height);
	// cub->img->img_pixels_ptr = mlx_get_data_addr(cub->img->img_ptr, &cub->img->bits_per_pixel, &cub->img->line_len, &cub->img->endian);
	// ft_image_render(cub, 0x0012FF);
	// mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->img->img_ptr, 0, 0);

// render minimap to scale
	ft_render_mini_map(cub);
	// cub->mini_map->width = cub->window_width / 5;
	// cub->mini_map->height = cub->mini_map->width;
	// cub->mini_map->img_ptr = mlx_new_image(cub->mlx_ptr, cub->mini_map->width, cub->mini_map->height);
	// cub->mini_map->img_pixels_ptr = mlx_get_data_addr(cub->mini_map->img_ptr, &cub->mini_map->bits_per_pixel, &cub->mini_map->line_len, &cub->mini_map->endian);
	// ft_mini_map_render(cub, 0xffffff);
	// mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->mini_map->img_ptr, 0, 0);

// find and display weapon image to scale
	if (ft_render_weapon(cub) == 1)
		return (1);
	// cub->weapon->weapon = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/weapon.xpm", &cub->weapon->weapon_width, &cub->weapon->weapon_height);
	// if (!cub->weapon->weapon)
	// 	return (ft_exit(cub), ft_error(5), 1);
	// cub->weapon->weapon_x = (cub->window_width - cub->weapon->weapon_width) / 2;
	// cub->weapon->weapon_y = cub->window_height - cub->weapon->weapon_height;
	// if (cub->weapon->weapon_y < 0)
	// 	cub->weapon->weapon_y = 0;
	// mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->weapon->weapon, cub->weapon->weapon_x, cub->weapon->weapon_y);
	return (0);
}
