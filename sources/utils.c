#include "cub3D.h"

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
