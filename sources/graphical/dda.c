#include "cub3D.h"

void	ft_wall_distance(t_cub3D *cub)
{
	double	dx;
	double	dy;

	if (cub->wall->hit_side == 0)
		cub->wall->wall_distance = (cub->dda->sidedistx - cub->dda->deltadistx);
	else
		cub->wall->wall_distance = (cub->dda->sidedisty - cub->dda->deltadisty);
	dx = cub->dda->mapx - cub->player->pos_x;
	dy = cub->dda->mapy - cub->player->pos_y;
	cub->wall->mini_distance = sqrt(dx * dx + dy * dy);
}

void	ft_finding_wall(t_cub3D *cub)
{
	cub->wall->hit = 0;
	while (cub->wall->hit == 0)
	{
		if (cub->dda->sidedistx < cub->dda->sidedisty)
		{
			cub->dda->sidedistx += cub->dda->deltadistx;
			cub->dda->mapx += cub->dda->stepx;
			cub->wall->hit_side = 0;
		}
		else
		{
			cub->dda->sidedisty += cub->dda->deltadisty;
			cub->dda->mapy += cub->dda->stepy;
			cub->wall->hit_side = 1;
		}
		if (cub->dda->mapx < 0 || cub->dda->mapx >= cub->map->width
			|| cub->dda->mapy < 0 || cub->dda->mapy >= cub->map->height)
		{
			cub->wall->hit = 1;
		}
		else if (cub->map->grid[cub->dda->mapy][cub->dda->mapx] == '1')
			cub->wall->hit = 1;
	}
}

void	ft_steps(t_cub3D *cub, double raydirx, double raydiry)
{
	if (raydirx < 0)
	{
		cub->dda->stepx = -1;
		cub->dda->sidedistx = (cub->player->pos_x
				- (double)cub->dda->mapx) * cub->dda->deltadistx;
	}
	else
	{
		cub->dda->stepx = 1;
		cub->dda->sidedistx = ((double)cub->dda->mapx
				+ 1.0 - cub->player->pos_x) * cub->dda->deltadistx;
	}
	if (raydiry < 0)
	{
		cub->dda->stepy = -1;
		cub->dda->sidedisty = (cub->player->pos_y
				- (double)cub->dda->mapy) * cub->dda->deltadisty;
	}
	else
	{
		cub->dda->stepy = 1;
		cub->dda->sidedisty = ((double)cub->dda->mapy
				+ 1.0 - cub->player->pos_y) * cub->dda->deltadisty;
	}
}

void	ft_dda(t_cub3D *cub, double raydirx, double raydiry)
{
	cub->dda->mapx = (int)cub->player->pos_x;
	cub->dda->mapy = (int)cub->player->pos_y;
	if (raydirx == 0)
		cub->dda->deltadistx = 1e30;
	else
		cub->dda->deltadistx = fabs(1.0 / raydirx);
	if (raydiry == 0)
		cub->dda->deltadisty = 1e30;
	else
		cub->dda->deltadisty = fabs(1.0 / raydiry);
	ft_steps(cub, raydirx, raydiry);
	ft_finding_wall(cub);
	ft_wall_distance(cub);
}
