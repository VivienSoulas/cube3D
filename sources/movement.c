#include "cub3D.h"

void	ft_movement_hooks(int key, t_cub3D *cub)
{
	if (key == 119 || key == 65362) // w or up arrow
	{
		cub->new_x = cub->player->pos_x + cub->dda->dirX * 0.3;
		cub->new_y = cub->player->pos_y + cub->dda->dirY * 0.3;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			ft_mini_map_render(cub);
			ft_render_image(cub);
		}
	}
	else if (key == 115 || key == 65364) //s or down arrow
	{
		cub->new_x = cub->player->pos_x - cub->dda->dirX * 0.3;
		cub->new_y = cub->player->pos_y - cub->dda->dirY * 0.3;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			ft_mini_map_render(cub);
			ft_render_image(cub);
		}
	}
}

void	ft_side_movement(int key, t_cub3D *cub)
{
	if (key == 100) // d
	{
		cub->new_x = cub->player->pos_x - cub->dda->dirY * 0.3;
		cub->new_y = cub->player->pos_y + cub->dda->dirX * 0.3;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			ft_mini_map_render(cub);
			ft_render_image(cub);
		}
	}
	else if (key == 97) // a
	{
		cub->new_x = cub->player->pos_x + cub->dda->dirY * 0.3;
		cub->new_y = cub->player->pos_y - cub->dda->dirX * 0.3;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			ft_mini_map_render(cub);
			ft_render_image(cub);
		}
	}
}


// when changing orientation also update DDA struct !!
void	ft_orientation_change(int key, t_cub3D *cub)
{
	(void)cub;
	if (key == 65361) // right arrow
	{
		cub->player->angle += 10;
		if (cub->player->angle >= 360)
			cub->player->angle -= 360;
		ft_update_dda_vector(cub);
		ft_mini_map_render(cub);
		ft_render_image(cub);
	}
	else if (key == 65363) // left arrow
	{
		cub->player->angle -= 10;
		if (cub->player->angle < 0)
			cub->player->angle += 360;
		ft_update_dda_vector(cub);
		ft_mini_map_render(cub);
		ft_render_image(cub);
	}
}

// // when changing orientation also update DDA struct !!
// void	ft_orientation_change_mouse(int key, t_cub3D *cub)
// {
// 	(void)cub;
// 	if (key == 65363) // mouse move right
// 	{
// 		cub->player->angle += 10;
// 		if (cub->player->angle >= 360)
// 			cub->player->angle -= 360;
// 		ft_update_dda_vector(cub);
// 		ft_mini_map_render(cub);
// 		ft_render_image(cub);
// 		printf("rotating to the right\n");
// 	}
// 	else if (key == 65361) // mouse move left
// 	{
// 		cub->player->angle -= 10;
// 		if (cub->player->angle < 0)
// 			cub->player->angle += 360;
// 		ft_update_dda_vector(cub);
// 		ft_mini_map_render(cub);
// 		ft_render_image(cub);
// 		printf("rotating to the left\n");
// 	}
// }
