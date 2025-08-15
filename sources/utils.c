#include "cub3D.h"

int	ft_alloc_struct(t_cub3D *cub)
{
	cub->img = ft_calloc(1, sizeof(t_image));
	cub->mini_map = ft_calloc(1, sizeof(t_mini_map));
	// cub->weapon = ft_calloc(1, sizeof(t_weapon));
	cub->textures = ft_calloc(1, sizeof(t_textures));
	cub->player = ft_calloc(1, sizeof(t_player));
	cub->vector = ft_calloc(1, sizeof(t_vector));
	cub->dda = ft_calloc(1, sizeof(t_dda));
	cub->wall = ft_calloc(1, sizeof(t_wall));
	if (cub->fd == -1 || !cub->img || !cub->mini_map
		/* || !cub->weapon  */|| !cub->textures || !cub->player || !cub->vector
		|| !cub->dda || !cub->wall)
		return (1);
	return (0);
}

int	ft_absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	ft_update_dda_vector(t_cub3D *cub)
{
	cub->player->radians_angle = cub->player->angle * M_PI / 180;
	cub->dda->dirx = cos(cub->player->radians_angle);
	cub->dda->diry = -sin(cub->player->radians_angle);
	cub->dda->planex = sin(cub->player->radians_angle) * cub->player->fov_factor;
	cub->dda->planey = cos(cub->player->radians_angle) * cub->player->fov_factor;
}
