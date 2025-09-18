#include "cub3D.h"

void	ft_calc_tex_y_east(t_cub3D *cub, int y)
{
	cub->textures->texx = cub->textures->texture_width - cub->textures->texx - 1;
	cub->textures->texy = (int)((y - cub->wall->wallstart)
			* cub->textures->texture_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->texture_height)
		cub->textures->texy = cub->textures->texture_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	cub->wall->colour = cub->textures->east[cub->textures->texy
		* cub->textures->texture_width + cub->textures->texx];
}

void	ft_calc_tex_y_west(t_cub3D *cub, int y)
{
	cub->textures->texy = (int)((y - cub->wall->wallstart)
			* cub->textures->texture_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->texture_height)
		cub->textures->texy = cub->textures->texture_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	cub->wall->colour = cub->textures->west[cub->textures->texy
		* cub->textures->texture_width + cub->textures->texx];
}

void	ft_calc_tex_y_south(t_cub3D *cub, int y)
{
	cub->textures->texx = cub->textures->texture_width - cub->textures->texx - 1;
	cub->textures->texy = (int)((y - cub->wall->wallstart)
			* cub->textures->texture_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->texture_height)
		cub->textures->texy = cub->textures->texture_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	cub->wall->colour = cub->textures->south[cub->textures->texy
		* cub->textures->texture_width + cub->textures->texx];
}

void	ft_calc_tex_y_north(t_cub3D *cub, int y)
{
	int	time_interval;

	cub->textures->texy = (int)((y - cub->wall->wallstart)
			* cub->textures->texture_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->texture_height)
		cub->textures->texy = cub->textures->texture_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	gettimeofday(&cub->now, NULL);
	time_interval = (cub->now.tv_sec - cub->last_change.tv_sec);
	if (time_interval % 5 == 0)
	{
		cub->wall->colour = cub->textures->north[cub->textures->texy
			* cub->textures->texture_width + cub->textures->texx];
		cub->last_change = cub->now;
	}
	else
	{
		cub->wall->colour = cub->textures->north_odd[cub->textures->texy
			* cub->textures->texture_width + cub->textures->texx];
	}
}
