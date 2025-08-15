#include "cub3D.h"

void	ft_movement_hooks(t_cub3D *cub)
{
	if (cub->keypressed[119] == 1 || cub->keypressed[65362] == 1) // w or up arrow
	{
		cub->new_x = cub->player->pos_x + cub->dda->dirx * 0.1;
		cub->new_y = cub->player->pos_y + cub->dda->diry * 0.1;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			ft_mini_map_render(cub);
			ft_render_image(cub);
		}
	}
	else if (cub->keypressed[115] == 1 || cub->keypressed[65364] == 1) //s or down arrow
	{
		cub->new_x = cub->player->pos_x - cub->dda->dirx * 0.1;
		cub->new_y = cub->player->pos_y - cub->dda->diry * 0.1;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			ft_mini_map_render(cub);
			ft_render_image(cub);
		}
	}
}

void	ft_side_movement(t_cub3D *cub)
{
	if (cub->keypressed[100] == 1) // d
	{
		cub->new_x = cub->player->pos_x - cub->dda->diry * 0.1;
		cub->new_y = cub->player->pos_y + cub->dda->dirx * 0.1;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			ft_mini_map_render(cub);
			ft_render_image(cub);
		}
	}
	else if (cub->keypressed[97] == 1) // a
	{
		cub->new_x = cub->player->pos_x + cub->dda->diry * 0.1;
		cub->new_y = cub->player->pos_y - cub->dda->dirx * 0.1;
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
void	ft_orientation_change(t_cub3D *cub)
{
	if (cub->keypressed[65361] == 1) // right arrow
	{
		cub->player->angle += 5;
		if (cub->player->angle >= 360)
			cub->player->angle -= 360;
		ft_update_dda_vector(cub);
		ft_mini_map_render(cub);
		ft_render_image(cub);
	}
	else if (cub->keypressed[65363] == 1) // left arrow
	{
		cub->player->angle -= 5;
		if (cub->player->angle < 0)
			cub->player->angle += 360;
		ft_update_dda_vector(cub);
		ft_mini_map_render(cub);
		ft_render_image(cub);
	}
}

// // when changing orientation also update DDA struct !!
void	ft_orientation_change_mouse(int key, t_cub3D *cub)
{
	(void)cub;
	if (key == 65363) // mouse move right
	{
		cub->player->angle += 10;
		if (cub->player->angle >= 360)
			cub->player->angle -= 360;
		ft_update_dda_vector(cub);
		ft_mini_map_render(cub);
		ft_render_image(cub);
	}
	else if (key == 65361) // mouse move left
	{
		cub->player->angle -= 10;
		if (cub->player->angle < 0)
			cub->player->angle += 360;
		ft_update_dda_vector(cub);
		ft_mini_map_render(cub);
		ft_render_image(cub);
		printf("rotating to the left\n");
	}
}
