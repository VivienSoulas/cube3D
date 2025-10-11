/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:45:17 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/03 09:45:18 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// w/up arrow and s/down arrow forward and backward
int	ft_movement_hooks(t_cub3d *cub)
{
	cub->mvt->new_x_ver = 0;
	cub->mvt->new_y_ver = 0;
	cub->mvt->new_x_hor = 0;
	cub->mvt->new_y_hor = 0;
	if (cub->keypressed[KEY_W] == 1
		|| cub->keypressed[KEY_UP] == 1)
	{
		cub->mvt->new_x_ver = cub->dda->dirx * 0.07;
		cub->mvt->new_y_ver = cub->dda->diry * 0.07;
	}
	else if (cub->keypressed[KEY_S] == 1
		|| cub->keypressed[KEY_DOWN] == 1)
	{
		cub->mvt->new_x_hor = -cub->dda->dirx * 0.07;
		cub->mvt->new_y_hor = -cub->dda->diry * 0.07;
	}
	ft_final_vector_mvt(cub);
	return (0);
}

// a and d move left and right
int	ft_side_movement(t_cub3d *cub)
{
	cub->mvt->new_x_ver = 0;
	cub->mvt->new_y_ver = 0;
	cub->mvt->new_x_hor = 0;
	cub->mvt->new_y_hor = 0;
	if (cub->keypressed[KEY_D] == 1)
	{
		cub->mvt->new_x_hor += -cub->dda->diry * 0.07;
		cub->mvt->new_y_hor += cub->dda->dirx * 0.07;
	}
	else if (cub->keypressed[KEY_A] == 1)
	{
		cub->mvt->new_x_hor += cub->dda->diry * 0.07;
		cub->mvt->new_y_hor += -cub->dda->dirx * 0.07;
	}
	ft_final_vector_mvt(cub);
	return (0);
}

// right and left arrow
int	ft_orientation_change(t_cub3d *cub)
{
	if (cub->keypressed[KEY_LEFT] == 1)
	{
		cub->player->angle += 7;
		if (cub->player->angle >= 360)
			cub->player->angle -= 360;
		ft_update_dda_vector(cub);
		return (1);
	}
	else if (cub->keypressed[KEY_RIGHT] == 1)
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
void	ft_orientation_change_mouse(int key, t_cub3d *cub)
{
	if (key == KEY_RIGHT)
	{
		cub->player->angle += 5;
		if (cub->player->angle >= 360)
			cub->player->angle -= 360;
		ft_update_dda_vector(cub);
		ft_update(cub);
	}
	else if (key == KEY_LEFT)
	{
		cub->player->angle -= 5;
		if (cub->player->angle < 0)
			cub->player->angle += 360;
		ft_update_dda_vector(cub);
		ft_update(cub);
	}
}

// adding all movement vector to check x and y independently
// moves only toward the availavle axis
void	ft_final_vector_mvt(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos_x + cub->mvt->new_x_hor + cub->mvt->new_x_ver;
	new_y = cub->player->pos_y + cub->mvt->new_y_hor + cub->mvt->new_y_ver;
	if (new_x < 0 || new_x >= cub->map->width
		|| new_y < 0 || new_y >= cub->map->height)
		return ;
	if (cub->map->grid[(int)cub->player->pos_y][(int)new_x] != '1')
		cub->player->pos_x = new_x;
	if (cub->map->grid[(int)new_y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y = new_y;
}
