#include "cub3D.h"

void	ft_wall_distance(t_cub3D *cub)
{
	double	dx;
	double	dy;

	if (cub->wall->hit_side == 0)
		cub->wall->wall_distance = (cub->dda->sideDistX - cub->dda->deltaDistX);
	else
		cub->wall->wall_distance = (cub->dda->sideDistY - cub->dda->deltaDistY);
	dx = cub->dda->mapX - cub->player->pos_x;
	dy = cub->dda->mapY - cub->player->pos_y;
	cub->wall->mini_distance = sqrt(dx * dx + dy * dy);
}

void	ft_finding_wall(t_cub3D *cub)
{
	cub->wall->hit = 0;
	while (cub->wall->hit == 0)
	{
		if (cub->dda->sideDistX < cub->dda->sideDistY)
		{
			cub->dda->sideDistX += cub->dda->deltaDistX;
			cub->dda->mapX += cub->dda->stepX;
			cub->wall->hit_side = 0;
		}
		else
		{
			cub->dda->sideDistY += cub->dda->deltaDistY;
			cub->dda->mapY += cub->dda->stepY;
			cub->wall->hit_side = 1;
		}
		if (cub->dda->mapX < 0 || cub->dda->mapX >= cub->map->width
			|| cub->dda->mapY < 0 || cub->dda->mapY >= cub->map->height)
		{
			cub->wall->hit = 1;
		}
		else if (cub->map->grid[cub->dda->mapY][cub->dda->mapX] == '1')
			cub->wall->hit = 1;
	}
}

void	ft_steps(t_cub3D *cub, double rayDirX, double rayDirY)
{
	if (rayDirX < 0)
	{
		cub->dda->stepX = -1;
		cub->dda->sideDistX = (cub->player->pos_x
				- (double)cub->dda->mapX) * cub->dda->deltaDistX;
	}
	else
	{
		cub->dda->stepX = 1;
		cub->dda->sideDistX = ((double)cub->dda->mapX
				+ 1.0 - cub->player->pos_x) * cub->dda->deltaDistX;
	}
	if (rayDirY < 0)
	{
		cub->dda->stepY = -1;
		cub->dda->sideDistY = (cub->player->pos_y
				- (double)cub->dda->mapY) * cub->dda->deltaDistY;
	}
	else
	{
		cub->dda->stepY = 1;
		cub->dda->sideDistY = ((double)cub->dda->mapY
				+ 1.0 - cub->player->pos_y) * cub->dda->deltaDistY;
	}
}

void	ft_dda(t_cub3D *cub, double rayDirX, double rayDirY)
{
	cub->dda->mapX = (int)cub->player->pos_x;
	cub->dda->mapY = (int)cub->player->pos_y;
	if (rayDirX == 0)
		cub->dda->deltaDistX = 1e30;
	else
		cub->dda->deltaDistX = fabs(1.0 / rayDirX);
	if (rayDirY == 0)
		cub->dda->deltaDistY = 1e30;
	else
		cub->dda->deltaDistY = fabs(1.0 / rayDirY);
	ft_steps(cub, rayDirX, rayDirY);
	ft_finding_wall(cub);
	ft_wall_distance(cub);
}
