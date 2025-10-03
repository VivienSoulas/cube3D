#include "cub3D.h"

// w/up arrow and s/down arrow forward and backward
int	ft_movement_hooks(t_cub3D *cub)
{
	if (cub->keypressed[119] == 1
		|| cub->keypressed[65362] == 1)
	{
		cub->new_x = cub->player->pos_x + cub->dda->dirx * 0.07;
		cub->new_y = cub->player->pos_y + cub->dda->diry * 0.07;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			return (1);
		}
	}
	else if (cub->keypressed[115] == 1
		|| cub->keypressed[65364] == 1)
	{
		cub->new_x = cub->player->pos_x - cub->dda->dirx * 0.07;
		cub->new_y = cub->player->pos_y - cub->dda->diry * 0.07;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			return (1);
		}
	}
	return (0);
}

// a and d move left and right
int	ft_side_movement(t_cub3D *cub)
{
	if (cub->keypressed[100] == 1)
	{
		cub->new_x = cub->player->pos_x - cub->dda->diry * 0.07;
		cub->new_y = cub->player->pos_y + cub->dda->dirx * 0.07;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			return (1);
		}
	}
	else if (cub->keypressed[97] == 1)
	{
		cub->new_x = cub->player->pos_x + cub->dda->diry * 0.07;
		cub->new_y = cub->player->pos_y - cub->dda->dirx * 0.07;
		if (cub->map->grid[(int)cub->new_y][(int)cub->new_x] != '1')
		{
			cub->player->pos_x = cub->new_x;
			cub->player->pos_y = cub->new_y;
			return (1);
		}
	}
	return (0);
}

// right and left arrow
int	ft_orientation_change(t_cub3D *cub)
{
	if (cub->keypressed[65361] == 1)
	{
		cub->player->angle += 7;
		if (cub->player->angle >= 360)
			cub->player->angle -= 360;
		ft_update_dda_vector(cub);
		return (1);
	}
	else if (cub->keypressed[65363] == 1)
	{
		cub->player->angle -= 7;
		if (cub->player->angle < 0)
			cub->player->angle += 360;
		ft_update_dda_vector(cub);
		return (1);
	}
	return (0);
}

// mouse move right and left
void	ft_orientation_change_mouse(int key, t_cub3D *cub)
{
	if (key == 65363)
	{
		cub->player->angle += 5;
		if (cub->player->angle >= 360)
			cub->player->angle -= 360;
		ft_update_dda_vector(cub);
		ft_update(cub);
	}
	else if (key == 65361)
	{
		cub->player->angle -= 5;
		if (cub->player->angle < 0)
			cub->player->angle += 360;
		ft_update_dda_vector(cub);
		ft_update(cub);
	}
}
