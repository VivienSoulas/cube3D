#include "cub3D.h"

// this is where raycasting will take place
int	ft_dda(t_cub3D *cub, double cameraX)
{
	cub->dda->rayDirX = cub->dda->dirX + cub->dda->planeX * cameraX;
	cub->dda->rayDirY = cub->dda->dirY + cub->dda->planeY * cameraX;
	cub->dda->mapX = (int)cub->player->pos_x;
	cub->dda->mapY = (int)cub->player->pos_y;
	if (cub->dda->rayDirX == 0)
		cub->dda->deltaDistX = 1e30;
	else
		cub->dda->deltaDistX = fabs(1.0 / cub->dda->rayDirX);
	if (cub->dda->rayDirY == 0)
		cub->dda->deltaDistY = 1e30;
	else
		cub->dda->deltaDistY = fabs(1.0 / cub->dda->rayDirY);

	printf("DDA algorithm calculated\n");
}
