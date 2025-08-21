#include "cub3D.h"

int	ft_initialise_cub(t_cub3D *cub, char **av)
{
	cub->fd = open(av[1], O_RDONLY);
	cub->img = ft_calloc(1, sizeof(t_image));
	cub->mini_map = ft_calloc(1, sizeof(t_mini_map));
	cub->weapon = ft_calloc(1, sizeof(t_weapon));
	cub->textures = ft_calloc(1, sizeof(t_textures));
	cub->player = ft_calloc(1, sizeof(t_player));
	cub->vector = ft_calloc(1, sizeof(t_vector));
	if (cub->fd == -1 || !cub->img || !cub->mini_map
		|| !cub->weapon || !cub->textures || !cub->player || !cub->vector)
		return (ft_exit(cub), ft_error(4), 1);
	cub->window_width = DEFAULT_WIDTH;
	cub->window_height = DEFAULT_HEIGHT;
	cub->player->radians_angle = cub->player->angle * M_PI / 180;
	// ft_map_parsing(fd, cub);
	// if (!cub->map)
	// 	return (ft_exit(cub), ft_error(4), 1);
if (ft_read_map(cub) == 1)
return (ft_exit(cub), ft_error(4), 1);
	return (0);
}

void	ft_initialise_mini_map(t_cub3D *cub)
{
	cub->mini_map->width = 200;
	cub->mini_map->height = 200;
	cub->mini_map->wall_colour = 0xFF00FF;
	cub->mini_map->player_colour = 0xFF0000;
	cub->mini_map->vector_length = 5;
}

int	ft_initialise_mlx(t_cub3D *cub)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		return (ft_exit(cub), ft_error(4), 1);
	if (ft_create_window(cub) == 1)
		return (1);
	if (ft_open_texture(cub) == 1)
		return (1);
	ft_render_image(cub);
	//if (ft_render_weapon(cub) == 1)
	//		return (1);
	ft_render_mini_map(cub);
	return (0);
}
