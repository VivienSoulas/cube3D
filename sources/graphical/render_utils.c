#include "cub3D.h"

void	ft_calc_tex_x_east_west(t_cub3D *cub)
{
	cub->wall->wallx = cub->player->pos_y + cub->wall->wall_distance
		* cub->dda->raydiry;
	cub->wall->wallx = cub->wall->wallx - floor(cub->wall->wallx);
	cub->textures->texx = (int)(cub->wall->wallx * cub->textures->texture_width);
	if (cub->textures->texx >= cub->textures->texture_width)
		cub->textures->texx = cub->textures->texture_width - 1;
	if (cub->textures->texx < 0)
		cub->textures->texx = 0;
}

void	ft_calc_tex_x_north_south(t_cub3D *cub)
{
	cub->wall->wallx = cub->player->pos_x + cub->wall->wall_distance
		* cub->dda->raydirx;
	cub->wall->wallx = cub->wall->wallx - floor(cub->wall->wallx);
	cub->textures->texx = (int)(cub->wall->wallx * cub->textures->texture_width);
	if (cub->textures->texx >= cub->textures->texture_width)
		cub->textures->texx = cub->textures->texture_width - 1;
	if (cub->textures->texx < 0)
		cub->textures->texx = 0;
}
