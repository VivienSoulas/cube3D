#include "cub3D.h"

void	ft_calc_tex_y_east(t_cub3D *cub, int y)
{
	int	wall_center;
	int	unclamped_wallstart;
	
	wall_center = cub->window_height / 2;
	unclamped_wallstart = wall_center - cub->wall->wallheight / 2;
	cub->textures->texx = cub->textures->texture_width - cub->textures->texx - 1;
	cub->textures->texy = (int)((y - unclamped_wallstart)
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
	int	wall_center;
	int	unclamped_wallstart;

	wall_center = cub->window_height / 2;
	unclamped_wallstart = wall_center - cub->wall->wallheight / 2;
	cub->textures->texy = (int)((y - unclamped_wallstart)
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
	int	wall_center;
	int	unclamped_wallstart;
	
	wall_center = cub->window_height / 2;
	unclamped_wallstart = wall_center - cub->wall->wallheight / 2;
	cub->textures->texx = cub->textures->texture_width - cub->textures->texx - 1;
	cub->textures->texy = (int)((y - unclamped_wallstart)
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
	int	wall_center;
	int	unclamped_wallstart;

	wall_center = cub->window_height / 2;
	unclamped_wallstart = wall_center - cub->wall->wallheight / 2;
	cub->textures->texy = (int)((y - unclamped_wallstart)
			* cub->textures->texture_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->texture_height)
		cub->textures->texy = cub->textures->texture_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	gettimeofday(&cub->now, NULL);
	time_interval = (cub->now.tv_usec / 100000);
	if (time_interval % 20 < 2)
	{
		cub->wall->colour = cub->textures->north_odd[cub->textures->texy
			* cub->textures->texture_width + cub->textures->texx];
	}
	else
	{
		cub->wall->colour = cub->textures->north[cub->textures->texy
			* cub->textures->texture_width + cub->textures->texx];
	}
}
