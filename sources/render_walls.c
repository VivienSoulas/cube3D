#include "cub3D.h"

void	ft_calc_tex_y_east(t_cub3D *cub, int y)
{
	cub->textures->texx = cub->textures->wall_width - cub->textures->texx - 1;
	cub->textures->texy = (int)((y - cub->wall->wallstart)
			* cub->textures->wall_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->wall_height)
		cub->textures->texy = cub->textures->wall_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	cub->wall->colour = cub->textures->east[cub->textures->texy
		* cub->textures->wall_width + cub->textures->texx];
}

void	ft_calc_tex_y_west(t_cub3D *cub, int y)
{
	cub->textures->texy = (int)((y - cub->wall->wallstart)
			* cub->textures->wall_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->wall_height)
		cub->textures->texy = cub->textures->wall_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	cub->wall->colour = cub->textures->west[cub->textures->texy
		* cub->textures->wall_width + cub->textures->texx];
}

void	ft_calc_tex_y_south(t_cub3D *cub, int y)
{
	cub->textures->texy = (int)((y - cub->wall->wallstart)
			* cub->textures->wall_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->wall_height)
		cub->textures->texy = cub->textures->wall_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	cub->wall->colour = cub->textures->south[cub->textures->texy
		* cub->textures->wall_width + cub->textures->texx];
}

void	ft_calc_tex_y_north(t_cub3D *cub, int y)
{
	cub->textures->texx = cub->textures->wall_width - cub->textures->texx - 1;
	cub->textures->texy = (int)((y - cub->wall->wallstart)
			* cub->textures->wall_height / cub->wall->wallheight);
	if (cub->textures->texy >= cub->textures->wall_height)
		cub->textures->texy = cub->textures->wall_height - 1;
	if (cub->textures->texy < 0)
		cub->textures->texy = 0;
	cub->wall->colour = cub->textures->north[cub->textures->texy
		* cub->textures->wall_width + cub->textures->texx];
}
